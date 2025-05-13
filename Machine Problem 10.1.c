#include <stdio.h>
#include <stdlib.h>

struct Record {
    int account;
    char name[21];
    double balance;
};

typedef struct Record Record;

// Function to display a single account record based on account number
void displayAccount(const char* filename, int accountNumber) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    Record r;
    fseek(fp, sizeof(Record) * (accountNumber - 1), SEEK_SET);
    if (fread(&r, sizeof(Record), 1, fp) == 1 && r.account != 0) {
        printf("\nAccount Found:\n");
        printf("Account No: %d\nName: %s\nBalance: %.2lf\n", r.account, r.name, r.balance);
    } else {
        printf("\nAccount %d not found or empty.\n", accountNumber);
    }

    fclose(fp);
}

// Function to display all account records
void listAllAccounts(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    Record r;
    printf("\n%-12s %-20s %-10s\n", "Account No", "Name", "Balance");
    while (fread(&r, sizeof(Record), 1, fp) == 1) {
        if (r.account != 0) {
            printf("%-12d %-20s %.2lf\n", r.account, r.name, r.balance);
        }
    }

    fclose(fp);
}

int main() {
    FILE* fp = fopen("data.bin", "wb");
    if (!fp) {
        printf("Oh no, an error occurred!\n");
        return -1;
    }

    Record r;
    printf("Enter account number 1 - 100 (0 to exit)\n? ");
    scanf("%i", &r.account);

    while (r.account > 0 && r.account <= 100) {
        printf("Enter name and balance\n? ");
        scanf("%s %lf", r.name, &r.balance);
        fseek(fp, sizeof(Record) * (r.account - 1), SEEK_SET);
        fwrite(&r, sizeof(Record), 1, fp);

        printf("Enter account number 1 - 100 (0 to exit)\n? ");
        scanf("%i", &r.account);
    }

    fclose(fp);

    int choice, accNum;
    do {
        printf("\nMenu:\n1. Display specific account\n2. List all accounts\n3. Exit\nChoose: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &accNum);
                if (accNum > 0 && accNum <= 100)
                    displayAccount("data.bin", accNum);
                else
                    printf("Invalid account number.\n");
                break;
            case 2:
                listAllAccounts("data.bin");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}
