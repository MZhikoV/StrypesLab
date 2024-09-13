#include <iostream>
#include <string.h>
#include <ctype.h>

/*Sample input:
define i(a,b): &(a,b)
define j(a,b,c,d): &(a,|(b,c),!(d))
run j(1,1,0,0)
run i(1,0)
define k(a,b,c): |(a,&(b,c,!(d)))
find 0,0,0:0;
*/

/*
ToDo:
*read input
*analyze input
*define function or error
    *trim command word until param declaration
    *create list of param's

*insert definition in array[] container with dynamic memory
*/
const int maxComLen=256; //define the maximum length of command

char inputLine[maxComLen];

//creating enum class for the function type
enum class funcType {
    define, run, all, find, undefined
};

//return string in lower cases
void toLowerCase(char * &inpS) {
    char * str=inpS;
    while (*str!='\0') {
        *str=tolower(*str);
        str++;
    };
};

//conversion from string to type
funcType formType (/*char * &str*/char * &delimFuncName) {

    delimFuncName = strchr(inputLine, ' ');
    size_t lengthFunc=(delimFuncName-inputLine);
    
    char *typeS=new char[lengthFunc+1];
    
    strncpy(typeS, inputLine, lengthFunc);
    typeS[lengthFunc+1]='\0';


    toLowerCase(typeS);
    
    funcType result;
    if (!strcmp(typeS, "define")) {
       result=funcType::define;
    } else if (!strcmp(typeS, "run")) {
        result=funcType::run;
    } else if (!strcmp(typeS, "all")) {
        result=funcType::all;
    } else if (!strcmp(typeS, "find")) {
        result=funcType::find;
    } else {
        result=funcType::undefined;
    };

    //delete typeS;

    return result;
};

//return the params count
int countParam(char * &str) {
    if (*str == '\0') {
        return 0;
    };

    int count = 0;
    while (*str) {
        if (*str == ',') {
            count++;
        };
        str++;
    };
    return count + 1;
}

//determining the type of the function


//reading the input
void readInput() {
    std::cin.getline(inputLine,maxComLen);
};


//prints if there is an error in the input
void inputError() {
    std::cout<<"Input error!"<<std::endl;
};

//defining structure that will contain the integrated circuit definition
struct integCircuit
{
    char name;
    funcType type;
    int paramCount=0;
    char expression[maxComLen];
    bool isValid=true;

    void setName(char* &str) {
        this->name=*str;
    }; 

    void setType(funcType type) {
        this->type=type;
    };

    void setExpression(char* &str) {
        strcpy(this->expression, str);
    }; 

    void printName() {
        std::cout<<name;
    };

    void printExpression() {
        std::cout<<expression;
    };

};

//create struct
integCircuit parseInput (char *str, funcType typeS) {

    integCircuit resultStruct;

    // char *expressionDelim=strchr(inputLine,':');

    // while (*expressionDelim) {
    //     expressionDelim++;

    //     if(!isalnum(*expressionDelim) && *expressionDelim!=' ') {
    //         break;
    //     };
    // };

    // char* typeS = strtok(str, " ");   //taking the type of the function
    resultStruct.setType(typeS);

    char* name = strtok(str, "(");      //taking the name of the function
    resultStruct.setName(name);          

    char* paramStr = strtok(nullptr, "): ");//taking the params of the function
    resultStruct.paramCount=countParam(paramStr);

    char* expression = strtok(nullptr, " "); //removing the unnecessary symbols
    expression = strtok(nullptr, "\0"); //taking the expression of the function
    resultStruct.setExpression(expression);
            
    return resultStruct;
};

//reallocating memory for the array
void reallocateArr(integCircuit * &arr,int count) {
    integCircuit * arrTemp=new integCircuit[count];
    //following the program logic, the size of the previous arr is count-1
    for (int i=0; i<(count-1);i++) {
        arrTemp[i]=arr[i];
    };
    delete[] arr;
    arr=arrTemp;
    // delete arrTemp;
};



