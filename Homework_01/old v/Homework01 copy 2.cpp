#include <iostream>
#include <string>
#include <cctype>
#include <bitset>
#include <iomanip>
#include <cstdint>

const int signLen=1;
const int positionLen=5;
const int significantPosLen=26;
const int maxElem=1000000;
const int maxRatNum=10;

//check if the string has non-digit values
bool isNum(const std::string &inp, const int startIdx); 

//check if the numerator and denomerators are correctly inserted
bool isCorrectInp(const std::string &strNom, const std::string &strDenom );

//function for dividing the input in two strings
void divideString(const std::string & inp, std::string &strNom, std::string &strDenom);

//function for reading input as a string with getline
std::string readInput ();

//from task
// Връща най-голямото общо кратно на две неотрицателни числа
int gcd(int a, int b);

//from task
// Връща броят битове, необходим за представянето на дадено положително число
int numBits(int n);

//function for representing rational numbers

//returns the nom of the rational number
int getNumer(unsigned rat);

//returns the denom of the rational number
int getDenom(unsigned rat);

//returns the addition of two rational numbers
unsigned ratAdd(unsigned r1, unsigned r2);

//returns the subtraction of two rational numbers
unsigned ratSub(unsigned r1, unsigned r2);

//returns the multiplication of two rational numbers
unsigned ratMul(unsigned r1, unsigned r2);

//returns the division of two rational numbers
unsigned ratDiv(unsigned r1, unsigned r2);

//returns the reciprocal of a given rational number
unsigned ratRec(unsigned rat);

// returns the absolute value of a given rational number
unsigned ratAbs(unsigned rat);

//returns the opposite of a rational number
unsigned ratNeg(unsigned rat);

// returns rational number as a float
float rat2float(unsigned rat);

unsigned makeRat(int n, int d);

//function for representing rational numbers with implicit denom lead bit
unsigned makeRatImp(int n, int d);

//returns the denom of the rational number with implicit denom lead bit
int getDenomImp(unsigned rat);

//compare the sums of fp32 and floatbar representation
void compareSums(unsigned rats[maxElem]);

//print error message
void errorMsg();

//print error message for operations
void errorMsg(std::string operation);

//print result message for operations
void resultMsg(std::string operation, unsigned ratNum, int countNum);

//print result message for nom and denom
void resultMsg(unsigned ratNum);

//print result message for nom and denom of the rational number with implicit denom lead bit
void resultMsgImp(unsigned ratNum);




