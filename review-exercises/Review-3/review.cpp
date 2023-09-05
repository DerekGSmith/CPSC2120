#include "review.h"

#include <iostream>
#include <string>

void ReadStdIn2() {
    int loop = 0;
    std::string input;
    std::cin >> input;
    while (input != "q") {
        std::cin >> input;
        loop++;
    }
    std::cout << loop;
}