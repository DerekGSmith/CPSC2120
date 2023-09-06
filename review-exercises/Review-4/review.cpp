#include "review.h"

void ReadWrite() {
    std::string output;
    std::string input;
    std::cin >> input;
    while (input != "q") {
        output += input;
        output += " ";
        std::cin >> input;
    }
    std::cout << output << std::endl;
}