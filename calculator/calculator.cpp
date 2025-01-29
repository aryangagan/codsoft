#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    int choice;

    cout << " Here is  Calculator Program!" << endl;
    cout << "Choose an operation to perform:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;

    // Get the user's choice
    cout << "Enter your choice (1/2/3/4): ";
    cin >> choice;

    // Validate the choice
    if (choice < 1 || choice > 4) {
        cout << "Invalid operation. Please restart the program and try again." << endl;
        return 1;
    }

    // Get the two numbers from the user
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Perform the chosen operation
    switch (choice) {
        case 1:
            result = num1 + num2;
            cout << "The result of addition is: " << result << endl;
            break;
        case 2:
            result = num1 - num2;
            cout << "The result of subtraction is: " << result << endl;
            break;
        case 3:
            result = num1 * num2;
            cout << "The result of multiplication is: " << result << endl;
            break;
        case 4:
            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
            } else {
                result = num1 / num2;
                cout << "The result of division is: " << result << endl;
            }
            break;
        default:
            cout << "Unexpected error." << endl;
            break;
    }

    return 0;
}