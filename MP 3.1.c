/* 2024-02813
   Bolando, Karylle Mirzi
   Machine Problem #3.1: Day of the Week
   Date Due: February 21, 2025 */


   #include <stdio.h>

   // Check if a year is a leap year
   int isLeapYear(int year) {
       return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
   }
   
   // Get the day number of the year
   int dayOfYear(int year, int month, int day) {
       int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
       if (isLeapYear(year)) daysInMonth[1] = 29;
   
       int dayNum = day;
       for (int i = 0; i < month - 1; i++) {
           dayNum += daysInMonth[i];
       }
       return dayNum;
   }
   
   // Get the weekday (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
   int getWeekday(int year, int month, int day) {
       int firstDay = (1 + 5 * ((year - 1) % 4) + 4 * ((year - 1) % 100) + 6 * ((year - 1) % 400)) % 7;
       return (firstDay + dayOfYear(year, month, day) - 1) % 7;
   }
   
   // Get the correct suffix for the day number
   const char* getSuffix(int dayNum) {
       if (dayNum % 10 == 1 && dayNum % 100 != 11) return "st";
       if (dayNum % 10 == 2 && dayNum % 100 != 12) return "nd";
       if (dayNum % 10 == 3 && dayNum % 100 != 13) return "rd";
       return "th";
   }
   
   int main() {
       int year, month, day;
       printf("Enter date (YYYY MM DD): ");
       scanf("%d %d %d", &year, &month, &day);
   
       if (year < 1 || year > 2025 || month < 1 || month > 12 || day < 1 || day > 31) {
           printf("Invalid date.\n");
           return 1;
       }
   
       char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
       int dayNum = dayOfYear(year, month, day);
       
       printf("%s, %d%s day of the year\n", weekdays[getWeekday(year, month, day)], dayNum, getSuffix(dayNum));
   
       return 0;
   }   
