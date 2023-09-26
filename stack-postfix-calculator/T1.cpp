#include <cstring>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

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
                    cout << left;
                    break;
                case '-':
                    left = left - right;
                    cout << left;
                    break;
                case '*':
                    left = left * right;
                    cout << left;
                    break;
                case '/':
                    left = left / right;
                    cout << left;
                    break;
                case '%':
                    left = left % right;
                    cout << left;
                    break;
            }
            cout << left;
            postfixStack.push(left);
        }
    }
    if (postfixStack.size() != 1) {
        return 0;
    } else {
        return postfixStack.top();
    }
}
int main() {
    string exp[] = {"4", "5", "*"};

    // ASSERT_EQ(calculatePostfixExpression(exp,3), 20);
    if (calculatePostfixExpression(exp, 3) != 20) {
        cout << "expected/correct value 20, actual value when testing "
             << calculatePostfixExpression(exp, 3) << ".\n";
        return 1;
    }
    cout << "Passed" << endl;
    return 0;
}