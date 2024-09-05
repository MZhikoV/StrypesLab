#include <iostream>
#include <cstring>

//get the number of occurances of needle in haystack
int getWordCount(const char *haystack, const char * needle);

//function for find and replace a substring in a string
char *stringReplace(const char *haystack, const char *needle, const char *replace);

int main() {

    const char *haystack = {"the quick brown fox jumps over the brown fence"};
    const char *needle = {" "};
    const char *replace={"<SPACE>>"};

    if (!haystack || !needle || !replace || strlen(needle)==0) {
        std::cout<<"Incorrect input!"<<std::endl;
        system("pause");
        return 0;
    };

    if (needle==replace) {
        std::cout<<"The string will not change:"<<std::endl;
        std::cout<<haystack<<std::endl;
        system("pause");
        return 0;
    };

    char * newstring=stringReplace(haystack, needle, replace);  //call find/replace function
    if (!newstring) {
        system("pause");
        return 0;
    }
    else {
        std::cout<<"New string:"<<std::endl<<newstring<<std::endl;
        free(newstring);
    };

    system("pause");
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------

//function for find and replace a substring in a string
char *stringReplace(const char *haystack, const char *needle, const char *replace) {
    int occurancesCount=getWordCount(haystack, needle); //get the number of occurances of needle in haystack

    //get the length of the new arr
    int newLength=strlen(haystack)-(occurancesCount*(strlen(needle)))+(occurancesCount*(strlen(replace)));

    char *result=(char *)malloc((newLength+1)*sizeof(char));    //allocate memory for the new arr +1 for the '\0'

    if (result) {
        char *currPtr=result;
        const char *findString;

        for (int i=0; i<occurancesCount; i++) {
            findString=strstr(haystack,needle); //find the occurance in main string
            strncpy(currPtr,haystack,(strlen(haystack)-strlen(findString)));    //copy the substring before the occurance
            currPtr+=strlen(haystack)-strlen(findString);   //move the ptr to the end of the new string           
            strncpy(currPtr,replace,strlen(replace));    //copy the replace string in the new string at current position
            //strcpy(currPtr,replace);    //copy the whole replace string in the new string at current position
            currPtr+=strlen(replace);    //move the ptr to the end of the new string
            haystack=findString+strlen(needle); //use the remainder of the main string, just after the searched string
        };

        strcpy(currPtr,haystack);   //copy the remainder of the main string in the new string

        return result;
    }
    else {
        std::cout<<"Memory can't be allocated!"<<std::endl;
        return NULL;
    };
};

//get the number of occurances of needle in haystack
int getWordCount(const char *haystack, const char * needle) {
    int count=0;

    const char* tmp = haystack;

    while (tmp=strstr(tmp,needle)) {
        count++;
        tmp=tmp+strlen(needle);
    };

    return count;
};