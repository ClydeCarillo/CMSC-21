#include <stdio.h>

// This is the recursion function
int power(int base, int exponent) {
    if (exponent == 1) {
        return base; // base^1 = base
    }
    return base * power(base, exponent - 1); // Recursion step
}

int main() {
    int base, exponent;
    
    printf("input: ");
    scanf("%d %d", &base, &exponent);
    
    // Verification
    if (exponent < 1) {
        printf("Exponent must be greater than or equal to 1.\n");
        return 1;
    }
    
    printf("output: %d\n", power(base, exponent));
    
    return 0;
}
