#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

// Function para malaman kung ang nilagay na operator ay una
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if ang nilagay ay operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Para sa pag dagdag ng operator(para gumana pag may isa pang operator)
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw invalid_argument("Division by zero!");
            return a / b;
    }
    return 0;
}

// Para sa pag sasama ng value at operator 
int evaluateInfix(const string& expression) {
    stack<int> values;      // pag store ng integer values
    stack<char> ops;        // pag store ng operators

    for (size_t i = 0; i < expression.length(); ++i) {
        
        if (isspace(expression[i])) continue;

        if (isdigit(expression[i])) {
            int value = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            values.push(value);
            i--; 
        }
        // If the character is an operator
        else if (isOperator(expression[i])) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(a, b, op));
            }
            ops.push(expression[i]);
        }
    }

    
    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

// Main function
int main() {
    string expression;
    cout << "Enter a number: ";
    getline(cin, expression);

    try {
        int result = evaluateInfix(expression);
        cout << "Result: " << result << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
