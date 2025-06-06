/*
Prompt the user to enter a string or phrase. Then, your task is to reverse that string.
If the string entered is "Hello world" and this is stored in an identifier str, printing str should display "dlrow olleH".

Use void pointers in pointing to the addresses of the characters of the string, and do casting in order to access and modify the elements of the string array. Lastly, implement everything in the main function only.

Accepting spaces in the string
Since scanf("%s", ...); will stop reading input on seeing a space, and thus only reading a single word, you should use the following format: scanf("%69[^\n]", ...);. This format means scanf will accept 69 characters except the \n character. When the newline character is seen, scanf will end.

Start your code with this:

#include <stdio.h>
#include <string.h>

int main() {

char str[100], temp;

return 0;

}
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp;

    scanf("%99[^\n]", str);

    int length = strlen(str);
    void *start = str;
    void *end = str + length - 1;

    while (start < end) {
        temp = *(char *)start;
        *(char *)start = *(char *)end;
        *(char *)end = temp;

        start = (char *)start + 1;
        end = (char *)end - 1;
    }

    printf("%s\n", str);

    return 0;
}
