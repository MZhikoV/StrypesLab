#include <iostream>
#include <thread>
#include <chrono>
#include <string>

// char * createProgressBar(   float currProgress=0, bool flagPercent=true, int barDivision=50,
//                             char endLeft='[', char endRight=']',
//                             char fillSymb='*', char emptySymb='_'
//                         );

std::string createProgressBar(   float currProgress, bool flagPercent, int barDivision,
                            char endLeft, char endRight, char fillSymb, char emptySymb
                        );

/*
Примерен изход в един момент, показващ прогрес бар със затапващи символи “[“ и “]”, запълващ символ “=”, празен символ интервал и показана стойност на процент на запълване.
[============   30%             	]
 ***************---*****************

Примерен изход със затапващи символи “<” и “>”, запълващ символ “-”, празен символ “.” и показване на процентите:
<-------------------------60%--....................>

*/

int main() {


int totalTimeSec=5; //to do an array that includes edge cases -5, 0 and a few more reasonable times + one very slow(big time)
//printProgressBar();

bool flagPercent=true;
int totalBarLength=50; //only the internal sections, left and right delimiters are not included
char endLeft='[';
char endRight=']';
char fillSymb='*';
char emptySymb='_';




int animationFrames=30;
int delay=(totalTimeSec*1000)/animationFrames;

for (int i=0; i<=animationFrames; i++) {
    float currProgress=i*(1.0/animationFrames);
    //std::cout<<currProgress<<std::endl;
    // char * progressBar=createProgressBar(currProgress,flagPercent,totalBarLength, endLeft, endRight, fillSymb, emptySymb);
    std::string progressBar=createProgressBar(currProgress,flagPercent,totalBarLength, endLeft, endRight, fillSymb, emptySymb);
    // std::string progressBar(createProgressBar(currProgress,flagPercent,totalBarLength, endLeft, endRight, fillSymb, emptySymb)+'\0');
    std::cout<<progressBar<<std::endl;

    // for (int j=0;j<=totalBarLength;j++) {
    //     std::cout<<progressBar[j];
    // };
    

    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    system("cls");

    //free(progressBar);
};


// char * progressBarr=createProgressBar(0.7);

// for (int i=0; i<52;i++) {
//     std::cout<<progressBarr[i];
// }
// std::cout<<std::endl;
// std::cout<<std::endl;





//printProgressBar(1);




    system("pause");
    return 0;
}

std::string createProgressBar(   float currProgress, bool flagPercent, int barDivision,
                            char endLeft, char endRight, char fillSymb, char emptySymb
                        ) {
    int totArrLength=barDivision+1;
    char * arrBar=(char*)malloc((totArrLength)*sizeof(char)); //вариант с динамична алокация  //да се провери вариант със стринг
    if(arrBar) {
        char test='a';

        arrBar[0]=endLeft;
        arrBar[totArrLength]=endRight;
        int currStop=currProgress*barDivision;
        for (int i=1; i<=currStop;i++) {
            arrBar[i]=fillSymb;
        };

        for (int i=currStop+1; i<totArrLength;i++) {
            arrBar[i]=emptySymb;
        };

        int progressCheck=currProgress*100;
        int centerPoint=(barDivision/2)+1;
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
        }

        if (flagPercent) {
            arrBar[centerPoint+percentDefl]='%';
        }

        // for (int i=0; i<=totArrLength;i++) {
        //     std::cout<<arrBar[i];
        // }
        // std::cout<<std::endl;
    }

    std::string progressBar=std::string(arrBar);
    
    free(arrBar);

    return progressBar;
};





/*

[****0 %****]
[****1 0%***]
[***10 0%***]


*/