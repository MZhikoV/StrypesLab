#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

// void testArr(int arr[200]) {
//     // int len=sizeof(arr)/sizeof(arr[0]);
//     int len=sizeof(arr);
//     std::cout<<len<<std::endl;
// }

int gcd(int a, int b) {                     //-5/10 a=-5 b=10       a=10 b=-5 -5 10/-5  0  a=-5 b=0 a=0 b=-5 a=-5 b= 0
    if (a < b) {                            //a=0 b=-5      a=-5 b=0
        return gcd(b, a);
    } else if (b != 0) {
        return gcd(b, a % b);
    } else {
        return a;
    }
};

int main() {
    
    // double a=1E27;
    // double b=3E28;
    // float c=a/b;

    // std::cout<<c<<std::endl;

        // std::cout<<(8^8)<<std::endl;

        // int arr[100];

        // for (int i=0; i<10;i++) {
        //     arr[i]=i;
        // };

        // std::cout<<sizeof(arr)<<std::endl;

        // testArr(arr);;

    int g=gcd(-5,10);

    std::cout<<g<<std::endl;


    system("pause");
    return 0;
}
