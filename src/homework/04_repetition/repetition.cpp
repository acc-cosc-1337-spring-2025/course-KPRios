//add include statements
#include "repetition.h"

//add function(s) code here

// Function to calculate the factorial of a number
int factorial(int num) {
    int product = 1;
    while (num > 0) {
        product *= num;  
        num--;            
    }
    return product;
}

// Function to calculate the greatest common divisor (gcd)
int gcd(int num1, int num2) {
    while (num1 != num2) {
        if (num1 < num2) {
            num2 -= num1;  
        } else {
            num1 -= num2;  
        }
    }
    return num1;  
}