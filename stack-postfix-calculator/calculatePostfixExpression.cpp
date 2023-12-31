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

int isOperator(string o) {
    if ((o[0] == '+') || (o[0] == '-')) {
        return 1;
    } else if ((o[0] == '*') || (o[0] == '/') || (o[0] == '%')) {
        return 2;
    } else {
        return 0;
    }
}

int calculatePostfixExpression(string expression[], int length) {
    stack<string> postfixStack;

    for (int i = 0; i < length; i++) {
        string element = expression[i];

        if (isdigit(element[0])) {
            postfixStack.push(element);
        }

        else if (isOperator(element)) {
            if (postfixStack.size() < 2) {
                return 0;
            }

            string rightOperand = postfixStack.top();
            postfixStack.pop();

            string leftOperand = postfixStack.top();
            postfixStack.pop();

            int right = stoi(rightOperand);
            int left = stoi(leftOperand);

            if (element == "+") {
                left = left + right;
            } else if (element == "-") {
                left = left - right;
            } else if (element == "*") {
                left = left * right;
            } else if (element == "/") {
                if (right == 0) {
                    // Division by zero
                    return 0;
                }
                left = left / right;
            } else if (element == "%") {
                if (right == 0) {
                    // Modulus by zero
                    return 0;
                }
                left = left % right;
            }

            postfixStack.push(to_string(left));
        } else {
            // Invalid element in the expression
            return 0;
        }
    }

    if (postfixStack.size() != 1) {
        return 0;
    } else {
        return stoi(postfixStack.top());
    }
}
