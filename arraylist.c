/* 
[STUDENT NUMBER HERE]
[YOUR NAME HERE]
CMSC 21 - [YOUR LAB SECTION HERE]
Machine Problem 7.1 - Interactive Array List Program
[DATE OF DEADLINE HERE]
*/

#include <stdio.h>

int main(){
    int choice;

    do{
        printf("HELLO USER!");
        printf("\nPlease Select an Option");
        printf("\n*****************************");
        printf("\n(1) Get Item");
        printf("\n(2) Set Item");
        printf("\n(3) Insert Item");
        printf("\n(4) Remove Item");
        printf("\n(5) Print all items");
        printf("\n(0) Exit");
        printf("\n*****************************");
        printf("\nENTER CHOICE: ");
        scanf("%d", &choice);

        printf("\n*****************************\n\n\n\n");
           
    }while(choice != 0);

    return 0;
}