int main() {



//bool isFirstRow=true;
/* Due to requirements, UI entry code is not required
//reading input for two numbers
std::cout<<"Enter two rational numbers:"<<std::endl;
*/

//creating string array for the two test numbers
std::string arrNumInp[]={"1/3", "9/8", "-3/2", "0", "1", "-10", "1/4000000"};

int sizeArr=sizeof(arrNumInp)/sizeof(arrNumInp[0]);


unsigned ratNumArr[maxRatNum]={};
//unsigned ratNumInpArr[2]={};


for (int i=0; i<sizeArr;i++) {
    // if (!isFirstRow) {
    //     std::cout<<std::endl;
    // };

    // std::string entryOrder;

    // if (i==0) {
    //     entryOrder="first";
    // } else {
    //     entryOrder="second";
    // };

    // std::cout<<"Enter "<<entryOrder<<" number:"<<std::endl;
    // std::string inp;
    // inp=readInput();

    std::string strNom,strDenom;
    divideString(inp, strNom, strDenom);

    if(!isCorrectInp(strNom, strDenom)) {
            errorMsg();
            system("pause");
            return 0;
    };

    int nomInp, denomInp;
    
    long long tempNom=stoll(strNom);
    long long tempDenom=stoll(strDenom);
    
    if (tempNom>INT32_MAX || tempDenom>INT32_MAX) {
        errorMsg();
        system("Pause");
        return 0;
    };

    nomInp=tempNom;
    denomInp=tempDenom;

    //check if the denominator is equal to '0'
    if (denomInp==0) {
        errorMsg();
        system("Pause");
        return 0;
    };

    unsigned ratNumber=makeRat(nomInp,denomInp);
    
    if(!ratNumber) {
        errorMsg();
        return 0; 
    };

    std::cout<<"The number "<<nomInp<<"/"<<denomInp<<" equals to: "<<ratNumber<<" which is in binary: "<<std::bitset<32>(ratNumber)<<std::endl;

    resultMsg(ratNumber);


    //representing rational numbers with implicit denom lead bit
    unsigned ratNumbImp=makeRatImp(nomInp,denomInp);
    
    if(!ratNumber) {
        errorMsg();
        return 0; 
    };

    std::cout<<"The number "<<nomInp<<"/"<<denomInp<<" represented with implicit denominator leading bit equals to: "
    <<ratNumbImp<<" which is in binary: "<<std::bitset<32>(ratNumbImp)<<std::endl;

    resultMsgImp(ratNumbImp);

    //operation reciprocal
    std::cout<<std::endl;
    unsigned ratRecNum=ratRec(ratNumber);

    std::string operation="reciprocal";

    if (!ratRecNum) {
        errorMsg(operation);
    }
    else {
        resultMsg(operation, ratRecNum,1);
        resultMsg(ratRecNum);
    };

    //operation return opposite
    std::cout<<std::endl;
    unsigned ratNegNum=ratNeg(ratNumber);

    operation="opposite";

    resultMsg(operation, ratNegNum,1);
    resultMsg(ratNegNum);

    //operation absolute value
    std::cout<<std::endl;
    unsigned ratAbsNum=ratAbs(ratNumber);

    operation="absolute value";

    resultMsg(operation, ratAbsNum,1);
    resultMsg(ratAbsNum);

    //operation rat to float
    std::cout<<std::endl;
    float floatNum=rat2float(ratNumber);

    std::cout<<"The float representation of the rational number is :"<<floatNum<<std::endl;


    ratNumArr[i]=ratNumber; //assigning value to the corresponding array element

    isFirstRow=false;
};
    std::string operation;

    std::cout<<std::endl<<std::endl<<"Basic arithmethic operations: "<<std::endl;

    //operation addition
    std::cout<<std::endl;
    unsigned ratAddNum=ratAdd(ratNumArr[0], ratNumArr[1]);

    operation="addition";

    if (!ratAddNum) {
        errorMsg(operation);
    }
    else {
        resultMsg(operation, ratAddNum,2);
        resultMsg(ratAddNum);
    };

    //operation subtraction
    std::cout<<std::endl;
    unsigned ratSubNum=ratSub(ratNumArr[0], ratNumArr[1]);

    operation="subtraction";

    if (!ratSubNum) {
        errorMsg(operation);
    }
    else {
        resultMsg(operation, ratSubNum,2);
        resultMsg(ratSubNum);
    };

    //operation multiplication
    std::cout<<std::endl;
    unsigned ratMulNum=ratMul(ratNumArr[0], ratNumArr[1]);

    operation="multiplication";

    if (!ratMulNum) {
        errorMsg(operation);
    }
    else {
        resultMsg(operation, ratMulNum,2);
        resultMsg(ratMulNum);
    };

    //operation division
    std::cout<<std::endl;
    unsigned ratDivNum=ratDiv(ratNumArr[0], ratNumArr[1]);

    operation="division";

    if (!ratDivNum) {
        errorMsg(operation);
    }
    else {
        resultMsg(operation, ratDivNum,2);
        resultMsg(ratDivNum);
    };


//reading input for comparing sums
std::cout<<"Enter up to 1 000 000 rational numbers. Enter \"E\" to end input:"<<std::endl;

//unsigned ratNumArr[maxElem]={};

int inpIdx=0;       //counts the input elements

unsigned *ratNumArrComp=(unsigned *)malloc(maxElem*sizeof(unsigned));
if(ratNumArrComp==NULL) {
    std::cout<<"Error allocating memory!"<<std::endl;
    return 0;
};

for (int idx=0; idx<maxElem;idx++) {
    
    std::string inp;
    inp=readInput();

    if (inp=="E" || inp=="e") {
        break;
    }

    std::string strNom,strDenom;
    divideString(inp, strNom, strDenom);

    if(!isCorrectInp(strNom, strDenom)) {
            errorMsg();
            system("pause");
            return 0;
    };

    int nomInp, denomInp;

    long long tempNom=stoll(strNom);
    long long tempDenom=stoll(strDenom);
    
    if (tempNom>INT32_MAX || tempDenom>INT32_MAX) {
        errorMsg();
        system("Pause");
        return 0;
    };

    nomInp=tempNom;
    denomInp=tempDenom;

    //check if the denominator is equal to '0'
    if (denomInp==0) {
        errorMsg();
        system("Pause");
        return 0;
    };

    unsigned ratNumber=makeRat(nomInp,denomInp);
    
    if(!ratNumber) {
        errorMsg();
        return 0; 
    };

    
    ratNumArrComp[idx]=ratNumber;
};

    compareSums(ratNumArrComp);

    //free(ratNumArrComp);


    system("pause");
    return 0;
}


