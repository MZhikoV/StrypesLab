#include <iostream>
#include <string>
#include <cctype>
#include <bitset> //to read more about it

//check if the input is correct
// //check if the separator '/' is presented more than once
// bool isCorrectInp(const std::string & inp ) {
//     int foundIdx=inp.find("/");
//     int cntr=0;
//     while (foundIdx!=std::string::npos) {
//         foundIdx=inp.find("/",foundIdx+1);
//         if (foundIdx!=std::string::npos) {
//             cntr++;
//         };
//     };

//     if (cntr) {
//         return false;
//     };

//     return true;
// }

const int signLen=1;
const int positionLen=5;
const int significantPosLen=26;

//check if the string has non-digit values \/
bool isNum(const std::string &inp, const int startIdx) {
    for (int i=startIdx; i<inp.size(); i++) {
        if (!isdigit(inp[i])) {
            return false;
        };
    };
    return true;
}

//check if the numerator and denomerators are correctly inserted \/
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
}

//print error message \/
void errorMsg() {
    std::cout<<"Incorrect input!"<<std::endl;
};

//function for dividing the input in two strings \/
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
}

//function for reading input as a string with getline \/
std::string readInput () {
    std::string input;
    std::getline(std::cin,input);
    return input;
}

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
}

//from task
// Връща броят битове, необходим за представянето на дадено положително число
int numBits(int n) {
    int res = 0;
    while (n != 0) {
        n >>= 1; ++res;
    }
    return res;
}



//function for representing rational numbers
//-------------------------------------------------------------
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
}

/*
sign=1
sign<<31

1000 0000 0000 0000 0000 0000 0000 0000

b=2->10 
b << 26
0000 1000 0000 0000 0000 0000 0000 0000

n=3-> 11
n << b
0000 0000 0000 0000 0000 0000 0000 1100

d=2 -> 10
d
0000 0000 0000 0000 0000 0000 0000 0010

(sign << 31) | (b << 26)
1000 0000 0000 0000 0000 0000 0000 0000
0000 1000 0000 0000 0000 0000 0000 0000
---------------------------------------
1000 1000 0000 0000 0000 0000 0000 0000
 | (n << b) 
0000 0000 0000 0000 0000 0000 0000 1100
---------------------------------------
1000 1000 0000 0000 0000 0000 0000 1100
|d
0000 0000 0000 0000 0000 0000 0000 0010
---------------------------------------
1000 1000 0000 0000 0000 0000 0000 1110


*/

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




//-------------------------------------------------------------



// //function for reading input
// void readNumber(unsigned &nom, unsigned &denom, bool &flagInp) {

//     std::string input,strDenom,strNom;
//     std::getline(std::cin,input);



//     int foundIdx=input.find("/");

//     //check if the separator '/' exists in the string, if no, we have denom=1
//     if (foundIdx==std::string::npos) {
//         strNom=input;
//         strDenom=1;
//     }
//     else {
//         strNom=input.substr(0,foundIdx);
//         strDenom=input.substr(foundIdx+1,input.size());

//         //check if the data is correctly entered - if secondary '/' appears the program will terminate
//         foundIdx=input.find("/", foundIdx+1);
//             if (foundIdx!=std::string::npos) {
//                 std::cout<<"Incorrect input!"<<std::endl;
//                 flagInp=false;
//                 nom=denom=0;
//             };
//     }
// }

