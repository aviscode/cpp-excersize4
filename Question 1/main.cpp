/*
File: main.cpp
Description: This is the main program file .
Course: 150018 C++ Workshop,
Exercise 4, Question 1
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#include<iostream>
#include <iomanip>
#include"string.h"
using namespace std;

enum MenuOption {
	EXIT,
	INSERT_TO_2_AINSTENCE,
	COMPARE,
	INSERT_FUNC,
	SEARCH_WORD_IN_AINSTENCE,
	// a neat trick for for-loop initial and final values
	FIRST_MENU_OPTION = EXIT,
	LAST_MENU_OPTION = SEARCH_WORD_IN_AINSTENCE,

};

// These strings will be seen by the user, on the main menu.They
// must be kept consistent with the operations of menu_option
// above.
const  char* const menuOptionStrings[] = {
	"exit",
	"intput to 2 words to 2 instance of the class" ,
	"compare 2  instance" ,
	"enter an index from which, the second instance word  will be inserted after first instance word" ,
	"search if the second instance word contained in the first instance word ",
};


int main() {
	MenuOption chosen;
	String a, b, c;
	// Everything happens inside of this do-while loop, until the user
	//     has decided to exit (or an error occurs).
	do {
		cout << endl << "Menu options:" << endl << endl;

		const int menuIndent = 10;

		for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION;
			chosen = (MenuOption)((int)chosen + 1)) {
			cout << setw(menuIndent) << " " << setw(2) << chosen << " -- ";
			cout << menuOptionStrings[chosen] << endl;
		}
		cout << endl;
		cout << "Please choose a menu option: ";
		float chosenInt;
		cin >> chosenInt;
		chosen = (MenuOption)((int)chosenInt);

		switch (chosen) {
		case INSERT_TO_2_AINSTENCE: {		//case input 2 words to 2 strings. 
			cout << "enter two words for the first an second instance:\n";
			cin.get();
			cin >> a;
			cin >> b;
			a.print();
			b.print();
			break;
		}
		case COMPARE:{		//CASE COMPER 2 STRINGS
			if (a < b)
				cout << "a < b\n";
			else if (a == b)
				cout << "a = b\n";
			else
				cout << "a > b\n";
			break;
		}
		case INSERT_FUNC: {		//insert function to insert string 1 to 2 from a specipic index 
			int index;
			cout << "enter a index from which the word will be spelled after the existing word\n";
			cin >> index;
			try{
				c = a.insert(index, b.getString());
				c.print();
			}
			catch (IndexException * Error){
				cout << "The entered index : " << Error->index << " is biger than the word: (the word size is : " << Error->maxIndex << ")\n";
				delete[] Error;
			}
			try{
				c = b.insert(index, a.getString());
				c.print();
			}
			catch (IndexException * Error){
				cout << "The entered index : " << Error->index << " is biger than the word: (the word size is : " << Error->maxIndex << ")\n";
				delete[] Error;
			}
			break;
		}
		case SEARCH_WORD_IN_AINSTENCE:{		//case search a word in a string
			try{
				int index;
				index = a[b.getString()];
				cout << "The word: ";
				b.print();
				cout << "was found inside: ";
				a.print();
				cout << "from index : " << index << endl;
			}
			catch (const cstring Error){
				cout << "the word:  " << Error << " is not contained in: ";
				a.print();
				cout << endl;
				delete[]Error;
			}
		}
		break;
		}

	} while (chosen != EXIT);
	system("pause");
	return 0;
}
