//write include statements
#include <iostream>   // for cin and cout
#include "hwexpressions.h" 
#include "hwexpressions.cpp"

//write namespace using statement for cout

using namespace std;

int main()
{
    double meal_amount, tip_rate, tip_amount, tax_amount, total;

    cout << "Enter the meal amount: ";
    cin >> meal_amount;

    tax_amount = get_sales_tax_amount(meal_amount);

    cout << "Enter the tip rate (as a decimal, e.g., 0.15 for 15%): ";
    cin >> tip_rate;
	tip_rate /100:

    tip_amount = get_tip_amount(meal_amount, tip_rate);

    total = meal_amount + tax_amount + tip_amount;

    cout << fixed;  // 
    cout.precision(2);  

    cout << "\nReceipt:\n";
    cout << "Meal Amount:          $" << meal_amount << endl;
    cout << "Sales Tax:            $" << tax_amount << endl;
    cout << "Tip Amount:           $" << tip_amount << endl;
    cout << "Total:                $" << total << endl;


	return 0;
}

