#include <iostream>
using namespace std;

int main()
{
    string  operation;
    double number1, number2;

    cout <<"Enter first  number: ";
    cin >> number1;
    cout <<"Enter Operation (+, -, *, /,): ";
    cin >> operation;
    cout <<"Enter second  number: ";
    cin >> number2;

    if (operation == "+") {
        cout << number1 + number2;
    }
    else if (operation == "-") {
        cout  << number1 - number2;
    }
    else if (operation == "*") {
        cout  << number1 * number2;
    }  
    else if (operation == "/") {
        cout  << number1 / number2;
    }
    else {
        cout << "Not a recoganized operation";
    }

    return 0;
}