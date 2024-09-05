#include <iostream>
#include <thread>
#include <chrono>
#include <string>


//creating Progress bar using dynamic memory allocation
std::string createProgressBar(   float currProgress, bool flagPercent, int totArrLength,
                            char endLeft, char endRight, char fillSymb, char emptySymb);

//creating Progress bar using std::string
std::string createProgressBarV02(   float currProgress, bool flagPercent, int totArrLength,
                            char endLeft, char endRight, char fillSymb, char emptySymb);

//print Progress bar
void printBar(int sections, int delay, const std::string & progressBar);


int main() {

int totalTimeSec=5; //time has always a positive value
bool flagPercent=true;  //show percent sign (true)
int totalBarLength=50;  //left and right delimiters included, always positive
char endLeft='[';       //left delimiter symbol
char endRight=']';      //right delimiter symbol
char fillSymb='*';      //fill bar symbol
char emptySymb='_';     //empty bar symbol

if (totalTimeSec<=0 || (flagPercent && totalBarLength<8) || (!flagPercent && totalBarLength<4) || (fillSymb==emptySymb)) {
//additional check can be included if needed - to verify that the open and close delimiters are from the same kind
// || (endLeft!='(' && (abs(endLeft-endRight)!=2)) || (endLeft=='(' && (abs(endLeft-endRight)!=1))
// #include<cmath> must be added
    std::cout<<"Wrong input!"<<std::endl;
    system("pause");
    return 0;
};

int barSections=20;     //generates progress sections

int delay=(totalTimeSec*1000)/barSections;  //calculates the time needed for each section, in miliseconds   


for (int i=0; i<=barSections; i++) {
    float currProgress=i*(1.0/barSections);
    
    std::cout<<"Using dynamic memory allocation:"<<std::endl;
    std::string progressBar=createProgressBar(currProgress,flagPercent,totalBarLength, endLeft, endRight, fillSymb, emptySymb);
    std::cout<<progressBar<<std::endl;

    std::cout<<"Using std::string:"<<std::endl;
    std::string progressBarV02=createProgressBarV02(currProgress,flagPercent,totalBarLength, endLeft, endRight, fillSymb, emptySymb);
    std::cout<<progressBarV02<<std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    system("cls");
};

    system("pause");
    return 0;
}

//---------------------------------------------------------------------------------------------------------------

//creating Progress bar using dynamic memory allocation
std::string createProgressBar(   float currProgress, bool flagPercent, int totArrLength,
                            char endLeft, char endRight, char fillSymb, char emptySymb) {
    char * arrBar=(char*)malloc((totArrLength+1)*sizeof(char)); //вариант с динамична алокация  //да се провери вариант със стринг
    if(arrBar) {
        arrBar[0]=endLeft;
        arrBar[totArrLength-1]=endRight;
        arrBar[totArrLength]='\0';
        int currStop=currProgress*(totArrLength-2);
        for (int i=1; i<=currStop;i++) {
            arrBar[i]=fillSymb;
        };

        for (int i=currStop+1; i<(totArrLength-1);i++) {
            arrBar[i]=emptySymb;
        };

        if (flagPercent) {

            int progressCheck=currProgress*100;
            int centerPoint=(totArrLength/2);
            int percentDefl=0;

            if (progressCheck<10) {
                arrBar[centerPoint-1]=static_cast<char>(progressCheck+48);
            }
            else if (progressCheck<100) {
                arrBar[centerPoint]=(progressCheck%10+48);
                progressCheck/=10;
                arrBar[centerPoint-1]=(progressCheck+48);
                percentDefl++;
            }
            else {
                arrBar[centerPoint]=(progressCheck%10+48);
                progressCheck/=10;
                arrBar[centerPoint-1]=(progressCheck%10+48);
                progressCheck/=10;
                arrBar[centerPoint-2]=(progressCheck+48);
                percentDefl++;
            };

            
            arrBar[centerPoint+percentDefl]='%';
        };
    }

    std::string progressBar=std::string(arrBar);
    
    free(arrBar);

    return progressBar;
};


//creating Progress bar using std::string
std::string createProgressBarV02(   float currProgress, bool flagPercent, int totArrLength,
                            char endLeft, char endRight, char fillSymb, char emptySymb) {

int currStop=currProgress*(totArrLength-2);

std::string percentAdd="";

if (flagPercent) {
    int progressCheck=currProgress*100;
    percentAdd=std::to_string(progressCheck)+"%";
};

//create "%" centered in the bar
int visibleBar=totArrLength-2-percentAdd.length();

std::string leftFull="", leftEmpty="", rightFull="", rightEmpty="";

if ((currStop>=(visibleBar/2)) && (currStop<=((visibleBar/2)+percentAdd.length()))) {
    leftFull=std::string(visibleBar/2,fillSymb);
    rightEmpty=std::string(totArrLength-2-visibleBar/2-percentAdd.length(),emptySymb);
}
else if (currStop>((visibleBar/2)+percentAdd.length())) {
    leftFull=std::string(visibleBar/2,fillSymb);
    rightFull=std::string(currStop-visibleBar/2-percentAdd.length(),fillSymb);
    rightEmpty=std::string(totArrLength-2-currStop,emptySymb);
}
else {
    leftFull=std::string(currStop,fillSymb);
    leftEmpty=std::string(visibleBar/2-currStop,emptySymb);
    rightEmpty=std::string(totArrLength-2-visibleBar/2-percentAdd.length(),emptySymb);
};

std::string progressBar=endLeft+leftFull+leftEmpty+percentAdd+rightFull+rightEmpty+endRight;

return progressBar;

};