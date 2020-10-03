// CPP function to generate all binary number 
// from 0 to given number n 
#include<iostream> 
#include<stdlib.h> 
using namespace std; 

// Maximum length of generated binary number 
const int MAX = 100; 

// CPP function to generate all binary number 
// for given number n 
char binaryGenerator(int n) 
{ 
	char a[MAX]; 

	for (int i = 0; i <= n; i++) { 

		// use define function itoa() to convert 
		// in given base 
		// a is char[] array where value store 
		// 2 is base, which convert. 
		itoa(i, a, 2); 

		cout << a << endl; 
	} 
} 

// Driven program 
int main() 
{ 
	int n = 10; 
	binaryGenerator(n); 
	return 0; 
} 
