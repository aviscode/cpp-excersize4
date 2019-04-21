/*
File: main.cpp
Description: This is the main file of the program.
Course: 150018 C++ Workshop,
Exercise 4, Question 2
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#include <iomanip>
#include<iostream>
#include"vector.h"

using namespace std;

enum MenuOption
{
	EXIT_MENU,
	INPUT_TO_VECTOR,
	CHECK_EQUALITY,
	PRINT_MULT_OF_TOW_FIRST_VECTORS,
	POSTING_FIRST_VECTOR_IN_THE_THIRD,
	POSTING_SUM_OF_TOW_VECTORS_IN_THE_THIRD,
	CLEAR_CONTENT_OF_VECTOR,
	DELETE_LAST_PLACE_IN_VECTOR,
	PRINT_ALL_VECTORS,

	FIRST_MENU_OPTION = EXIT_MENU,
	LAST_MENU_OPTION = PRINT_ALL_VECTORS,
};


const char * const menuOptionStrings[] =
{
	"Exit the program",
	"Input content to a vector",
	"Check if the first vector equal to second",
	"Print the mult of the first vector whit the second",
	"Posting the first vector in the third",
	"Posting the sum of tow vectors in the third",
	"Clear the contsnt of the vector. (1 or 2)",
	"Delete the last place from the vector (1 or 2)",
	"Print all vectors",
};

// Function main - this is the entry code for the program
// It prints menu and performs the action according to the chosen option.
int main(void)
{
	Vector v1(9), v2(9), v3;  //set 3 vectors
	MenuOption chosen;

	do {
		cout << endl << "Menu options:" << endl << endl;

		const int menuIndent = 10;


		for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION;
			chosen = (MenuOption)((int)chosen + 1)) {
			cout << setw(menuIndent) << " " << chosen << " -- ";
			cout << menuOptionStrings[chosen] << endl;
		}
		cout << endl;

		int chosenInt, chosenV = 0;
		cout << "Please choose a menu option: ";
		cin >> chosenInt;
		chosen = (MenuOption)chosenInt;


		switch (chosen) {
		case EXIT_MENU:
			// adios
			cout << "Thanx for using Vectors Management Program !" << endl;
			break;
		case INPUT_TO_VECTOR: {		//case set values
			int size, value;
			cout << "Please select which vector to enter values : (1 OR 2)\n";
			cin >> chosenV;
			while (chosenV != 1 && chosenV != 2) {		//gets vctor 1 or 2 
				cout << "ERROR Enter 1 OR 2\n";
				cin >> chosenV;
			}
			if (chosenV == 1) {
				cout << "How many values do you want to insert into the vector ? (smaller than " << v1.getCapacity() << ") :";
				cin >> size;
				while (v1.getCapacity() < size) {		//gets the size of the vector
					cout << "ERROR the size is too big \n";
					cin >> size;
				}
				v1.setSize(size);
				cout << "Enter the values\n";
				for (uint i = 0; i < size; ++i)
					cin >> v1[i];
			}
			else {
				cout << "How many values do you want to insert into the vector ? (smaller than " << v2.getCapacity() << ") : ";
				cin >> size;
				while (v2.getCapacity() < size) {		//gets the size of the vector
					cout << "ERROR the size is too big \n";
					cin >> size;
				}
				v2.setSize(size);
				cout << "Enter the values\n";
				for (uint i = 0; i < size; ++i)
					cin >> v2[i];
			}
			break;
		}
		case CHECK_EQUALITY:		//case checkig if 2 vectors eqals
			if (v1 == v2)
				cout << "vector v1 is eqal to vectoe v2\n";
			else
				cout << "vector v1 is not eqal to vector v2\n";
			break;
		case PRINT_MULT_OF_TOW_FIRST_VECTORS:
			try {
				int*sum = v1 * v2;
				for (uint i = 0; i < v1.getSize(); ++i)
					cout << sum[i] << " ";
				cout << endl;
				delete[]sum;
			}
			catch (IndexException *temp) {
				cout << "The size of v1 : " << temp->index << " is not eqal to size of v2 the size of v2  : " << temp->maxIndex << ")\n";
			}
			break;
		case POSTING_FIRST_VECTOR_IN_THE_THIRD:		//copying the first vectoe in the third vector	
			v3 = v1;
			cout << v3;
			break;
		case POSTING_SUM_OF_TOW_VECTORS_IN_THE_THIRD:		//seting the sum of 2 vectors in the third vector
			v3 = v1 + v2;
			cout << v3;
			break;
		case CLEAR_CONTENT_OF_VECTOR:		//clear a vector 
			cout << "Please select which vector you will like clear : (1 OR 2)\n";
			cin >> chosenV;
			while (chosenV != 1 && chosenV != 2)
			{
				cout << "ERROR Enter 1 OR 2\n";
				cin >> chosenV;
			}
			if (chosenV == 1) {
				v1.clear();
				cout << v1;
			}
			else {
				v2.clear();
				cout << v2;
			}

			break;
		case DELETE_LAST_PLACE_IN_VECTOR: {		//delete a last value in a vector
			cout << "Please select which vector you will like to delete the last value : (1 OR 2)\n";
			cin >> chosenV;
			while (chosenV != 1 && chosenV != 2)		//gets the size of the vector
			{
				cout << "ERROR Enter 1 OR 2\n";
				cin >> chosenV;
			}
			if (chosenV == 1) {
				try {
					v1.delLast();
					cout << v1;
				}
				catch (int size) {
					cout << "The vector is empty\n";
				}
			}
			else {
				try {
					v2.delLast();
					cout << v2;
				}
				catch (int size) {
					cout << "The vector is empty\n";
				}
			}
			break;
		}
		case PRINT_ALL_VECTORS:		//case of printing all vectors
			cout << v1;
			cout << v2;
			cout << v3;
			break;
		}
	} while (chosen != EXIT_MENU);

	return 0;
}