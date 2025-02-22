#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

void divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else if (a < b) {
        printf("Result: %.2f\n", (float)a / b); // Decimal result
    } else {
        printf("Result: %d\n", a / b); // Whole number result
    }
}

int main() {
    int option, num1, num2;
    char extra; // To detect unwanted input

    while (1) { // Infinite loop until user picks 5
        printf("\nAno gusto mo:\n");
        printf("(1) Addition\n");
        printf("(2) Subtraction\n");
        printf("(3) Multiplication\n");
        printf("(4) Division\n");
        printf("(5) Or... mahal ko. HUIE (Exit)\n");
        printf("Pili ka: ");

        // Scan input and check if there's unwanted input after the number
        if (scanf("%d%c", &option, &extra) != 2 || extra != '\n') {
            printf("Invalid input. Please enter a single number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (option == 5) {
            printf("AY JOKE HAHAH bye 🏃‍♂️\n");
            break; // Exit the loop
        }

        if (option >= 1 && option <= 4) {
            printf("Enter two numbers: ");
            if (scanf("%d %d%c", &num1, &num2, &extra) != 3 || extra != '\n') {
                printf("Invalid input. Try again.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
        }

        switch (option) {
            case 1:
                printf("Result: %d\n", add(num1, num2));
                break;
            case 2:
                printf("Result: %d\n", sub(num1, num2));
                break;
            case 3:
                printf("Result: %d\n", multiply(num1, num2));
                break;
            case 4:
                divide(num1, num2);
                break;
            default:
                printf("Walang ganun HAHAH\n");
                break;
        }
    }

    return 0;
}