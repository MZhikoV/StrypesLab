// // istream::getline example
// #include <iostream>     // std::cin, std::cout
// #include <cstring>
// #include <cstdlib>

// int main () {
//   // char name[256], title[256];

//   // std::cout << "Please, enter your name: ";
//   // std::cin.getline (name,256);

//   // std::cout << "Please, enter your favourite movie: ";
//   // std::cin.getline (title,256);

//   // std::cout << name << "'s favourite movie is " << title;
//   char text[256]={"some text here"};

//   //char * text={"some text here"};
//   std::cout<<text<<std::endl;
//   std::cout<<strlen(text)<<std::endl;

//   char * newbegin=strchr(text,'t');
//   char * begin=text;
//   std::cout<<"begin-"<<begin<<std::endl;

//   char test[256];

//   std::cout<<(newbegin-begin)<<std::endl;
//   strncpy(test,text,(newbegin-begin));
//   test[(newbegin-begin)]='!';
//   std::cout<<"tets-"<<test<<std::endl;

// system("pause");
//   return 0;


//   char * newend=strrchr(text,'t');


// //   //char * test=(char *)malloc(sizeof(char)*((newend-newbegin+2)));
// //   char test[256];
// //   strcpy(test,newend+2);
// //   std::cout<<"tets-"<<test<<std::endl;

// // system("pause");
// //   return 0;


// //   strncpy(test,newbegin,(newend-newbegin+1));
// //   test[newend-newbegin+1]='\0';
  



// //   std::cout<<"tets-"<<test<<std::endl;
// //   strcpy(text,test);
// //   //memcpy(newbegin,test,newend-newbegin+2);
// //   std::cout<<"final text "<<text<<std::endl;
// //   std::cout<<strlen(text)<<std::endl;
// //   //free(test);
// //   memcpy(test,test,2);
// //   std::cout<<"tes "<<test<<std::endl;


// //   // char * text={"some text here"};
// //   // char * newbegin=strchr(text,'t');
// //   // char * newend=strrchr(text,'t');
  

// //   //char * arrBar=(char*)malloc((totArrLength+1)*sizeof(char));

// //   // char str[] = "memmove can be very useful......";
// //   // memmove (str+20,str+15,11);
// //   // puts (str);

// //   // memmove(&text,&newbegin,10);
// //   // //std::cout<<(newend-newbegin+1)<<std::endl;
// //   // std::cout<<text<<std::endl;
// //   // std::cout<<strlen(text)<<std::endl;

// system("pause");
//   return 0;
// }


#include <iostream>
#include <cstdlib>
#include <cctype>

//#include <bits/stdc++.h>
using namespace std;

// void bin(unsigned n, int * arr)
// {

//   int i=0;
//   while (n>0) {
//     arr[i]=n%2;
//     n/=2;
//     i++;
//   };
// }

void print(const char * str) {
    if (*str=='\0') {return;}

    cout<<*str;
    print(str+1);
}


// // Driver Code
int main(void)
{

print("123456789");




// cout<<tolower('A')<<endl;
//   bool sure=-1;
// cout<<sure<<endl;
//   int abs=4;
//   int const count=abs;
//   //int * arr=new int[count];
//   int arr[count]={0};
//   bin(0,arr);
//   for (int i=0;i<count;i++) {
//     cout<<arr[i];
//   };
//   cout << endl;
//   bin(15,arr);
//   for (int i=0;i<count;i++) {
//     cout<<arr[i];
//   };
//   cout<<endl;
system("pause");
return 0;
}