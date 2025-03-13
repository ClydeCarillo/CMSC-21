/*
Implement a program that sorts the elements of an array in ascending order.

Have an array of size 10 and enter the values for each of its elements.
Then, create a void function that will be used to sort the values of the array in ascending order.

Display the sorted array in the output.

The use of any [ ] in the code is PROHIBITED, except to initialize an array. Use pointers and pointer arithmetic instead.


SAMPLE

Input:     98 67 34 89 -23 83 -9 27 11 10
Output:  -23 -9 10 11 27 34 67 83 89 98

Input:     1 0 2 9 3 8 4 7 5 6
Output: 0 1 2 3 4 5 6 7 8 9
*/

#include <stdio.h>

void sortArray(int *arr, int size) {
    int *i, *j, temp;

    for (i = arr; i < arr + size - 1; i++) {
        for (j = i + 1; j < arr + size; j++) {
            if (*i > *j) {
                temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

int main() {
    int arr[10];
    int *ptr = arr;

    for (int i = 0; i < 10; i++) {
        scanf("%d", ptr + i);
    }

    sortArray(arr, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}
