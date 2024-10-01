#include <iostream>

int main() {

    //Solution 1 int numRows, int * rowSizes
    int rows, rSize;
    std::cin>>rows>>rSize;

    int ** data=(int**)malloc(rows*sizeof(int*));
    if (!data) {
        std::cout<<"Error!"<<std::endl;
        return 0;
    };

    for (int i=0; i<rows; i++) {
        data[i]=(int*)malloc(rSize*sizeof(int));
        if (!data[i]) {
            std::cout<<"Error!"<<std::endl;
            return 0;
        };
    };

    for (int i=0; i<rows;i++) {
        for (int j=0; j<rSize; j++) {
            std::cin>>data[i][j];
        };
    };

    for (int i=0; i<rows;i++) {
        for (int j=0; j<rSize; j++) {
            std::cout<<data[i][j]<<' ';
        };
        std::cout<<std::endl;
    };
    std::cout<<std::endl;

    int row2[3]={9,9,9};
    int * sub= row2;

    data[1]=sub;

    for (int i=0; i<rows;i++) {
        for (int j=0; j<rSize; j++) {
            std::cout<<data[i][j]<<' ';
        };
        std::cout<<std::endl;
    };
    std::cout<<std::endl;




    for (int i=0; i<rows; i++) {
        free (data[i]);
    };

    free(data);

    system("pause");
    return 0;
}