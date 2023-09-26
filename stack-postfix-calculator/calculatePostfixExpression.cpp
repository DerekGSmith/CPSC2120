#include <cstring>
#include <stack>
#include <string>

using namespace std;

// Calculates a postfix expression with integer operands using a stack
// The expression is represented using an array of strings
// Each string is either an operand or operator symbol
// Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
// Example expression: "8", "5", "-" evaluates to a result of 3:
// 1: push 8
// 2: push 5,
// 3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
// The result of the operation (8-5) is 3, push 3 onto stack
// After evaluation of the expression, the final result should be
// the only value on the stack, return 0 if the stack is
// non-empty after popping the result
// Return 0 if expression is zero-length or if there are insufficient operands
// for an operation
// The STL Stack class can be used
// To easily convert a numeric string to an int you may use the stoi() function
// which takes a string as a parameter and returns a string

int isOperator(char o) {
    if ((o == '+') || (o == '-')) {
        return 1;
    } else if ((o == '*') || (o == '/') || (o == '%')) {
        return 2;
    } else {
        return 0;
    }
}

int calculatePostfixExpression(string expression[], int length) {
    stack<char> postfixStack;
    char infixC[2];
    string postfix[length];
    int check, index = 0;
    int left, right;

    for (int i = 0; i < length; i++) {
        // strcpy is used to obtain a char from a one character string.
        // this is done to make comparisons easier and isOperator to work
        strcpy(infixC, expression[i].c_str());

        if (isdigit(infixC[0])) {
            postfixStack.push(infixC[0]);
        }

        else if (isOperator(infixC[0]) > 0) {
            // operator condition , adds operator to stack

            if (postfixStack.empty()) {
                return 0;
            }
            right = postfixStack.top();
            postfixStack.pop();
            if (postfixStack.empty()) {
                return 0;
            }
            left = postfixStack.top();
            postfixStack.pop();

            switch (infixC[0]) {
                case '+':
                    left = left + right;
                    break;
                case '-':
                    left = left - right;
                    break;
                case '*':
                    left = left * right;
                    break;
                case '/':
                    left = left / right;
                    break;
                case '%':
                    left = left % right;
                    break;
            }
            postfixStack.push(left);
        }
    }
    if (postfixStack.size() != 1) {
        return 0;
    } else {
        return postfixStack.top();
    }
}
