// 2024-02183 
// KARYLLE MIRZI BOLANDO
// CMSC 21 - E1
// Machine Problem 8.1 (Modified to Linked List)
// April 22, 2025

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int count;
} myList;

void initializeList(myList *list);
int getItem(myList *list, int index);
void setItem(myList *list, int index, int value);
bool insertItem(myList *list, int index, int value);
bool removeItem(myList *list, int index);
void printList(myList *list);
void freeList(myList *list);

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
                printf("List contents: ");
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

    freeList(&list);
    return 0;
}

void initializeList(myList *list) {
    list->head = NULL;
    list->count = 0;
}

int getItem(myList *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid index.\n");
        return -1;
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

void setItem(myList *list, int index, int value) {
    if (index < 0 || index >= list->count) {
        printf("Invalid index.\n");
        return;
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->value = value;
    printf("Item at index %d set to %d\n", index, value);
}

bool insertItem(myList *list, int index, int value) {
    if (index < 0 || index > list->count) {
        return false;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node *prev = list->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }

    list->count++;
    return true;
}

bool removeItem(myList *list, int index) {
    if (index < 0 || index >= list->count) {
        return false;
    }

    Node *toDelete;

    if (index == 0) {
        toDelete = list->head;
        list->head = list->head->next;
    } else {
        Node *prev = list->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        toDelete = prev->next;
        prev->next = toDelete->next;
    }

    free(toDelete);
    list->count--;
    return true;
}

void printList(myList *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void freeList(myList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->head = NULL;
    list->count = 0;
}
