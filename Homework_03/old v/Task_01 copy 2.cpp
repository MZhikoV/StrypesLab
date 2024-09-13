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
    typeS[lengthFunc]='\0';
    
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

    delete[] typeS;

    return result;
};

// //create a string of parameters
// char * paramNameStr (char * str, int count) {
//     int idx=0;
//     char * paramStr[count];
//     while (*str) {
//         if (*str != ',') {
//             paramStr[idx]=*str;
//             idx++;
//         };
//         str++;
//     };
// }

//return the params count
int countParam(char * str) {
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
};

//reading the input
void readInput() {
    std::cin.getline(inputLine,maxComLen);
};

//prints if there is an error in the input
void inputError() {
    std::cout<<"Input error!"<<std::endl;
};

//expression validation
bool expressValid(char *paramStr, char * expreStr) {

    for (int i=0; i<strlen(expreStr); i++) {
        if (isalpha(expreStr[i])) {
            if(!strchr(paramStr,expreStr[i])) {
                return false;
            };
        };
    };

    return true;
};

//defining structure that will contain the integrated circuit definition
struct integCircuit
{
    char name;
    funcType type;
    int paramCount=0;
    char paramStr[maxComLen];
    char expression[maxComLen];
    bool isValid=true;

    void setName(char* str) {
        this->name=*str;
    }; 

    void setType(funcType type) {
        this->type=type;
    };

    void setExpression(char* &str) {
        strcpy(this->expression, str);
    };

    void setParamStr(char* &str) {
        strcpy(this->paramStr, str);
    };

    void setValid(bool validation) {
        this->isValid=validation;
    };

    void printName() {
        std::cout<<name;
    };

    void printExpression() {
        std::cout<<expression;
    };

};

//define param struct
struct paramRun {
    char name;
    int value;

    void setName(char name) {
        this->name=name;
    };

    void setValue(int num) {
        this->value=num;
    };
};

//create struct
integCircuit parseInput (char *str, funcType typeS) {

    integCircuit resultStruct;

    resultStruct.setType(typeS);

    char* name = strtok(str, "(");      //taking the name of the function
    resultStruct.setName(name);          

    char* paramStr = strtok(nullptr, "): ");//taking the params of the function
    resultStruct.setParamStr(paramStr);
    resultStruct.paramCount=countParam(paramStr);

    char* expression = strtok(nullptr, " "); //removing the unnecessary symbols
    expression = strtok(nullptr, "\0"); //taking the expression of the function
    resultStruct.setExpression(expression);
    //defines the validation of the expression - if all parameters are included in the definition
    resultStruct.setValid(expressValid(resultStruct.paramStr, resultStruct.expression));

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
};



int main() {

int countDef=1; //counts the define commands;
integCircuit * arrIntCirc = new integCircuit[countDef];

for(;;) {
    readInput();

    if (!inputLine[0]) {    //check if we are getting empty line which will terminate the program execution
        break;
    };

    char * delimFuncName;
    funcType typeF=formType(delimFuncName);
    
    switch (typeF) {
        case funcType::define: {
            if (countDef!=1) {
                reallocateArr(arrIntCirc,countDef);
            };

            arrIntCirc[countDef-1]=parseInput(delimFuncName+1,typeF);
            
            if (arrIntCirc[countDef-1].isValid) {
                std::cout<<arrIntCirc[countDef-1].name<<" defined succesfully!"<<std::endl;
            } else {
                inputError();
            };

            countDef++; //increment the value if a next command occures
        };
        break;

        case funcType::run: {
            char* name = strtok(delimFuncName+1, "(");      //taking the name of the function
            
            integCircuit currIntCirc;
            bool isFound=false;
            for (int i=0; i<(countDef-1);i++) {
                if(arrIntCirc[i].name==*name) {
                    currIntCirc=arrIntCirc[i];
                    isFound=true;
                    break;
                };
            };

            if (!isFound) {
                std::cout<<"Error! Integrated circuit with name \""<<name<<"\" is not defined!"<<std::endl;
                break;
            };

            if (!currIntCirc.isValid) {
                std::cout<<"Error! Integrated circuit with name \""<<currIntCirc.name<<"\" is not correct!"<<std::endl;
                break;
            };

            paramRun * paramArr = new paramRun[currIntCirc.paramCount]; //create array for parameter struct

            char * paramNameStr=currIntCirc.paramStr;

            for (int i=0; i<currIntCirc.paramCount; i++) {
                char* currVal = strtok(nullptr, ",");
                paramArr[i].setValue(atoi(currVal));
                //std::cout<<currParam.value<<std::endl;
            };

            int idx=0;

            for (int i=0; i<strlen(currIntCirc.paramStr); i++) {
                if (currIntCirc.paramStr[i]!=',') {
                    paramArr[idx].setName(currIntCirc.paramStr[i]);
                    //std::cout<<paramArr[idx].name<<std::endl;
                    idx++;
                };
            };

            for (int i=0; i<currIntCirc.paramCount; i++) {
                std::cout<<paramArr[i].name<<" -> ";
                std::cout<<paramArr[i].value<<std::endl;
            };




            int a=0;

            delete[] paramArr;
        };
        break;




    };
    

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

    delete [] arrIntCirc;

    system("pause");
    return 0;
}




/*Sample input:
define i(a,b): &(a,b)
define j(a,b,c,d): &(a,|(b,c),!(d))
run j(1,1,0,0)
run i(1,0)
define k(a,b,c): |(a,&(b,c,!(d)))
run k(1,0,1)
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