//-----------------------------------------------------------
//function definitions

//check if the string has non-digit values
bool isNum(const std::string &inp, const int startIdx) {
    for (int i=startIdx; i<inp.size(); i++) {
        if (!isdigit(inp[i])) {
            return false;
        };
    };
    return true;
};

//check if the numerator and denomerators are correctly inserted
bool isCorrectInp(const std::string &strNom, const std::string &strDenom ) {
    //check if the first position of nomerator is '+', '-' or a digit
    if (strNom[0]!='+' && strNom[0]!='-' && !isdigit(strNom[0])) {
        return false;
    };
    //check if the rest of the nomerator contains only digits
    if (strNom.size()>=1) {
        if(!isNum(strNom, 1)) {
            return false;
        };
    };

    //check if the denomerator contains only digits and is positive
    if(!isNum(strDenom, 0)) {
        return false;
    };

    return true;
};

//function for dividing the input in two strings
void divideString(const std::string & inp, std::string &strNom, std::string &strDenom) {

    int foundIdx=inp.find("/");

    //check if the separator '/' exists in the string, if no, we have denom=1
    if (foundIdx==std::string::npos) {
        strNom=inp;
        strDenom='1';
    }
    else {
        strNom=inp.substr(0,foundIdx);
        strDenom=inp.substr(foundIdx+1,inp.size());
    };
};

//function for reading input as a string with getline
std::string readInput () {
    std::string input;
    std::getline(std::cin,input);
    return input;
};

//from task
// Връща най-голямото общо кратно на две неотрицателни числа
int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    } else if (b != 0) {
        return gcd(b, a % b);
    } else {
        return a;
    }
};

//from task
// Връща броят битове, необходим за представянето на дадено положително число
int numBits(int n) {
    int res = 0;
    while (n != 0) {
        n >>= 1; ++res;
    }
    return res;
};

//function for representing rational numbers
//-------------------------------------------------------------------------------------------------------------------------
//Advantage: More precise representation of numbers that can't be represented precisely with standart types (float, double)
//for example: 1/3, 1/7 etc.
//Disadvantage: Limitation to the size of the nominator and denominator. 
//for example, a rational number, represented binary with more than 26 digits
//-------------------------------------------------------------------------------------------------------------------------
unsigned makeRat(int n, int d) {
    
    int sign = (n < 0) ? 1 : 0;
    n = abs(n);

    int divider = gcd(n, d);
    n /= divider;
    d /= divider;

    int b = numBits(d); //calculating the positions required for denom
    int posNom=numBits(n); //calculating the positions required for nom

    //check if the n+d are greater than 26 bits
    if ((b+posNom) > significantPosLen) {
        return 0;
    };

    unsigned rat = (sign << (significantPosLen+positionLen)) | (b << significantPosLen) | (n << b) | d;
    return rat;
};

//returns the nom of the rational number
int getNumer(unsigned rat) {
    int sign=(rat>>(significantPosLen+positionLen));

    int b;
    b=((rat<<signLen)>>(significantPosLen+signLen));

    int nom=((rat<<(signLen+positionLen))>>(b+(signLen+positionLen)));
    nom*=sign? -1 : 1;

    return nom;
};

