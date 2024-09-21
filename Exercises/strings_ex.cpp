#include <iostream>

void printS(const char * arr) {
    int idx=0;
    while (arr[idx]) {
        std::cout<<arr[idx];
        idx++;
    };
    std::cout<<std::endl;
};

size_t lenS(const char * arr) {
    size_t len=0;
    while (arr[len]) {
        len++;
    };
    return len;
};

bool cpyS(char * dest, const char * source) {
    if (lenS(dest)<lenS(source)) {
        return false;
    };
    int idx=0;
    while (source[idx]){
        dest[idx]=source[idx];
        idx++;
    };
    dest[idx++]='\0';

    return true;
};

void catS(char * dest, const char * source) {
    int idx=0;
    int destIdx=lenS(dest);
    while (source[idx]){
        dest[destIdx++]=source[idx++];
    };
    dest[destIdx]='\0';
}

int cmpS(const char * arr1, const char * arr2) {

    while (*arr1 && *arr1==*arr2) {
        arr1++;
        arr2++;
    };

    return *arr1-*arr2;
};

int chrS(const char * arr1, const char x) {
    int i=0;
    while (arr1[i]) {
        if (arr1[i]==x) {
            return i;
        };
        i++;
    };
    return -1;
}


int main() {

    char arr1[100]="Hello";
    const char* arr2="world";
    char arr3[100]={'H', 'e', 'l','l','o',' ', 'd','a','r','k','n','e','s','s'};
    char arr4[]={'m', 'y', ' ', 'o','l','d', ' ','f','r','i','e','n','d','\0'};


    printS(arr1);
    std::cout<<"The length of arr1 is: "<<lenS(arr1)<<std::endl;
    printS(arr2);
    std::cout<<"The length of arr2 is: "<<lenS(arr2)<<std::endl;
    printS(arr3);
    std::cout<<"The length of arr3 is: "<<lenS(arr3)<<std::endl;
    printS(arr4);
    std::cout<<"The length of arr4 is: "<<lenS(arr4)<<std::endl;

    // cpyS(arr1,arr2);
    // std::cout<<"Copy arr2 in arr1: ";
    // printS(arr1);

    // cpyS(arr3,arr4);
    // std::cout<<"Copy arr4 in arr3: ";
    // printS(arr3);

    // std::cout<<"Concatenated arr1 and arr2: ";
    // catS(arr1,arr2);
    // printS(arr1);

    // std::cout<<"Concatenated arr1 and arr2: ";
    // catS(arr3,arr4);
    // printS(arr3);

    // std::cout<<cmpS(arr1,arr2)<<std::endl;
    // std::cout<<cmpS(arr3,arr4)<<std::endl;

    std::cout<<"First occurence of -l- in arr1 is at pos: "<<chrS(arr1, 'l')<<std::endl;
    std::cout<<"First occurence of -k- in arr3 is at pos: "<<chrS(arr3, 'k')<<std::endl;
    std::cout<<"First occurence of -k- in arr4 is at pos: "<<chrS(arr4, 'k')<<std::endl;


    system("pause");
    return 0;
}