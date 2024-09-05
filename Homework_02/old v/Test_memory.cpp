#include <stdio.h>
#include <stdlib.h>

#include<crtdbg.h> //remove after check


int main() {
    int * offset_x=(int*)malloc(sizeof(int));
    int * offset_y=(int*)malloc(sizeof(int));

    *offset_x=10;
    *offset_y=20;

    free(offset_x);

    _CrtDumpMemoryLeaks();

    system("pause");
    return 0;
}