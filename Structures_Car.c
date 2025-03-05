/* 
Engine: DDis 190 Engine
Fuel Type: Petrol
Fuel Tank Capacity: 37
Seating Capacity: 5
City Mileage: 19.74 kmpl
*/

#include <stdio.h>
	
	struct Car {  // this groups all car-related attributes together
	    char *engine;
	    char *fuelType;
	    int fuelCap;
	    int seatingCap;
	    float cityMileage;
	};
	
	int main() {
	    // each car is now a single variable instead of multiple separate ones
	    struct Car car1 = {"DDis 190 Engine", "Petrol", 37, 5, 19.74};
	    struct Car car2 = {"1.2 L Kappa Dual VTVT", "Diesel", 35, 5, 22.54};
	
	    // the dot . operator is used to access structure members
	    printf("Car 1 Engine: %s\n", car1.engine);
	    printf("Car 1 Fuel Type: %s\n", car1.fuelType);
	    printf("Car 1 Fuel Tank Capacity: %d liters \n", car1.fuelCap);
	    printf("Car 1 Seating Capacity: %d persons\n", car1.seatingCap);
	    printf("Car 1 City Mileage: %.2f km/l\n\n", car1.cityMileage);
	
	    printf("Car 2 Engine: %s\n", car2.engine);
	    printf("Car 2 Fuel Type: %s\n", car2.fuelType);
	    printf("Car 2 Fuel Tank Capacity: %d liters\n", car2.fuelCap);
	    printf("Car 2 Seating Capacity: %d persons\n", car2.seatingCap);
	    printf("Car 2 City Mileage: %.2f km/l\n", car2.cityMileage);
	
	    return 0;
	}



char *car1Engine = "DDis 190 Engine";
char *car1fuelType = "Petrol";
int car1fuelCap = 37;
int car1seatingCap = 5;
float car1CityMileage = 19.74;



char *car2Engine = "1.2 L Kappa Dual VTVT";
char *car2fuelType = "Diesel";
int car2fuelCap = 35;
int car2seatingCap = 5;
float car2CityMileage = 22.54;

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
