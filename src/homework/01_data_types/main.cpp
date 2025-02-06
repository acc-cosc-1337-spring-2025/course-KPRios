//write include statements
#include "data_types.h" //tells C++ where to find multiply_numbers function
#include<iostream>

//write namespace using statement for cout
using std::cout; using std::cin;


int main()
{
	int num;
	cout<<"Enter a number: ";
	cin>>num;

	int results = multiply_numbers(num);

	cout<<"Result: "<<results<<"\n";

	int num1 = 4;

	int result = multiply_numbers(num1); //Declare result correctly

	cout<<"Result: "<<result<<"\n";

	return 0;
}
