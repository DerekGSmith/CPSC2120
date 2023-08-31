#include "review.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void ReadStdIn() {
    int i;
    double d;
    string s, input;
    getline(cin, input);
    stringstream stream(input);
    stream >> i >> d >> s;
    cout << i << endl;
    cout << d << endl;
    cout << s;
}