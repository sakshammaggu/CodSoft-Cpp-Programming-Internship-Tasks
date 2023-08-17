/*
    Task 2:
    -------
    Develop a calculator program that performs basic arithmetic
    operations such as addition, subtraction, multiplication, and
    division. Allow the user to input two numbers and choose an
    operation to perform.
*/
#include <iostream>
using namespace std;
void simple_calculator(double num1, double num2)
{
    char operation;
    cout<<"Choose an operation (+, -, *, /): ";
    cin>>operation;

    // Perform the chosen operation and display the result
    switch (operation) {
        case '+':
            cout<<"Result: " <<num1 + num2<<endl;
            break;
        case '-':
            cout<<"Result: " <<num1 - num2<<endl;
            break;
        case '*':
            cout<<"Result: " <<num1 * num2<<endl;
            break;
        case '/':
            if (num2 != 0) 
            {
                cout<<"Result: " << num1 / num2 << endl;
            } 
            else 
            {
                cout<<"Error: Cannot divide by zero." <<endl;
            }
            break;
        default:
            cout<<"Error: Invalid operation." <<endl;
            break;
    }
}
int main() 
{
    // Get user input for two numbers and the operation
    double num1;
    cout<<"Enter the first number: ";
    cin>>num1;

    double num2;
    cout<<"Enter the second number: ";
    cin>>num2;

    simple_calculator(num1, num2);
}
