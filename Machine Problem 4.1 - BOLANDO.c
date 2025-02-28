/* 2024-02813
   Bolando, Karylle Mirzi
   Machine Problem #4.1: Rows and Columns
   Date Due: February 28, 2025 */

   #include <stdio.h>

   int main() {
       int rows, cols;
   
       // Input for rows
       do {
           printf("Enter # of rows: ");
           scanf("%d", &rows);
           if (rows < 1 || rows > 5) {
               printf("Enter only 1-5!\n");
           }
       } while (rows < 1 || rows > 5);
   
       // Input for columns
       do {
           printf("Enter # of columns: ");
           scanf("%d", &cols);
           if (cols < 1 || cols > 5) {
               printf("Enter only 1-5!\n");
           }
       } while (cols < 1 || cols > 5);
   
       int array[rows][cols];
   
       // Taking input for the 2D array
       for (int i = 0; i < rows; i++) {
           for (int j = 0; j < cols; j++) {
               printf("Enter value #%d for row #%d: ", j + 1, i + 1);
               scanf("%d", &array[i][j]);
           }
       }
   
       // Displaying the 2D array
       for (int i = 0; i < rows; i++) {
           for (int j = 0; j < cols; j++) {
               printf("%d ", array[i][j]);
           }
           printf("\n");
       }
   
       // Computing the product of each column
       int product[cols];
       for (int j = 0; j < cols; j++) {
           product[j] = 1; // Initialize product as 1
           for (int i = 0; i < rows; i++) {
               product[j] *= array[i][j];
           }
       }
   
       // Displaying the product of each column
       printf("\nThe products of every column are: ");
       for (int j = 0; j < cols; j++) {
           printf("%d", product[j]);
           if (j < cols - 1) {
               printf(", ");
           }
       }
       printf("\n");
   
       return 0;
   }   