//returns the denom of the rational number
int getDenom(unsigned rat) {
    int b;
    b=((rat<<signLen)>>(significantPosLen+signLen));

    int denom=((rat<<(signLen+positionLen+significantPosLen-b))>>(signLen+positionLen+significantPosLen-b));

    return denom;
};

//returns the addition of two rational numbers
unsigned ratAdd(unsigned r1, unsigned r2) {
    int nom1=getNumer(r1);
    int deNom1=getDenom(r1);

    int nom2=getNumer(r2);
    int deNom2=getDenom(r2);

    int nomResult=(nom1*deNom2)+(nom2*deNom1);
    int deNomResult=deNom1*deNom2;

    return makeRat(nomResult,deNomResult);
};

//returns the subtraction of two rational numbers
unsigned ratSub(unsigned r1, unsigned r2) {
    int nom1=getNumer(r1);
    int deNom1=getDenom(r1);

    int nom2=getNumer(r2);
    int deNom2=getDenom(r2);

    int nomResult=(nom1*deNom2)-(nom2*deNom1);
    int deNomResult=deNom1*deNom2;

    return makeRat(nomResult,deNomResult);
};

//returns the multiplication of two rational numbers
unsigned ratMul(unsigned r1, unsigned r2) {
    int nom1=getNumer(r1);
    int deNom1=getDenom(r1);

    int nom2=getNumer(r2);
    int deNom2=getDenom(r2);

    int nomResult=nom1*nom2;
    int deNomResult=deNom1*deNom2;

    return makeRat(nomResult,deNomResult);
};

//returns the division of two rational numbers
unsigned ratDiv(unsigned r1, unsigned r2) {
    int nom1=getNumer(r1);
    int deNom1=getDenom(r1);

    int nom2=getNumer(r2);
    int deNom2=getDenom(r2);

    if(nom2==0) {
        return 0;
    }

    int r2Sign= (nom2<0)? -1 : 1;       //check if the sign of the r2 is negative

    int nomResult=nom1*deNom2*r2Sign;   //assign the sign to the nom
    int deNomResult=deNom1*abs(nom2);   //denom is always positive

    return makeRat(nomResult,deNomResult);
};

//returns the reciprocal of a given number
unsigned ratRec(unsigned rat) {
    int nom=getNumer(rat);
    int deNom=getDenom(rat);

    if (nom==0) {
        return 0;
    };

    int ratSign= (nom<0)? -1 : 1;       //check if the sign of the rat is negative

    int nomResult=ratSign*deNom;        //assign the sign to the nom
    int deNomResult=abs(nom);           //denom is always positive

    return makeRat(nomResult,deNomResult);
};

//returns the opposite of a rational number
unsigned ratNeg(unsigned rat) {

    int ratSign= -1;                        //always returns the opposite sign

    int nomResult=ratSign*getNumer(rat);    //assign the sign to the nom
    int deNomResult=getDenom(rat);          //denom is always positive

    return makeRat(nomResult,deNomResult);
};

// returns the absolute value of a given rational number
unsigned ratAbs(unsigned rat) {
    int nomResult=abs(getNumer(rat));       //results as an absolute value of the nom
    int deNomResult=getDenom(rat);          //denom is always positive

    return makeRat(nomResult,deNomResult);
};

// returns rational number as a float
float rat2float(unsigned rat) {
    int nomResult=getNumer(rat);       //results as an absolute value of the nom
    int deNomResult=getDenom(rat);          //denom is always positive

    return static_cast<float>(nomResult)/deNomResult;
};

//function for representing rational numbers with implicit denom lead bit
//-------------------------------------------------------------------------------------------------------------------------
//Advantage: Bigger range (x2) for the rational number, represented binary with 27 digits
//Disadvantage: More complex solution and a specific behaviour when the denom is equal to '1'(is missing)
//-------------------------------------------------------------------------------------------------------------------------

unsigned makeRatImp(int n, int d) {
    
    int sign = (n < 0) ? 1 : 0;
    n = abs(n);

    int divider = gcd(n, d);
    n /= divider;
    d /= divider;

    int b = numBits(d); //calculating the positions required for denom
    int posNom=numBits(n); //calculating the positions required for nom

    //check if the n+d are greater than 26 bits
    if ((b+posNom) > significantPosLen) {
        return 0;
    };

    unsigned rat = (sign << (significantPosLen+positionLen)) | ((b-1) << significantPosLen) | (d^(1>>(b-1))) | (n << (b-1));
    return rat;
};

