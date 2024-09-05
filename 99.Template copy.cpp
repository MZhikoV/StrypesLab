#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

// void swapM(int ** a, int **b){
//     *a=*b;
// }

union Data {
    int intValue;
    float floadValue;
    char charValue;
    double doubleValue;
    };

int main() {

    Data arrHet[4];

    arrHet[0].intValue=10;
    arrHet[1].floadValue=3.25f;
    arrHet[2].doubleValue=4.567;
    arrHet[3].charValue='X';

    cout<<arrHet[0].intValue<<endl;

    double sum=0;
    // for (int i=0; i<4; i++) {
    //     cout<<arrHet[i]<<endl;
    // }
    
    // int c=-12;
    // cout<<c%10<<endl;
    // cout<<c/10<<endl;
    //int max;
    // int count=10;
    // int read[]={12,24,65,987,54,357,148,5613,96,0};
    // int temp[10]={0};

    // int * mat1=read;
    // int * mat2=temp;

    // swapM(&mat1,&mat2);


    // for (int i=0;i<10;i++) {
    //     cout<<mat1[i]<<' ';
    // };
    // cout<<endl;

    // int max=*max_element(read,read+count);
    // cout<<max<<endl;

    // int count=10;
    // int read[]={12,24,65,987,54,357,148,5613,96,0};
    // int exp=1;
    // int table[10] = {0};
    // for (int c = 0; c < count; c++) {
	// 	const int index = (read[c] / exp) % 10;
	// 	table[index]++;
	// }



    // int base=log10(252)+1;
    // cout<<base<<endl;
    // int basePlus=base&1;
    // cout<<basePlus<<endl;
    // int sum=base+basePlus;
    // cout<<sum<<endl;


    // system("pause");
    // return 0;



    // const char * arr1="Hello millo goes to drillo, huh";
    // cout<<*arr1<<endl<<arr1<<endl;
    // const char *tmp=arr1;
    // cout<<*tmp<<endl<<tmp<<endl;

    // tmp=&arr1[6];
    // cout<<*tmp<<endl<<tmp<<endl;


    system("pause");
    return 0;
}
