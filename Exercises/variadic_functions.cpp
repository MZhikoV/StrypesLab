#include <iostream>
#include <cstdarg>

// int sum(int count,...) {
//     int total=0;

//     std::va_list args;
//     va_start(args,count); //initialise the argument list

//     for (int i=0; i<count; i++) {
//         int v=va_arg(args,int);
//         std::cout<<v<<std::endl;
//         total+=v;
//     };

//     va_end(args);

//     return total;   
// };

// int max (int count,...) {
//     int maxEl=INT_MIN;
//     std::va_list args;
//     va_start(args,count);

//     for (int i=0; i<count;i++) {
//         int currArg=va_arg(args,int);

//         if (maxEl<currArg) {
//             maxEl=currArg;
//         };
//     };

//     va_end(args);

//     return maxEl;
// }

// int min(int count,...) {
//     int minEl=INT_MAX;

//     std::va_list args;
//     va_start(args,count);

//     for (int i=0; i<count;i++) {
//         int currEl=va_arg(args,int);
//         if (currEl<minEl) {
//             minEl=currEl;
//         };
//     };

//     va_end(args);
//     return minEl;
// };

int sum(int count, ...) {
    int result=0;

    std::va_list args;
    va_start(args,count); //initialise the argument list

    for (int i=0; i<count; i++) {
        int v=va_arg(args,int);
        std::cout<<v<<' ';
        result+=v;
    };

    va_end(args);

    std::cout<<std::endl;

    return result;
};

int max(int count, ...) {
    int result=INT_MIN;

    std::va_list args;

    va_start(args,count); //initialise argument list

    for (int i=0; i<count; i++) {
        int v=va_arg(args,int);
        std::cout<<v<<' ';
        if (result<v) {
            result=v;
        };
    };

    va_end(args);

    std::cout<<std::endl;

    return result;
};

int min(int count, ...) {
    int result=INT_MAX;

    std::va_list(args); //initialise arguments list

    va_start(args,count);

    for (int i=0; i<count; i++) {
        int v=va_arg(args, int);
        std::cout<<v<<' ';
        if (result>v) {
            result=v;
        };
    };

    va_end(args);

    std::cout<<std::endl;

    return result;
}

int main() {

    int result=sum(4, 10, 20, 30, 40);
    std::cout<<"Sum of elements: "<<result<<std::endl<<std::endl;

    int maxel=max(5, 1, 420, 16, 30, 940);
    std::cout<<"Max element is: "<<maxel<<std::endl<<std::endl;

    int minel=min(5, 1, 420, 0, 30, 940);
    std::cout<<"Min element is: "<<minel<<std::endl<<std::endl;


    system("pause");
    return 0;
}