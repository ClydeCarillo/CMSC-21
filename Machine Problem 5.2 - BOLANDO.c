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
