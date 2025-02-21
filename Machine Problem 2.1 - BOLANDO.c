/* 2024-02813
   Bolando, Karylle Mirzi
   Machine Problem #2.1: StdDev()
   Date Due: February 7, 2025 */

#include <stdio.h>
#include <math.h>

// Function to calculate the mean
float Mean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum / size;
}

// Function to calculate the standard deviation
float StdDev(int arr[], int size) {
    float mean = Mean(arr, size);  // Call Mean() to get the mean
    float sum_squared_diff = 0.0;
    for (int i = 0; i < size; i++) {
        sum_squared_diff += (arr[i] - mean) * (arr[i] - mean);
    }
    return sqrt(sum_squared_diff / size);  // Population standard deviation formula
}

// Function to print the results
void PrintResults(int arr[], int size, float mean, float std_dev) {
    printf("\nOriginal array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nMean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", std_dev);
}

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Validate input size
    if (size <= 0) {
        printf("Invalid size. The number of elements must be greater than 0.\n");
        return 1;
    }

    int arr[size];

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate mean and standard deviation
    float mean = Mean(arr, size);
    float std_dev = StdDev(arr, size);

    // Print the results
    PrintResults(arr, size, mean, std_dev);

    return 0;
}