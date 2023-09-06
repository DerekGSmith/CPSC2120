#include "review.h"

std::vector<int> InitializeArray(int size) {
    std::vector<int> newVector;

    for (int i = 0; i < size; i++) {
        newVector.push_back(0);
    }
    return newVector;
}
