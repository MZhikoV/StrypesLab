#include <iostream>

int main() {

    // //Solution 1 int numRows, int * rowSizes
    // int rows, rSize;
    // std::cin>>rows>>rSize;

    // //create a dynamic array of pointers for each row
    // int ** data=(int**)malloc(rows*sizeof(int*));
    // if (!data) {
    //     std::cout<<"Error!"<<std::endl;
    //     return 0;
    // };

    // //creating a dynamic array for each row
    // for (int i=0; i<rows; i++) {
    //     data[i]=(int*)malloc(rSize*sizeof(int));
    //     if (!data[i]) {
    //         std::cout<<"Error!"<<std::endl;
    //         return 0;
    //     };
    // };

    // //initialise elements
    // for (int i=0; i<rows;i++) {
    //     for (int j=0; j<rSize; j++) {
    //         std::cin>>data[i][j];
    //     };
    // };

    // //print elements
    // for (int i=0; i<rows;i++) {
    //     for (int j=0; j<rSize; j++) {
    //         std::cout<<data[i][j]<<' ';
    //     };
    //     std::cout<<std::endl;
    // };
    // std::cout<<std::endl;

    // //create a substitute row
    // int row2[3]={9,9,9};
    // int * sub= row2;

    // //substitute row2
    // data[1]=sub;

    // //print new elements
    // for (int i=0; i<rows;i++) {
    //     for (int j=0; j<rSize; j++) {
    //         std::cout<<data[i][j]<<' ';
    //     };
    //     std::cout<<std::endl;
    // };
    // std::cout<<std::endl;

    // //deallocate each row
    // for (int i=0; i<rows; i++) {
    //     free (data[i]);
    // };

    // //deallocate array
    // free(data);




    // //Solution 2 int rows, int cols, we don't change sizes
    // int cols, rows;
    // std::cin>>rows>>cols;

    // //create a dynamic array for all elements (rows*cols), elements are in a sequence
    // int * data=(int*)malloc(rows*cols*sizeof(int));

    // if (!data) {
    //     std::cout<<"Error!"<<std::endl;
    //     return 0;
    // };

    // //initialise elements
    // for (int i=0; i<rows; i++) {
    //     for (int j=0; j<cols;j++) {
    //         std::cin>>data[(i*cols+j)];
    //     };
    // };

    // //print elements
    // for (int i=0; i<rows; i++) {
    //     for (int j=0; j<cols;j++) {
    //         std::cout<<data[(i*cols+j)]<<' ';
    //     };
    //     std::cout<<std::endl;
    // };

    // std::cout<<std::endl;

    // free(data);

    //solution 3 jagged array fixed rows, diff, cols sizes
    int rows;
    std::cin>>rows;

    //create prefix array, last element is the total number of data array elements
    int * offsetArray=(int*)malloc((rows+1)*sizeof(int));

    if (!offsetArray) {
        std::cout<<"Error!"<<std::endl;
        return 0;
    };

    //setting the first element to be '0'
    offsetArray[0]=0;
    int tmp=0;

    //initialising the prefix array
    for (int i=1; i<=rows; i++) {
        std::cin>>tmp;
        offsetArray[i]=offsetArray[i-1]+tmp;
    };

    //allocate jogged arrai as a sequence of numbers
    int* data=(int*)malloc(offsetArray[rows]*sizeof(int));

    if (!data) {
        std::cout<<"Error!"<<std::endl;
        return 0;
    };

    //initializing the jagged data array
    for (int i=0; i<rows; i++) {
        for (int j=0; j<(offsetArray[i+1]-offsetArray[i]); j++){
            std::cin>>data[offsetArray[i]+j];
        };
    };

    //print jogged array
    for (int i=0; i<rows; i++) {
        for (int j=0; j<(offsetArray[i+1]-offsetArray[i]); j++){
            std::cout<<data[offsetArray[i]+j]<<' ';
        };
        std::cout<<std::endl;
    };

    std::cout<<std::endl;

    free(offsetArray);
    free(data);

    system("pause");
    return 0;
}