//returns the denom of the rational number with implicit denom lead bit
int getDenomImp(unsigned rat) {
    int b;
    b=((rat<<signLen)>>(significantPosLen+signLen));
    if (b==0) {     //the right operand when shifting must be less than the number of bits in left operand otherwise undef.beh.  
        return 1;
    };
    
    int denom=((rat<<(signLen+positionLen+significantPosLen-b))>>(signLen+positionLen+significantPosLen-b)) | (1<<(b));

    return denom;
};

//compare the sums of fp32 and floatbar representation
void compareSums(unsigned rats[maxElem]) {
    //int arrSize=sizeof(rats)/sizeof(rats[0]);
    
    int currNom=0, currDeNom=1;
    float currSumFloat=0;

    for(int i=0; i<maxElem; i++) {

        //sum of floating bar elements
        int nom2=getNumer(rats[i]);
        int deNom2=getDenom(rats[i]);

        if (nom2!=0) {
        currNom=(currNom*deNom2)+(nom2*currDeNom);
        currDeNom*=deNom2;

        int divider = gcd(currNom, currDeNom);
        
        currNom /= divider;
        currDeNom /= divider;


        //sum of float elements
        currSumFloat+=rat2float(rats[i]);
        };
    };

    
    

    unsigned totalSumFB=makeRat(currNom,currDeNom);

    if(!totalSumFB) {
        errorMsg();
    } else {
    std::cout<<"The total sum of Floating bar elements "<<totalSumFB
    << "represented in binary is: "<<std::bitset<32>(totalSumFB)<<std::endl;

    resultMsg(totalSumFB);

    std::cout<<"The total sum of float elements is: "<<currSumFloat<<std::endl;

    double deltaErr=abs((currSumFloat-rat2float(totalSumFB))/currSumFloat)*100;
    std::cout<<"The calculation error from different type of representation is ";
    std::cout<<std::fixed<<std::setprecision(26)<<deltaErr<<"%"<<std::endl;

    free(rats);
    };
};

//----------------------------------------------------------------------------------
//error messages

//print error message
void errorMsg() {
    std::cout<<"Incorrect input!"<<std::endl;
};

//print error message for operations
void errorMsg(std::string operation) {
    std::cout<<"The operation "<<operation<<" can't be executed!"<<std::endl;
};

//print result message for operations
void resultMsg(std::string operation, unsigned ratNum, int countNum) {
    std::string countWord="number";
    if (countNum>1) {
        countWord="numbers";
    };

    std::cout<<"The "<<operation<<" of the "<<countWord<<" is :"<<ratNum
    <<" which is in binary: "<<std::bitset<32>(ratNum)<<std::endl;
};

//print result message for nom and denom
void resultMsg(unsigned ratNum) {
    int nom=getNumer(ratNum);
    std::cout<<"The Nominator is: "<<nom<<std::endl;
    int deNom=getDenom(ratNum);
    std::cout<<"The Denominator is: "<<deNom<<std::endl;
};

//print result message for nom and denom of the rational number with implicit denom lead bit
void resultMsgImp(unsigned ratNum) {
    int nom=getNumer(ratNum);
    std::cout<<"The Nominator is: "<<nom<<std::endl;
    int deNom=getDenomImp(ratNum);
    std::cout<<"The Denominator is: "<<deNom<<std::endl;
};








