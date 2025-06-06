/* 2024-02813
   Bolando, Karylle Mirzi
   Machine Problem #2.2: Relatively Primality
   Date Due: February 11, 2025 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Recursive function for division
int recursive_division(int A, int B, int count) {
    if (A < B) return count;
    return recursive_division(A - B, B, count + 1);
}

// Recursive function for greatest common denominator (GCD)
int gcd(int A, int B) {
    if (B == 0) return A; // GCD(A, 0) is A
    return gcd(B, A - B * recursive_division(A, B, 0));
}

int main() {
    int choice, A, B;
    char input[20];
    while (fgets(input, sizeof(input), stdin)) {
        for (int i = 0; input[i]; i++) input[i] = tolower(input[i]); // Convert input to lowercase to accept uppercase and lowercase letters
        if (sscanf(input, "item %d: %d %d", &choice, &A, &B) == 3) {
            if (choice == 1) {
                printf("%d\n", recursive_division(A, B, 0));
            } else if (choice == 2) {
                printf("%d\n", (gcd(A, B) == 1) ? 1 : 0);
            }
        }
    }
    return 0;
}
