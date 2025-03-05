/* 
Questions (datatype):
Relationship status (char *)
Which school they graduated in senior high (char *)
Height (in feet/inches) (float)
Zodiac sign (can be western of Chinese) (char *)
Name of pet (char *)
Favorite subject in high school (char *)
Favorite color (char *)
Favorite food (char *)
Favorite drink (char *)
Favorite book (char *)
Dream destination (char *)
Lights on or lights off? (int/bool)
iPhone or Android? (int/bool)
Kapuso o Kapamilya? (int/bool)
Mahal ka or mahal mo? (int/bool)
Make love or send choclates? (int/bool)
Motto in life (char *)
*/

#include <stdio.h>
#include <stdbool.h>  // Include this to use bool in C
struct Slumbook {
    char *favorite_book;
    bool mahal_ka_or_mahal_mo;
    char *name_of_pet;
    char *dream_destination;
    bool iphone_or_android;
    bool make_love_or_send_chocolates;
    bool lights_on_or_lights_off;
    char *motto_in_life;
    char *zodiac_sign;
    char *relationship_status;
    char *school_graduated;
    float height;
};
// Declare struct variables globally
struct Slumbook response3, response4, response5, response6;
int main() {
    // Assign values correctly
    response3.favorite_book = "Holding up the Universe";
    response3.mahal_ka_or_mahal_mo = 1; // Assuming 1 = "Mahal mo"
    response3.name_of_pet = "Bogie";
    response3.dream_destination = "Korea";
    response3.iphone_or_android = 0; // Assuming 0 = Android
    response4.mahal_ka_or_mahal_mo = 1; 
    response4.make_love_or_send_chocolates = 0;
    response4.motto_in_life = "Never let your anger overpower your gratefulness";
    response4.zodiac_sign = "Scorpio";
    response5.zodiac_sign = "Cancer";
    response5.relationship_status = "Single";
    response5.name_of_pet = "Brax & Muno";
    response5.make_love_or_send_chocolates = 1;
    response5.lights_on_or_lights_off = 0;
    response6.relationship_status = "Complicated";
    response6.school_graduated = "International Academe of EnScieMa";
    response6.favorite_book = "The Hunger Games";
    response6.height = 5.7;
    response6.dream_destination = "Singapore";
    // Print sample output to verify correctness
    printf("Response3 - Favorite Book: %s, Dream Destination: %s\n", response3.favorite_book, response3.dream_destination);
    printf("Response6 - School Graduated: %s, Favorite Book: %s\n", response6.school_graduated, response6.favorite_book);
    return 0;
}
