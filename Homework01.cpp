#include <iostream>
#include <string>
#include <cctype>
#include <bitset>
#include <iomanip>
#include <cstdint>
#include <cstdlib>

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

//function to calculate the error between FP32 and floating bar
void errorRatArr(std::string arr[],int arrSize);

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

bool isFirstRow=true;

//creating string array for the test numbers
std::string arrNumInp[]={"1/3", "9/8", "-3/2", "0", "1", "-10", "1/4000000","42"};

int sizeArr=sizeof(arrNumInp)/sizeof(arrNumInp[0]);

unsigned ratNumArr[maxRatNum]={};

for (int i=0; i<sizeArr;i++) {

    std::string strNom,strDenom;
    divideString(arrNumInp[i], strNom, strDenom);

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

    if (!isFirstRow) {
        std::cout<<std::endl;
    };

    std::cout<<"The number "<<nomInp<<"/"<<denomInp<<" equals to: "<<ratNumber<<" which is in binary: "<<std::bitset<32>(ratNumber)<<std::endl;

    resultMsg(ratNumber);


    //representing rational numbers with implicit denom lead bit
    unsigned ratNumbImp=makeRatImp(nomInp,denomInp);
    
    if(!ratNumber) {
        errorMsg();
        return 0; 
    };

    std::cout<<std::endl;
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

//Basic arithmetic operations
//-----------------------------------------------------------------------------------------
    std::string operation;

    std::cout<<std::endl<<std::endl<<"Basic arithmethic operations: "<<std::endl;

    for (int i=1; i<sizeArr;i++) {

        std::cout<<std::endl<<getNumer(ratNumArr[i-1])<<'/'<<getDenom(ratNumArr[i-1])<<" and "
        <<getNumer(ratNumArr[i])<<'/'<<getDenom(ratNumArr[i])<<std::endl;

        //operation addition    
        std::cout<<std::endl;
        unsigned ratAddNum=ratAdd(ratNumArr[i-1], ratNumArr[i]);

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
        unsigned ratSubNum=ratSub(ratNumArr[i-1], ratNumArr[i]);

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
        unsigned ratMulNum=ratMul(ratNumArr[i-1], ratNumArr[i]);

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
        unsigned ratDivNum=ratDiv(ratNumArr[i-1], ratNumArr[i]);

        operation="division";

        if (!ratDivNum) {
            errorMsg(operation);
        }
        else {
            resultMsg(operation, ratDivNum,2);
            resultMsg(ratDivNum);
        };
    };

//comparison between FP32 and floating bar
//----------------------------------------------------------------------------------
std::string arrNumInpSmall[]={"1/2", "1/3", "-1/7", "1/13", "1/1"};
int arrSizeSmall=sizeof(arrNumInpSmall)/sizeof(arrNumInpSmall[0]);

std::string arrNumInpBig[]={"1", "10/3", "100", "100/2", "1000/3", "10000/4"};
int arrSizeBig=sizeof(arrNumInpBig)/sizeof(arrNumInpBig[0]);

std::string arrNumInpMix[]={"1/2", "10", "-1/7", "-1/3", "1/90", "-1/10",};
int arrSizeMix=sizeof(arrNumInpMix)/sizeof(arrNumInpMix[0]);


//function to calculate the error between FP32 and floating bar
std::cout<<std::endl<<"Small numbers:"<<std::endl;
errorRatArr(arrNumInpSmall,arrSizeSmall);

std::cout<<std::endl<<"Big numbers:"<<std::endl;
errorRatArr(arrNumInpBig,arrSizeBig);

std::cout<<std::endl<<"Mix numbers:"<<std::endl;
errorRatArr(arrNumInpMix,arrSizeMix);


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
        //Denom is always presented and printed on the console, even if the number is presented as an int
        //simple "if" can stop print it on console
    }
    else {
        strNom=inp.substr(0,foundIdx);
        strDenom=inp.substr(foundIdx+1,inp.size());
    };
};

//from task
// Връща най-голямото общо кратно на две неотрицателни числа
int gcd(int a, int b) {                     //-5/10 a=-5 b=10       a=10 b=-5 -5 10/-5  0  a=-5 b=0 a=0 b=-5 a=-5 b= 0
    if (a < b) {                            //a=0 b=-5      a=-5 b=0
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
//when using floating bar for calculating smaller numbers, we have more precision than the float,
//when calculating large numbers with floating bar we have number size limitations. float can calculate larger numbers 
void compareSums(unsigned rats[maxElem]) {
    
    float currSumFloat=0;
    double totalSumFB=0;

    for(int i=0; i<maxElem; i++) {

        //sum of floating bar elements
        int nom2=getNumer(rats[i]);
        int deNom2=getDenom(rats[i]);

        //std::cout<<nom2<<"/"<<deNom2<<std::endl;

        if (nom2!=0) {
        
        totalSumFB+=static_cast<double>(nom2)/deNom2;


        //sum of float elements
        currSumFloat+=rat2float(rats[i]);
        };
    };

    std::cout<<std::fixed<<std::setprecision(26);
    std::cout<<"The total sum of Floating bar elements is:  "<<totalSumFB<<std::endl;

    std::cout<<"The total sum of float elements is:         "<<currSumFloat<<std::endl;

};

//function to calculate the error between FP32 and floating bar
void errorRatArr(std::string arr[],int arrSize) {

    unsigned* ratNumArrComp=(unsigned*)malloc(maxElem*sizeof(unsigned));
    
    if(ratNumArrComp==NULL) {
        std::cout<<"Error allocating memory!"<<std::endl;
    }
    else {

        bool correctInpFlag=true;

        for (int idx=0; idx<arrSize;idx++) {

            std::string strNom,strDenom;
            divideString(arr[idx], strNom, strDenom);

            if(!isCorrectInp(strNom, strDenom)&&correctInpFlag) {
                    errorMsg();
                    correctInpFlag=false;
            }
            else {

                int nomInp, denomInp;

                long long tempNom=stoll(strNom);
                long long tempDenom=stoll(strDenom);
            
                if ((tempNom>INT32_MAX || tempDenom>INT32_MAX)&&correctInpFlag) {
                    errorMsg();
                    correctInpFlag=false;
                }
                else {

                    nomInp=tempNom;
                    denomInp=tempDenom;

                    //check if the denominator is equal to '0'
                    if (denomInp==0 && correctInpFlag) {
                        errorMsg();
                        correctInpFlag=false;
                    }
                    else {

                        unsigned ratNumber=makeRat(nomInp,denomInp);
                        
                        if(!ratNumber && correctInpFlag) {
                            errorMsg();
                            correctInpFlag=false; 
                        }
                        else {
                            
                            ratNumArrComp[idx]=ratNumber;
                        };
                    };
                };
            };
        };

        unsigned tempRat=0;
        for (int idx=arrSize; idx<(maxElem-arrSize);idx++) {
            tempRat=makeRat(0,1);
            
            ratNumArrComp[idx]=tempRat;
        };

    if (correctInpFlag) {
        compareSums(ratNumArrComp);
    };
    };

    free(ratNumArrComp);
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
