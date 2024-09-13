// Homework 1 add ip type
// format: ip name 127.0.0.1
// Homework 2 move Data and Type into the parameter struct
// Move outside functions into the Parameter struct where it is appropriate

// input parameters
// input : ([params])
// params : type name(32) value
// supported types : char short int bool float double string(max 255)
// name : no checks & no spaces
// value : needs to match the type if it doesnt -> undefined behaviour
// example : 
// ()
// (int a 5,short c 9,string str safasfaf,bool b 1,double d 4.2)\0
// int a 5, short c 9, string str safasfaf
// int a 5
// short c 9
// string str sadasfaf

#pragma warning(disable: 4996)

#include <iostream>
#include <cstring>

// Data
// enum of the types
// union which includes all the supported types
// array of structs { type, data }

// Steps
// 1. getline whole thing
// 2. trim brackets
// 3. tokenize the input into separate parameters
// 4. parse the separate elements of a parameter
char input[2048];

enum class Type: int {
    Bool,
    Char,
    Short,
    Int,
    Float,
    Double,
    String,
    Undefined
};

const char* toString(Type type)
{
    switch (type) {
    case Type::Bool: return "bool";
    case Type::Char: return "char";
    case Type::Short: return "short";
    case Type::Int: return "int";
    case Type::Float: return "float";
    case Type::Double: return "double";
    case Type::String: return "string"; 
    }
    return "undefined";
}

Type formString(const char* str)
{
    if (!strcmp(str, "bool")) {
        return Type::Bool;
    }
    if (!strcmp(str, "char")) {
        return Type::Char;
    }
    if (!strcmp(str, "short")) {
        return Type::Short;
    }
    if (!strcmp(str, "int")) {
        return Type::Int;
    }
    if (!strcmp(str, "float")) {
        return Type::Float;
    }
    if (!strcmp(str, "double")) {
        return Type::Double;
    }
    if (!strcmp(str, "string")) {
        return Type::String;
    }

    return Type::Undefined;
}

union Data {
    bool b;
    char c;
    short s;
    int i;
    float f;
    double d;
    char *str;
};

struct Parameter {

    Data data;
    Type type;
    char name[32];

    void print() {
        std::cout << toString(type) << ' ' << name << ' ';
        printValue();
        std::cout << std::endl;
    }

    void printValue() {
        switch (type) {
        case Type::Bool: std::cout << data.b; break;
        case Type::Char: std::cout << data.c; break;
        case Type::Short: std::cout << data.s; break;
        case Type::Int: std::cout << data.i; break;
        case Type::Float: std::cout << data.f; break;
        case Type::Double: std::cout << data.d; break;
        case Type::String: std::cout << data.str; break;
        }
    }

    void setName(const char* name) {
        strcpy(this->name, name);
    }

    void setData(const char* data) {
        switch (type) {
        case Type::Bool: this->data.b = atoi(data); break;
        case Type::Char: this->data.c = atoi(data); break;
        case Type::Short: this->data.s = atoi(data); break;
        case Type::Int: this->data.i = atoi(data); break;
        case Type::Float: this->data.f = atof(data); break;
        case Type::Double: this->data.d = atof(data); break;
        case Type::String:
            this->data.str = new char[strlen(data) + 1] {'\0'};
            strcpy(this->data.str, data); break;
        }
    }
};

void readInput()
{
    std::cin.getline(input, 2048);
}

char* trimBraces()
{
    char* pos = strchr(input, ')');
    *pos = '\0';
    return input + 1;
}

int countParameters(const char* params)
{
    if (*params == '\0') return 0;

    int count = 0;
    while (*params) {
        if (*params == ',') ++count;
        params++;
    }

    return count + 1;
}

Parameter parseParameter(char* str) {
    Parameter result;

    char* type = strtok(str, " ");
    char* name = strtok(nullptr, " ");
    char* value = strtok(nullptr, " ");
    result.type = formString(type);
    result.setName(name);
    result.setData(value);

    return result;
}

void gatherParameters(Parameter* params, char *str, int count)
{
    char** tokens = new char* [count];
    int index = 0;
    char* current = strtok(str, ",");
    while (current) {
        tokens[index++] = current;
        current = strtok(nullptr, ",");
    }

    for (int i = 0; i < count; ++i) {
        params[i] = parseParameter(tokens[i]);
    }
}

void freeCStrings(Parameter* params, int count) {
    for (int i = 0; i < count; ++i) {
        if (params[i].type == Type::String) {
            delete[] params[i].data.str;
        }
    }
}

int main()
{
    readInput();

    char* paramsStr = trimBraces();
    int paramCount = countParameters(paramsStr);
    
    Parameter* params = new Parameter[paramCount];

    gatherParameters(params, paramsStr, paramCount);

    for (int i = 0; i < paramCount; ++i) {
        params[i].print();
    }

    freeCStrings(params, paramCount);

    delete[] params;
    return 0;
}
