#include <cstring>
#include <iostream>
#include <stack>
#include <string>

#include "calculatePostfixExpression.cpp"

using namespace std;

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