/* 
INTERACTIVE ARRAY LIST PROGRAM

Implement an ArrayList program where the user can perform various operations on a list.
Initialize the list before performing any operations.
Refer to the slides or presentation for the implementation of the ArrayList structure (your array will still have a fixed size of 20 for this activity) and essential functions.
Update the implementation of the insertItem function to handle the case when the list is empty and you want to insert the first item.
Additionally, add a function called printList that prints all items from the list, including the empty elements (values on empty elements should be -1). Use this function prototype: void printList(myList* list)
Use the provided code below to display the menu to the user and prompt for their choice:
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

Your task is to compile all the essential functions into one program and integrate the menu system to allow the user to choose the desired operation on the list.

The menu options are as follows:
(1) Get Item: Retrieve an item from the list.
(2) Set/Update Item: Modify an existing item in the list.
(3) Insert new Item: Add a new item to the list.
(4) Remove Item: Delete an item from the list.
(5) Print/Display all Items: Show all items in the list, including the empty elements (display -1 for empty elements).
(0) Exit the Program: Terminate the program.

Refer to the lecture on Array Lists for a sample program flow. If you were absent during this lecture, please send me a message through email or Google Chat to give you a demonstration during consultation hours.
*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

typedef struct {
    int items[SIZE];
    int count;
} myList;

void initializeList(myList *list);
int getItem(myList *list, int index);
void setItem(myList *list, int index, int value);
bool insertItem(myList *list, int index, int value);
bool removeItem(myList *list, int index);
void printList(myList *list);

int main() {
    myList list;
    initializeList(&list);
    int choice, index, value;

    do {
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

        switch (choice) {
            case 1:
                printf("Enter index to retrieve: ");
                scanf("%d", &index);
                printf("Item at index %d: %d\n", index, getItem(&list, index));
                break;
            case 2:
                printf("Enter index to update: ");
                scanf("%d", &index);
                printf("Enter new value: ");
                scanf("%d", &value);
                setItem(&list, index, value);
                break;
            case 3:
                printf("Enter index to insert at: ");
                scanf("%d", &index);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if (insertItem(&list, index, value)) {
                    printf("Item inserted successfully.\n");
                } else {
                    printf("Insertion failed. List might be full or index is invalid.\n");
                }
                break;
            case 4:
                printf("Enter index to remove: ");
                scanf("%d", &index);
                if (removeItem(&list, index)) {
                    printf("Item removed successfully.\n");
                } else {
                    printf("Removal failed. Invalid index.\n");
                }
                break;
            case 5:
                printList(&list);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n*****************************\n\n\n\n");

    } while (choice != 0);

    return 0;
}

void initializeList(myList *list) {
    for (int i = 0; i < SIZE; i++) {
        list->items[i] = -1;
    }
    list->count = 0;
}

int getItem(myList *list, int index) {
    if (index >= 0 && index < list->count) {
        return list->items[index];
    }
    printf("Invalid index.\n");
    return -1;
}

void setItem(myList *list, int index, int value) {
    if (index >= 0 && index < list->count) {
        list->items[index] = value;
    } else {
        printf("Invalid index.\n");
    }
}

bool insertItem(myList *list, int index, int value) {
    if (list->count >= SIZE || index < 0 || index > list->count) {
        return false;
    }
    for (int i = list->count; i > index; i--) {
        list->items[i] = list->items[i - 1];
    }
    list->items[index] = value;
    list->count++;
    return true;
}

bool removeItem(myList *list, int index) {
    if (index < 0 || index >= list->count) {
        return false;
    }
    for (int i = index; i < list->count - 1; i++) {
        list->items[i] = list->items[i + 1];
    }
    list->items[list->count - 1] = -1;
    list->count--;
    return true;
}

void printList(myList *list) {
    printf("List items: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", list->items[i]);
    }
    printf("\n");
}
