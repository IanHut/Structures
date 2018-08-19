// Filename: Structures.c
//
// These are notes and sandbox code for the CS50 2018 Week 4 short video
// entitled "Structures".
//
// Date: 08/18/2018
//
// Name: Ian Hutcheson
//
// IDE: Microsoft Visual Studio 2017



#include <stdio.h>

int main(void) {
	// Structures are just user defined data types

	// Can hold variables of different data type under one new user created type
	// Arrays -> only data of the same type
	// Structures -> can group together elements of a variety of data
	// "Super-variable"
	// Student: might have a name, student ID, GPA, etc.

	struct car
	{
		int year;
		char model[10];
		char plate[7];
		int odometer;
		double engine_size;
	}; // <--- need semi-colon at the end!

	// usually define these near the top next to our includes
	// or just create a separate header file and #include it

	// variable declaration (static example, stack)
	struct car myCar;

	// use the dot operator to access the members of the structure
	myCar.year = 2016;
	myCar.odometer = 50505;
	strcpy(myCar.plate, "7YXC401"); // can't just assign a string, have to 'copy' it into the variable
	myCar.engine_size = 11.0;

	// structures (like all variables) do not need to be created on the stack,
	//     we can dynamically allocate structures at run time if our program requires it
	// use pointers!
	// deference the pointer to the structure, then access its fields

	// variable declaration (dynamic example, heap)
	struct car *yourCar = malloc(sizeof(struct car));
	// declare yourCar, point to its address, and at that address allocate enough
	//     memory to hold the size of a 'car' structure

	// field accessing, use dereference operator in conjunction with dot operator
	(*yourCar).year = 2011;
	strcpy((*yourCar).plate, "8UXN039");
	(*yourCar).odometer = 101094;
	// this is tedious, so theres a short cut... use the arrow operator

	// Arrow operator (->)
	// 1. dereferences the pointer on the left side of the arrow
	// 2. access the field on the right side of the arrow
	yourCar->year = 2011;
	strcpy(yourCar->plate, "8UXN039");
	yourCar->odometer = 101094;
	// arrow operator accesses the field of structure to which you only have its pointer

	// befriend and get used to this syntax

	// Create test structure
	struct myInfo {
		char* firstName;
		char* lastName;
		int age;
		double weight;
		int height;
	};

	struct myInfo ianInfo;
	ianInfo.age = 30;
	ianInfo.firstName = "Ian";
	ianInfo.lastName = "Hut";
	ianInfo.weight = 198.8;
	ianInfo.height = 68;

	printf("size of myInfo structure is: %d\n", sizeof(struct myInfo));
	printf("Ian's age is: %d years old\n", ianInfo.age);
	printf("Ian's weight is: %.1f pounds\n", ianInfo.weight);
	printf("Ian's height is: %d inches\n", ianInfo.height);


	// Cannot access the elements in a structure via bracket notation
	// ianInfo[0] = 25;
	// ^^ Illegal

	//***** Defining Custom Data Types *****//
	// Rather than typing the struct keyword every time, you can simply typedef
	// and assign it an alias
	// Usage: typedef <oldname> <newname>;
	// ex. typedef char* string;
	// that's in the CS50 library
	// structures have a two word type name, really annoying
	// ex. struct myInfo <variable name>

	// Type define the structure
	// typedef struct myInfo my_info;
	// my_info; is now legal
	// can also do it in the initial structure definition
	// ex. typedef struct car {
	//         ....
	//     }
	//     my_car;   <---- note the semicolon

	return;
}