/* 
This project I created a console of a basic calculator that does the basic things like add, subtract, multiply and divide. I also allowed the user to use the calcultor until user no longer wants to use.
*/

#include <iostream>
#include <limits>

using namespace std;

int main() {
    double num1, num2;
    char operation;
    char choice;

    cout << "Console Calculator\n";
    cout << "------------------\n";

    do {
        // Input first number
        cout << "Enter the first number: ";
        cin >> num1;

        // Input operation
        bool isValidOperation = false;
        while (!isValidOperation) {
            cout << "Enter an operation (+, -, *, /): ";
            cin >> operation;

            switch (operation) {
                case '+':
                case '-':
                case '*':
                case '/':
                    isValidOperation = true;
                    break;
                default:
                    cout << "Error: Invalid operation. Please try again.\n";
                    break;
            }
        }

        // Input second number
        cout << "Enter the second number: ";
        cin >> num2;

        // Perform the calculation based on the chosen operation
        double result;
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Division by zero is not allowed.\n";
                    continue;
                }
                break;
        }

        // Display the result
        cout << "Result: " << result << endl;

        // Prompt for continuation
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

