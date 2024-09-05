//Orriginal code with comments is at the end

//The code is used for sorting arrays in ascending order
//The code represents the Radix sort algorithm, that processes the array elements digit by digit
//from the less significant to more significant digit and uses count sort algorithm

#include <cmath>
#include <iostream> //missing in the original code
#include <algorithm>

void moreMagic(int *&read, int count, int exp); //see function definition after main

void magic(int *a, int count);	//see function definition after main

void memError();	//see function definition after main

int main() {

	//declaring an d initialisation of input data
    int n;
    std::cin >> n;	//enter the number of elements

	if (n<2) {		//chek if the entered number is positive and greater than 1 so they can be sorted
		std::cout<<"Number of elements must be positive and greater or equal to 2!"<<std::endl;
		system("pause");
		return 0;
	}

	int * a=(int*)malloc(n*sizeof(int)); //allocating dynamic memory for the array, so we dont need to reserve unneeded memory
	
	if (!a) {
		memError();
		system("pause");
		return 0;
	};

	//there are three types of possible input int data - only positive, only negative or "mixed" numbers
	//in this case the chosen variant is only negative or only positive numbers see in "moreMagic" for mixed
	std::cout<<"Enter "<<n<<" only positive/negative integer nubers:"<<std::endl;

	bool allPositive=true, allNegative=true;

    for (int c = 0; c < n; c++) {
        std::cin >> a[c];
		if (a[c]<0) {
			allPositive=false;
		};
		if (a[c]>0) {
			allNegative=false;
		};
		if (!allPositive && !allNegative) {	//if the flags for both checks are false exit the program - mixed pos./neg. nums
			std::cout<<"Incorrect input!"<<std::endl;
			system("pause");
			return 0;
		};
    };

   magic(a, n);	//calling the sort function

    for (int c = 0; c < n; c++) {	//printing the sorted array
        std::cout << a[c] << ' ';
    };

	std::cout<<std::endl;

	free(a);	//free dynamic memory
	
    system("pause");
    return 0;
}

//----------------------------------------------------------------------------------------------
//function definitions

void moreMagic(int *&read, int count, int exp) {

//if we have mixed pos. and neg. numbers we will need two arrays for each type of nums
// '0'-s will be part only in one of the arrays
	int table[10] = {0};

//creating count array for each digit from the less significant to more significant digit
//digit "jumping" is achieved by dividing the number with the exp, which increases with 10 at every call from "magic"
//exp determines the digit position for units, tens...
//"table" array counts the occurances of each digit(0-9)
	for (int c = 0; c < count; c++) {
		const int index = (read[c] / exp) % 10;
		table[index]++;
	};

//creating the cumulative count array for each digit (0-9)
	for (int c = 1; c < 10; c++) {
		table[c] += table[c - 1];
	};

	int * write=(int*)malloc(count*sizeof(int)); //allocating dynamic memory for the array, so we dont need to reserve unneeded memory

	if (!write) {
		memError();
		system("pause");
		exit(0);	//quickest way to exit without making bool flags and check back to "magic" and "main"
	}
//using the count sort algorithm, where starting from the last element of the array and based on the cumulative count array
//we determine the position of the current element, keeping the order of appearance in the base array
// *smart indian guy has a great explanation video on youtube ;)
	for (int c = count - 1; c >= 0; c--) {
		const int index = (read[c] / exp) % 10;
		write[table[index] - 1] = read[c];
		table[index]--;
	};

	std::copy(write,write+count,read);	//copy the temp array in the main array

	free(write);	//free dynamic memory
};


void magic(int *a, int count) {
	
	//using the STL we can find the max element by using "max_element" function teplate
	const int target=*std::max_element(a,a+count);

	const int base = log10(target) + 1;	//calculates the number of digits the max element has

//loop for calling the count sort algorithm for every significant digit
//the safeguard "base + (base & 1)" is not required when using fixed number digits
//(when the number of digits is odd it adds one more iteration, so the total iterations become even)
	for (int c = 0, exp = 1; c < base; c++, exp *= 10) {	
		moreMagic(a, count, exp);
	};
};

void memError() {
	std::cout<<"Memory error!"<<std::endl;
};


//--------------------------------------------------------------------------------------------------------------------------
//Original code with comments
/*
#include <cmath>
#include <iostream> //missing


void moreMagic(int *&read, int count, int exp, int *&write) {
	int table[10] = {0};

//creating count array for each digit from the less significant to more significant digit
//digit "jumping" is achieved by dividing the number with the exp, which increases with 10 at every call from "magic"
//exp determines the digit position for units, tens...
//"table" array counts the occurances of each digit(0-9)
	for (int c = 0; c < count; c++) {
		const int index = (read[c] / exp) % 10;
		table[index]++;
	}

//creating the cumulative count array for each digit (0-9)
	for (int c = 1; c < 10; c++) {
		table[c] += table[c - 1];
	}
//using the count sort algorithm, where starting from the last element of the array and based on the cumulative count array
//we determine the position of the current element, keeping the order of appearance in the base array
// *smart indian guy has a great explanation video on youtube ;)
	for (int c = count - 1; c >= 0; c--) {
		const int index = (read[c] / exp) % 10;
		write[table[index] - 1] = read[c];
		table[index]--;
	}
//swaping the array pointers for returning the sorted array;
	int *a = read;
	read = write;
	write = a;
}

void magic(int *a, int count, int *b) {
	if (count < 2) {	//check if the array has more than 1 element so it can be sorted
		return;
	}
	int find = 0;
	for (int c = 1; c < count; c++) {	//loop for finding the max element in the array
		if (a[c] > a[find]) {
			find = c;
		}
	}
	const int target = a[find];			//max element in the array
	const int base = log10(target) + 1;	//calculates the number of digits the max element has

//loop for calling the count sort algorithm for every significant digit
	for (int c = 0, exp = 1; c < base + (base & 1); c++, exp *= 10) {	
		moreMagic(a, count, exp, b);
	}
}


int main() {

	//declaring an initialisation of input data
    int a[200], b[200];
    int n;
    std::cin >> n;
    for (int c = 0; c < n; c++) {
        std::cin >> a[c];
    }


    magic(a, n, b);	//calling the sort function


    for (int c = 0; c < n; c++) {	//printing the sorted array
        std::cout << a[c] << ' ';
    }

    system("pause");
    return 0;
}
*/