/* 2024-02813
   Bolando, Karylle Mirzi
   Mastery Exam
   Date Due: May 23, 2025 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 64

typedef struct Student {
    char student_number[MAX_LEN];
    char last_name[MAX_LEN];
    char first_name[MAX_LEN];
    char course[MAX_LEN];
    int year_level;
    int age;
    char sex[MAX_LEN];
    int final_grade;
    struct Student *next;
} Student;

Student *head = NULL;

void trim_newline(char *str) {
    str[strcspn(str, "\n")] = 0;
}

void input_string(const char *prompt, char *buffer) {
    char temp[MAX_LEN];
    int valid;
    do {
        valid = 1;
        printf("%s", prompt);
        fgets(temp, MAX_LEN, stdin);
        trim_newline(temp);

        if (strlen(temp) > 15) {
            printf("Input must be at most 15 characters.\n");
            valid = 0;
        } else {
            for (int i = 0; temp[i]; i++) {
                if (isspace((unsigned char)temp[i])) {
                    printf("Input must not contain spaces.\n");
                    valid = 0;
                    break;
                }
            }
        }
    } while (!valid);

    strcpy(buffer, temp);
}

int input_integer(const char *prompt) {
    char line[32];
    int value, success;
    do {
        printf("%s", prompt);
        if (!fgets(line, sizeof(line), stdin)) {
            printf("Input error. Try again.\n");
            success = 0;
            continue;
        }
        success = sscanf(line, "%d", &value);
        if (!success) {
            printf("Invalid input. Please enter a number.\n");
        }
    } while (!success);
    return value;
}

int input_grade(const char *prompt) {
    int grade;
    do {
        grade = input_integer(prompt);
        if (grade < 0 || grade > 100) {
            printf("Grade must be between 0 and 100.\n");
        }
    } while (grade < 0 || grade > 100);
    return grade;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

Student* find_student_by_number(const char *number) {
    Student *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->student_number, number) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

void enrol_student() {
    Student *new_student = (Student *)malloc(sizeof(Student));
    input_string("Enter student number (e.g., 2024-0001): ", new_student->student_number);

    if (find_student_by_number(new_student->student_number)) {
        printf("Student already exists!\n");
        free(new_student);
        return;
    }

    input_string("Enter last name: ", new_student->last_name);
    input_string("Enter first name: ", new_student->first_name);
    input_string("Enter course: ", new_student->course);
    new_student->year_level = input_integer("Enter year level: ");
    new_student->age = input_integer("Enter age: ");
    input_string("Enter sex: ", new_student->sex);
    new_student->final_grade = input_grade("Enter final grade (0-100): ");

    new_student->next = head;
    head = new_student;
    printf("Student enrolled successfully!\n");
}

void drop_student() {
    char number[MAX_LEN];
    input_string("Enter student number to drop: ", number);

    Student *temp = head, *prev = NULL;
    while (temp != NULL && strcmp(temp->student_number, number) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Student not found.\n");
        return;
    }

    if (!prev) head = temp->next;
    else prev->next = temp->next;

    free(temp);
    printf("Student dropped successfully.\n");
}

void edit_student() {
    char number[MAX_LEN];
    input_string("Enter student number to edit: ", number);

    Student *student = find_student_by_number(number);
    if (!student) {
        printf("Student not found.\n");
        return;
    }

    int choice;
    do {
        printf("\nEdit Menu:\n");
        printf("1. Last name\n2. First name\n3. Course\n4. Year level\n5. Age\n6. Sex\n7. Final grade\n8. Done\n? ");
        choice = input_integer("");
        switch (choice) {
            case 1: input_string("Enter new last name: ", student->last_name); break;
            case 2: input_string("Enter new first name: ", student->first_name); break;
            case 3: input_string("Enter new course: ", student->course); break;
            case 4: student->year_level = input_integer("Enter new year level: "); break;
            case 5: student->age = input_integer("Enter new age: "); break;
            case 6: input_string("Enter new sex: ", student->sex); break;
            case 7: student->final_grade = input_grade("Enter new final grade (0-100): "); break;
        }
    } while (choice != 8);

    printf("Student updated successfully!\n");
}

void display_header() {
    printf("+----------------+--------------+-------------+-------------------+------+-----+-----+--------+\n");
    printf("| STUDENT NUMBER | LAST NAME    | FIRST NAME  | COURSE            | YEAR | AGE | SEX | GRADE  |\n");
    printf("+----------------+--------------+-------------+-------------------+------+-----+-----+--------+\n");
}

void display_student(Student *s) {
    printf("| %-14s | %-12s | %-11s | %-17s | %-4d | %-3d | %-3s | %-6d |\n",
        s->student_number, s->last_name, s->first_name, s->course,
        s->year_level, s->age, s->sex, s->final_grade);
}

void display_footer() {
    printf("+----------------+--------------+-------------+-------------------+------+-----+-----+--------+\n");
}

Student* sorted_insert(Student *sorted, Student *node) {
    if (!sorted || strcmp(node->student_number, sorted->student_number) < 0) {
        node->next = sorted;
        return node;
    }
    Student *curr = sorted;
    while (curr->next && strcmp(curr->next->student_number, node->student_number) < 0) {
        curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
    return sorted;
}

void display_sorted(Student *filtered) {
    Student *sorted = NULL;
    while (filtered) {
        Student *next = filtered->next;
        filtered->next = NULL;
        sorted = sorted_insert(sorted, filtered);
        filtered = next;
    }
    display_header();
    while (sorted) {
        display_student(sorted);
        Student *next = sorted->next;
        free(sorted);
        sorted = next;
    }
    display_footer();
}

void display_all() {
    Student *temp = head, *copies = NULL;
    while (temp) {
        Student *copy = malloc(sizeof(Student));
        *copy = *temp;
        copy->next = copies;
        copies = copy;
        temp = temp->next;
    }
    if (copies) display_sorted(copies);
    else printf("No students to display.\n");
}

void filter_by_string_partial(const char *label, char *(*getter)(Student *)) {
    char val[MAX_LEN];
    input_string(label, val);
    to_lowercase(val);

    Student *temp = head, *matches = NULL;
    while (temp) {
        char *field = getter(temp);
        char field_lower[MAX_LEN];
        strncpy(field_lower, field, MAX_LEN);
        to_lowercase(field_lower);

        if (strstr(field_lower, val)) {
            Student *copy = malloc(sizeof(Student));
            *copy = *temp;
            copy->next = matches;
            matches = copy;
        }
        temp = temp->next;
    }

    if (matches) display_sorted(matches);
    else printf("No matching students found.\n");
}

char* get_last_name(Student *s) { return s->last_name; }
char* get_student_number(Student *s) { return s->student_number; }
char* get_course(Student *s) { return s->course; }
char* get_sex(Student *s) { return s->sex; }

void filter_by_int(const char *label, int (*getter)(Student *)) {
    int val = input_integer(label);
    Student *temp = head, *matches = NULL;
    while (temp) {
        if (getter(temp) == val) {
            Student *copy = malloc(sizeof(Student));
            *copy = *temp;
            copy->next = matches;
            matches = copy;
        }
        temp = temp->next;
    }
    if (matches) display_sorted(matches);
    else printf("No matching students found.\n");
}

int get_year(Student *s) { return s->year_level; }

void filter_by_passing(int passing) {
    Student *temp = head, *matches = NULL;
    while (temp) {
        if ((passing && temp->final_grade >= 60) || (!passing && temp->final_grade < 60)) {
            Student *copy = malloc(sizeof(Student));
            *copy = *temp;
            copy->next = matches;
            matches = copy;
        }
        temp = temp->next;
    }
    if (matches) display_sorted(matches);
    else printf("No matching students found.\n");
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Enrol a student\n2. Drop a student\n3. Edit a student\n4. Display all students\n");
        printf("5. Filter by last name\n6. Filter by student number\n7. Filter by year level\n8. Filter by course\n9. Filter by sex\n");
        printf("10. Filter by passing\n11. Filter by failing\n12. Exit\n? ");
        choice = input_integer("");
        switch (choice) {
            case 1: enrol_student(); break;
            case 2: drop_student(); break;
            case 3: edit_student(); break;
            case 4: display_all(); break;
            case 5: filter_by_string_partial("Enter last name: ", get_last_name); break;
            case 6: filter_by_string_partial("Enter student number: ", get_student_number); break;
            case 7: filter_by_int("Enter year level: ", get_year); break;
            case 8: filter_by_string_partial("Enter course: ", get_course); break;
            case 9: filter_by_string_partial("Enter sex: ", get_sex); break;
            case 10: filter_by_passing(1); break;
            case 11: filter_by_passing(0); break;
        }
    } while (choice != 12);

    while (head) {
        Student *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}