/*
Floating bar

1/3: 0 00010 000000000000000000000001 11
9/8: 0 00100 0000000000000000001001 1000
-3/2: 1 00010 000000000000000000000011 10
0: 0 00001 0000000000000000000000000 1
1: 0 00001 0000000000000000000000001 1
-10: 1 00001 0000000000000000000001010 1
1/4000000: 0 10110 0001 1111010000100100000000

Уточнения:

\/  числителят е винаги неотрицателен, а знаменателя строго положителен;
\/  числителят и знаменателят винаги са взаимнопрости числа. Например 4/6 не се счита за валидна дроб, ами се опростява до 2/3 и това се кодира;
\/  целите числа считаме за рационални със знаменател 1;
\/  не разглеждаме числа, чиито опростени числител и знаменател не се побират в общо 26 бита.


Задачите:
Напишете следните функции, които работят с floating bar числа:
\/  // Опростява и кодира дробта n/d в 32-битово цяло число
    unsigned makeRat(int n, int d);

\/  // Връща числителя на дадено рационално число, със знака на числото (т.е. отрицателно число за отрицателни дроби)
    int getNumer(unsigned rat);

\/  // Връща знаменателя на дадено рационално число, винаги положителен
    int getDenom(unsigned rat);

\/  // Изчисляват _точно_ и кодират съответно сумата/разликата/произведението/частното на дадени две рационални числа.
    // Това означава, че използване на float и double в междинните изчисления е забранено (!)
    unsigned ratAdd(unsigned r1, unsigned r2);
    unsigned ratSub(unsigned r1, unsigned r2);
    unsigned ratMul(unsigned r1, unsigned r2);
    unsigned ratDiv(unsigned r1, unsigned r2);

\/    // Връща реципрочното на дадено рационално число
    unsigned ratRec(unsigned rat);


\/    // Връща противоположното на дадено рационално число
    unsigned ratNeg(unsigned rat);


\/  // Връща абсолютната стойност на дадено рационално число
    unsigned ratAbs(unsigned rat);

\/  // Превръща рационално число в стандартно дробно число
    float rat2float(unsigned rat);

\/    Напишете в кратък коментар в кода по едно предимство/недостатък на това представяне.
    Дайте пример за число, което можем да представим точно по този начин, но не като стандартен float.
    Дайте пример и за обратното.


Бонус - имплицитен водещ бит на знаменателя
Аналогично на стандартния формат за дробни числа, тук знаем, че знаменателят е ненулево число с водещ бит единица. 
Тогава числото B може да съдържа броят останали битове от представянето му, и само те да участват в кодирането:
    1/3 ->  0 00001 0000000000000000000000001 1
//  1/3:    0 00010 000000000000000000000001 11


    9/8 ->  0 00011 00000000000000000001001 000
//  9/8:    0 00100 0000000000000000001001 1000


42 -> 0 00000 00000000000000000000101010 (!)

unsigned makeRat2(int n, int d) {
    
    int sign = (n < 0) ? 1 : 0;
    n = abs(n);

    int divider = gcd(n, d);
    n /= divider;
    d /= divider;

    int b = numBits(d); //calculating the positions required for denom
    int posNom=numBits(n); //calculating the positions required for nom

    //check if the n+d are greater than 26 bits
    if ((b+posNom) > significantPosLen) {
        return 0;
    };

    unsigned rat = (sign << (significantPosLen+positionLen)) | (b << significantPosLen) | (d^(1>>(b-1))) | (n << (b-1);
    return rat;
};



Променете вашите функции така, че да работят с този усложнен формат. Напишете по едно предимство/недостатък на това усложнение.

Бонус - сравнение със fp32

Различните представяния на реални числа имат различни предимства и недостатъци.
Напишете кратка функция която да сравни грешката
при събиране на голямо количество реални числа представени по два различни начина (fp32 и floating bar)

// Изчислява сумата на даден масив от рационални числа по два начина: точно и след превръщането им във float.
// Отпечатайте двата резултата и ги сравнете - в кои случаи единият е верен и в кои случаи другият?
void compareSums(unsigned rats[1000000]);

Предаване на кода

За да може да проверим вашите работи, трябва да спазите следните правила:

Може да се качи само един файл (архив от позволените формати) който да съдържа всичките нужни файлове. Има лимит на размера на архива - целта е да не добавяте временните файлове от компилация.
Освен изходният код трябва да качите и проектен файл който описва как се компилира вашият код. Това е проектен файл от средата за разработка която ползвате или файл който може да бъде изпълнен от терминал и ще компилира изцяло вашият код.
Някъде в предадените файлове трябва да упоменете спецификите на системата която използвате за да компилирате кода си (операционна система, компилатор, версия, среда за разработка и версия ако има такава)
*/
