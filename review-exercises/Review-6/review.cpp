#include "review.h"

void LoopThrough(double* data, int size) {
    int i = 0;
    while (i < size) {
        data[i] += 1;
        i++;
    }
}