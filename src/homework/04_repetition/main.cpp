//write include statements
#include <iostream>
#include "repetition.h"

//write using statements

int main() 
{
	int choice, num1, num2;
    
    do {
        // Display menu
        std::cout << "MAIN MENU\n";
        std::cout << "1 - Factorial\n";
        std::cout << "2 - Greatest Common Divisor\n";
        std::cout << "3 - Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Factorial
                std::cout << "Enter a number to calculate the factorial: ";
                std::cin >> num1;
                std::cout << "Factorial of " << num1 << " is: " << factorial(num1) << std::endl;
                break;
            
            case 2: // Greatest Common Divisor
                std::cout << "Enter two numbers to calculate the gcd: ";
                std::cin >> num1 >> num2;
                std::cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << std::endl;
                break;
            
            case 3: // Exit
                char confirm;
                std::cout << "Are you sure you want to exit? (Y/N): ";
                std::cin >> confirm;
                if (confirm == 'Y' || confirm == 'y') {
                    std::cout << "Exiting the program...\n";
                } else {
                    std::cout << "Returning to the menu...\n";
                }
                break;

            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 3);
	return 0;
}
