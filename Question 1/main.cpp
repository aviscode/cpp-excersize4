#include<iostream>
#include"string.h"
using namespace std;

enum Action
{
	EXIT,
	INSERT_2_WORDS,
	COMPARE,
	INSERT_FUNC,
	SEARCH_WORD
};

Action menu()
{
	cout << "enter 1 to put in two words" << endl;
	cout << "enter 2 to compare the two words" << endl;
	cout << "enter 3 to enter an index from which, the second word will be inserted after this word" << endl;
	cout << "enter 4 to search if the second word contained in the first word " << endl;
	cout << "enter 0 to exit" << endl;
	int x;
	cin >> x;
	return (Action)x;
}

int main()
{
	String a, b, c;

	Action ac = menu();
	while (ac)
	{
		switch (ac)
		{
		case INSERT_2_WORDS:
		{
			cout << "please enter 2 words \n";
			cin >> a;
			cin >> b;
			a.print();
			b.print();

			break;
		}
		case COMPARE:
		{
			if (a < b)
				cout << "a < b\n";
			else if (a == b)
				cout << "a = b\n";
			else
				cout << "a > b\n";
			break;
		}
		case INSERT_FUNC:
		{
			int index;
			cout << "Select an index from which the word will be spelled after the existing word\n";
			cin >> index;
			try
			{
				c = a.insert(index, b.getString());
				c.print();
			}
			catch (IndexException * Index)
			{
				cout << "The given index : " << Index->index << " is biger than the word. (the word size is : " << Index->maxIndex << ")\n";
				delete[] Index;
			}
			try
			{a.insert(index, a.getString());
				c.print();
			}
			catch (IndexException * Index)
			{
				cout << "The given index : " << Index->index << " is biger than the word. (the word size is : " << Index->maxIndex << ")\n";
				delete[] Index;
			}
			break;
		}
		case SEARCH_WORD:
		{
			try
			{
				int indexOfFirstLetter;
				indexOfFirstLetter = a[b.getString()];
				cout << "The word :";
				b.print();
				cout << "was found inside :";
				a.print();
				cout << "in index : " << indexOfFirstLetter << endl;
			}
			catch (const cstring notContained)
			{
				cout << "the word : " << notContained << " is not contained in :";
				a.print();
				cout << endl;
				delete[]notContained;
			}
		}
		break;
		}
		ac = menu();
	}
	return 0;
}