int main() {

int countDef=1; //counts the define commands;
integCircuit * arrIntCirc = new integCircuit[countDef];

for(;;) {
    readInput();

    if (!inputLine[0]) {    //check if we are getting empty line which will terminate the program execution
        break;
    };

    // char * delimFuncName = strchr(inputLine, ' ');
    // size_t lengthFunc=(delimFuncName-inputLine);
    
    // char *typeS=new char[lengthFunc+1];
    
    // strncpy(typeS, inputLine, lengthFunc);
    // typeS[lengthFunc+1]='\0';

    // std::cout<<delimName+1<<std::endl;
    // std::cout<<(delimName-inputLine)<<std::endl;
    // std::cout<<(*delimName-*inputLine)<<std::endl;

    // char* typeS;
    //strncat(typeS, inputLine, (delimName-inputLine));
    char * delimFuncName;
    funcType typeF=formType(delimFuncName);
    
    switch (typeF) {
        case funcType::define: {
            if (countDef!=1) {
                reallocateArr(arrIntCirc,countDef);
            };

            arrIntCirc[countDef-1]=parseInput(delimFuncName+1,typeF);
            
            std::cout<<arrIntCirc[countDef-1].name<<" defined succesfully!"<<std::endl;

            countDef++; //increment the value if a next command occures

            break;
        };
    }
    

    // char* typeS = strtok(inputLine, " ");   //taking the type of the function
    // std::cout<<typeS<<std::endl;
    // std::cout<<inputLine<<std::endl;

    // char* name = strtok(delimName+1, "(");      //taking the name of the function
    // std::cout<<name<<std::endl;         

    // char* paramStr = strtok(nullptr, ")");//taking the params of the function
    // std::cout<<paramStr<<std::endl;

    // char* expression = strtok(nullptr, " "); //removing the unnecessary symbols
    // expression = strtok(nullptr, "\0"); //taking the expression of the function
    // std::cout<<expression<<std::endl;

    // system("pause");
    // return 0;

    // //check is needed to determine if the command is valid
    // if (isalpha(inputLine[0])) {
    //     switch (tolower(inputLine[0]))
    //     {
    //     case 'd': {
    //         if (countDef!=1) {
    //             reallocateArr(arrIntCirc,countDef);
    //         };

    //         arrIntCirc[countDef-1]=parseInput(inputLine);
            
    //         std::cout<<arrIntCirc[countDef-1].name<<" defined succesfully!"<<std::endl;

    //         countDef++; //increment the value if a next command occures

    //         break;
    //     };
    //     case 'r':
    //         std::cout<<"run"<<std::endl;
    //         break;
    //     case 'a':
    //         std::cout<<"run"<<std::endl;
    //         break;
    //     case 'f':
    //         std::cout<<"find"<<std::endl;
    //         break;
        
    //     default:
    //         inputError();
    //         break;
    //     }
    // } else {
    //     inputError();
    //     continue;
    // };
};

for (int i=0; i<(countDef-1);i++) {
    arrIntCirc[i].printName();
    std::cout<<" with expression: ";
    arrIntCirc[i].printExpression();
    std::cout<<std::endl;
};

    system("pause");
    return 0;
}




/*Sample input:
define i(a,b): &(a,b)
define j(a,b,c,d): &(a,|(b,c),!(d))
run j(1,1,0,0)
run i(1,0)
define k(a,b,c): |(a,&(b,c,!(d)))
find 0,0,0:0;


define i(a,b): &(a,b)
define j(a,b,c,d): &(a,|(b,c),!(d))
define k(a,b,c): |(a,&(b,c,!(d)))
DEFINE l(a,b,c): &(a,b,!(c))
deFIne m(a): |(a,&(b,c,!(d)))

*/



/*
            char test[6]={'H','E','L','L','O','\0'};
            char * testPtr=test;
            std::cout<<testPtr<<std::endl;
            toLowerCase(testPtr);
            std::cout<<testPtr<<std::endl;
*/