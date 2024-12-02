#include <stdio.h>

void fullAdder(int *a, int *b, int *carryIn, int *sum, int *carryOut);

int main() {
    int a = 1;
    int b = 1;
    int carryIn = 1;
    int sum = 0;
    int carryOut = 0;

    fullAdder(&a, &b, &carryIn, &sum, &carryOut);

    return 0;
}

//Full adder
void fullAdder(int *a, int *b, int *carryIn, int *sum, int *carryOut) {
    *sum = (*a ^ *b) ^ *carryIn;
    *carryOut = (*a & *b) | (*carryIn & (*a ^ *b));

    printf("Sum: %d\n", *sum);
    printf("Carry-out: %d\n", *carryOut);
}
