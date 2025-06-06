/*
(not sure if this is right)

Modify/update your Machine Problem #7.1 from Array Lists to Vectors.
Meaning, you need to change your structure to Vectors (see the Slides for reference).
The program flow and user menu should be the same. Only the implementation of the list using vectors is modified.
However, in printing all items from the list together with the empty elements, the number of elements displayed should be based on the current capacity of your vector list.

Sample Output
Case 1:

input=2
output=HELLO USER!
Please Select an Option
*****************************
(1) Get Item
(2) Set Item
(3) Insert Item
(4) Remove Item
(5) Print all items
(0) Exit
*****************************
ENTER CHOICE: 2
*****************************
Enter index: 0
Enter value: 30
Item at index 0 set to 30
*****************************
Case 2:

input=5
output=HELLO USER!
Please Select an Option
*****************************
(1) Get Item
(2) Set Item
(3) Insert Item
(4) Remove Item
(5) Print all items
(0) Exit
*****************************
ENTER CHOICE: 5
 *****************************
 List contents (capacity: 10): 10 20 -1 -1 -1 -1 -1 -1 -1 -1
 *****************************
*/

// 2024-02183 
// KARYLLE MIRZI BOLANDO
// CMSC 21 - E1
// Machine Problem 8.1
// April 22, 2025

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int *items;
    int count;
    int capacity;
} myList;

void initializeList(myList *list);
int getItem(myList *list, int index);
void setItem(myList *list, int index, int value);
bool insertItem(myList *list, int index, int value);
bool removeItem(myList *list, int index);
void printList(myList *list);
void expandCapacity(myList *list);

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

        printf("\n*****************************\n\n");

        switch (choice) {
            case 1:
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Item at index %d: %d\n", index, getItem(&list, index));
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Enter value: ");
                scanf("%d", &value);
                setItem(&list, index, value);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Enter value: ");
                scanf("%d", &value);
                if (insertItem(&list, index, value)) {
                    printf("Item %d inserted at index %d\n", value, index);
                } else {
                    printf("Insertion failed. Index is invalid.\n");
                }
                break;
            case 4:
                printf("Enter index: ");
                scanf("%d", &index);
                if (removeItem(&list, index)) {
                    printf("Item at index %d removed\n", index);
                } else {
                    printf("Removal failed. Invalid index.\n");
                }
                break;
            case 5:
                printf("List contents (capacity: %d): ", list.capacity);
                printList(&list);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n*****************************\n\n\n\n");

    } while (choice != 0);

    // Free dynamically allocated memory
    free(list.items);
    return 0;
}

void initializeList(myList *list) {
    list->items = (int *)malloc(sizeof(int) * INITIAL_CAPACITY);
    list->capacity = INITIAL_CAPACITY;
    list->count = 0;
    for (int i = 0; i < list->capacity; i++) {
        list->items[i] = -1;
    }
}

void expandCapacity(myList *list) {
    int newCapacity = list->capacity * 2;
    int *newItems = (int *)malloc(sizeof(int) * newCapacity);
    for (int i = 0; i < list->capacity; i++) {
        newItems[i] = list->items[i];
    }
    for (int i = list->capacity; i < newCapacity; i++) {
        newItems[i] = -1;
    }
    free(list->items);
    list->items = newItems;
    list->capacity = newCapacity;
}

int getItem(myList *list, int index) {
    if (index >= 0 && index < list->count) {
        return list->items[index];
    }
    printf("Invalid index.\n");
    return -1;
}

void setItem(myList *list, int index, int value) {
    if (index < 0) {
        printf("Invalid index.\n");
        return;
    }

    while (index >= list->capacity) {
        expandCapacity(list);
    }

    // Only update count if we're writing past the current last item
    if (index >= list->count) {
        for (int i = list->count; i < index; i++) {
            list->items[i] = -1;
        }
        list->count = index + 1;
    }

    list->items[index] = value;
    printf("Item at index %d set to %d\n", index, value);
}

bool insertItem(myList *list, int index, int value) {
    if (index < 0 || index > list->count) {
        return false;
    }

    if (list->count == list->capacity) {
        expandCapacity(list);
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
    for (int i = 0; i < list->capacity; i++) {
        printf("%d ", list->items[i]);
    }
    printf("\n");
}
