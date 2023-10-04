#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int getPrecedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

string infixToPrefix(const string& infix) {
    stack<char> operators;
    string prefix;

    // Reverse the infix expression
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (char ch : reversedInfix) {
        if (isalnum(ch)) {
            prefix += ch;
        } else if (ch == ')') {
            operators.push(ch);
        } else if (ch == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop the '('
        } else {
            while (!operators.empty() && getPrecedence(ch) < getPrecedence(operators.top())) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }

    // Reverse the prefix expression to get the final result
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}
