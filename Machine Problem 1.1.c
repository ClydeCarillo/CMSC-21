/*
Name: Karylle Mirzi Bolando
Course: CMSC 21 - E
Date: January 21, 2025

Description:

Ask the user to enter a string. Determine whether the string is a hexadecimal string.
A string is said to be hexadecimal if and only if it contains the digits from ‘0’ - ‘9’ and
the letters from ‘A’ - ‘F’. If the input string is "123", "ABC", or "129FFB", then it is a hexadecimal string.
If the user enters "-123", "FFG", "abcff", or "123ec", then these are not hexadecimal strings.
For this problem, we consider the uppercase letters 'A' - 'F', only as defined above.

If the input value is hexadecimal, print HEXADECIMAL! and if not, print NOT HEXADECIMAL!
*/


#include <stdio.h>

int main() {
    char str[100];
    int i = 0, isHexadecimal = 1;

    // Ask the user to enter a string
    printf("Enter a string: ");
    scanf("%s", str);

    // Check each character in the string
    while (str[i] != '\0') {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))) {
            isHexadecimal = 0; // Not a hexadecimal string
            break;
        }
        i++;
    }

    // Print the result
    if (isHexadecimal) {
        printf("HEXADECIMAL!\n");
    } else {
        printf("NOT HEXADECIMAL!\n");
    }

    return 0;
}


/*  
#include <stdio.h>


isHexadecimal() {
    
}

int main() {
    char str[100];
    int i = 0, isHexadecimal = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F')) {
            i++;
        } else {
            isHexadecimal = 0;
            break;
        }
    }

    if (isHexadecimal) {
        printf("HEXADECIMAL!\n");
    } else {
        printf("NOT HEXADECIMAL!\n");
    }

    return 0;
}

*/