int main() {



//reading input for two numbers!!!
//for (int i=0; i<2;i++) {                      !!! make it available for reading two numbers
    std::string inp;
    inp=readInput();

std::string strNom,strDenom;
divideString(inp, strNom, strDenom);

if(!isCorrectInp(strNom, strDenom)) {
        errorMsg();
        system("pause");
        return 0;
};

int nomInp, denomInp;

nomInp=stoi(strNom);
denomInp=stoi(strDenom);

//check if the denominator is equal to '0'
if (denomInp==0) {
    errorMsg();
    system("Pause");
    return 0;
};

unsigned number=makeRat(nomInp,denomInp);
if(!number) {
   errorMsg(); 
};
std::cout<<"The number "<<nomInp<<"/"<<denomInp<<" equals to: "<<number<<" which is in binary: "<<std::bitset<32>(number)<<std::endl;

int nom=getNumer(number);
std::cout<<"The Nominator is: "<<nom<<std::endl;

int deNom=getDenom(number);
std::cout<<"The Denominator is: "<<deNom<<std::endl;


//unsigned trstNum1,trstNum2, test3=number;
// sign=nom=number;

// int sgn=(number>>31);
// int b;
// trstNum1=(number<<1);
// std::cout<<"number<<1 "<<std::bitset<32>(trstNum1)<<std::endl;

// //trstNum1<<=1;

// trstNum1>>=27;
// std::cout<<"trstNum1>>=27 "<<std::bitset<32>(trstNum1)<<std::endl;
// b=trstNum1;
// std::cout<<"b= "<<b<<std::endl;

// trstNum2=number<<6;
// trstNum2>>=(b+6);

// std::cout<<"The nominator is: "<<(sgn ? '-' : ' ') <<trstNum2<<std::endl;


// int sgn=(number>>31);
// test3<<=1;
// test3>>=27;
// int b=test3;



// unsigned nom,denom;
// bool flagInp=true;

// readNumber(nom, denom, flagInp);


// std::cout<<nom<<std::endl;
// std::cout<<denom<<std::endl;
    
    system("pause");
    return 0;
}





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

// Изчисляват _точно_ и кодират съответно сумата/разликата/произведението/частното на дадени две рационални числа.
// Това означава, че използване на float и double в междинните изчисления е забранено (!)
unsigned ratAdd(unsigned r1, unsigned r2);
unsigned ratSub(unsigned r1, unsigned r2);
unsigned ratMul(unsigned r1, unsigned r2);
unsigned ratDiv(unsigned r1, unsigned r2);

// Връща реципрочното на дадено рационално число
unsigned ratRec(unsigned rat);
// Връща противоположното на дадено рационално число
unsigned ratNeg(unsigned rat);
// Връща абсолютната стойност на дадено рационално число
unsigned ratAbs(unsigned rat);

// Превръща рационално число в стандартно дробно число
float rat2float(unsigned rat);
Напишете в кратък коментар в кода по едно предимство/недостатък на това представяне. Дайте пример за число, което можем да представим точно по този начин, но не като стандартен float. Дайте пример и за обратното.
Упътване
Можете да използвате наготово следните функции:
// Връща най-голямото общо кратно на две неотрицателни числа
int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    } else if (b != 0) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}
// Връща броят битове, необходим за представянето на дадено положително число
int numBits(int n) {
    int res = 0;
    while (n != 0) {
        n >>= 1; ++res;
    }
    return res;
}
Бонус - имплицитен водещ бит на знаменателя
Аналогично на стандартния формат за дробни числа, тук знаем, че знаменателят е ненулево число с водещ бит единица. Тогава числото B може да съдържа броят останали битове от представянето му, и само те да участват в кодирането:
1/3 -> 0 00001 0000000000000000000000001 1
9/8 -> 0 00011 00000000000000000001001 000
42 -> 0 00000 00000000000000000000101010 (!)
Променете вашите функции така, че да работят с този усложнен формат. Напишете по едно предимство/недостатък на това усложнение.
Бонус - сравнение със fp32

Различните представяния на реални числа имат различни предимства и недостатъци. Напишете кратка функция която да сравни грешката при събиране на голямо количество реални числа представени по два различни начина (fp32 и floating bar)

// Изчислява сумата на даден масив от рационални числа по два начина: точно и след превръщането им във float.
// Отпечатайте двата резултата и ги сравнете - в кои случаи единият е верен и в кои случаи другият?
void compareSums(unsigned rats[1000000]);

Предаване на кода

За да може да проверим вашите работи, трябва да спазите следните правила:

Може да се качи само един файл (архив от позволените формати) който да съдържа всичките нужни файлове. Има лимит на размера на архива - целта е да не добавяте временните файлове от компилация.
Освен изходният код трябва да качите и проектен файл който описва как се компилира вашият код. Това е проектен файл от средата за разработка която ползвате или файл който може да бъде изпълнен от терминал и ще компилира изцяло вашият код.
Някъде в предадените файлове трябва да упоменете спецификите на системата която използвате за да компилирате кода си (операционна система, компилатор, версия, среда за разработка и версия ако има такава)
*/
