#include <iostream>

void print(const char* str) {
    if (*str == '\0') { return; }
    std::cout << *str;
    print(str + 1);
    //std::cout << *str;
    //print(str + 1);
    //std::cout << *str;
}

int main() {

    print("abcdef");

    std::cout<<std::endl;

    system("pause");
    return 0;
}