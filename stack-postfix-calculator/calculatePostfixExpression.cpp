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
int isOperator(char);

int calculatePostfixExpression(string expression[], int length) {
    stack<string> operators;
    char infixC[2], temp;
    char tempC[2];
    int rightP = 0, leftP = 0, check, index = 0;

    // exiting program if unequal parenthesis are detected
    for (int i = 0; i < length; i++) {
        if (rightP > leftP) {
            return 0;
        } else if (infix[i] == "(") {
            leftP++;
        } else if (infix[i] == ")") {
            rightP++;
        }
    }
    if (rightP != leftP) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        // strcpy is used to obtain a char from a one character string.
        // this is done to make comparisons easier and isOperator to work
        strcpy(infixC, infix[i].c_str());
    }

    int isOperator(char o) {
        if ((o == '+') || (o == '-')) {
            return 1;
        } else if ((o == '*') || (o == '/') || (o == '%')) {
            return 2;
        } else {
            return 0;
        }
    }