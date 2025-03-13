/*
Implement a program that swaps two numbers using call-by-reference.

Ask the user to enter two numbers to be stored on variables num1 and num2 respectively by following this format "%d %d".
Then, call a void function swap() to do the swapping of those numbers. 
num1 will now have the value of num2 and vice-versa.

Lastly, display the result of their swap in the main function.
Follow this exact string to avoid errors when evaluating your code:
"num1 = %d \nnum2 = %d"


SAMPLE

Input:     34 89
Output: num1 = 89
               num2 = 34

Input:     -92 44
Output: num1 = 44
               num2 = -92
*/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    swap(&num1, &num2);
    printf("num1 = %d \nnum2 = %d\n", num1, num2);

    return 0;
}
