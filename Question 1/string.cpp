#include <cstring>
#include "string.h"

// C- String based Con _structor (CTOR)
String::String(const char* s) : _str(nullptr) {       // initialize the fields
	setString(s);
}
// Copy CTOR
String::String(const  String& other) : _str(nullptr) { // initialize the fields
	setString(other._str);
}
// Move CTOR
String::String(String&& other) : _str(other._str) {    // initialize with other's data
  // Avoid temp object DTOR removing the dynamic data which is now used in our object
	other._str = nullptr;
}
// De _structor (DTOR)
String::~String() {
	delete[]  _str; // delete operators handle nullptr by themselves
	_str = nullptr;
}

//  String getter (Viewer) which returns a dynamic c- String (char array)
// The caller is responsible to free this array after using it
char*  String::getString() const {
	if (_str == nullptr) return nullptr;  // there is nothing to return...
	uint length = strlen(_str) + 1; // calculate the length
	char* temp = new char[length];         // allocate the char array
	strncpy(temp, _str, length);            // copy the content
	return temp;
}

//  String setter (Modifier)
void  String::setString(const char * s) {
	// Protect when setting to the same char array
	if (s == _str) return;
	delete[]  _str; // Free old  String dynamic data memory

	if (s != nullptr) { // Create new dynamic char array and copy the content
		uint length = strlen(s) + 1; // calc the length
		_str = new char[length];              // allocate new array
		strncpy(_str, s, length);             // copy the content
	}
	else // Nullify the  String pointer
		_str = nullptr;
}

// Copy assignment operator
String&  String::operator = (const  String& s) {
	if (this == &s) return *this; // Protection from assigning the object to itself
	delete[] _str;
	_str = nullptr;
	setString(s._str);
	// Allow chained assignments
	return *this;
}

// Move assignment operator
String&  String::operator = (String&& s) {
	delete[]  _str; // Free old  String dynamic data memory
	_str = s._str;  // Update the pointer
	s._str = nullptr; // Avoid temp object DTOR removing the data now used in our object
	return *this;
}
// Operators

String&  String::operator += (const  String& rhs) {
	if (rhs._str == nullptr || strlen(rhs._str) == 0) // nothing to add
		return *this;

	if (_str == nullptr) { // we have nothing => like a copy ctor
		setString(rhs._str);
		return *this;
	}

	// Create new c- String with appropriate length
	char* temp = new char[strlen(_str) + strlen(rhs._str) + 1];
	strcpy(temp, _str);     // copy there our original  String
	strcat(temp, rhs._str); // concatenate there the second  String
	delete[]  _str;          // free our old memory
	_str = temp;            // set now to the new  String
	return *this;
}

String operator + (String lhs, const  String& rhs) {
	lhs += rhs; // Concatenate second  String to the first (local - by value)
	return lhs; // return by value - it will use Move Ctor
}

String&  String::operator *= (uint rhs) {
	if (_str == nullptr || rhs == 1 || strlen(_str) == 0) // nothing to replicate
		return *this;

	if (rhs == 0) { // empty us
		delete[]  _str;
		_str = nullptr;
		return *this;
	}

	// Create new c- String with appropriate length
	char* temp = new char[strlen(_str) * rhs + 1];
	strcpy(temp, _str);      // First time - copy myself to there
	while (--rhs != 0)       // While there are more replications to do
		strcat(temp, _str);  //    concatenate myself to there (again and again)

	delete[]  _str;          // free our old memory
	_str = temp;            // set now to the new  String
	return *this;
}

String operator*(String lhs, uint rhs) {
	lhs *= rhs; // Replicate inside the first (local - by value)
	return lhs; // return by value - it will use Move Ctor
}

bool  String::operator == (const  String& rhs) const {
	return !strcmp(_str, rhs._str);
}

bool String::operator <(const String& rhs)const {
	if (strcmp(_str, rhs._str) < 0)
		return true;
	else
		return false;
}

bool String::operator >(const String& rhs)const {
	if (strcmp(_str, rhs._str) > 0)
		return true;
	else
		return false;
}

bool String::operator <=(const String& rhs)const {
	if (strcmp(_str, rhs._str) > 0)
		return false;
	else
		return true;
}

bool String::operator >=(const String& rhs)const {
	if (strcmp(_str, rhs._str) < 0)
		return false;
	else
		return true;
}

bool String::operator !=(const String& rhs)const {
	if (strcmp(_str, rhs._str) == 0)
		return false;
	else
		return true;
}

int& String::operator[](const cstring index) {
	for (int i = 0; i < length(); ++i) {
		return i;

	}
}


ostream& operator <<(ostream& out, const String& rhs) {
	out << *rhs._str;
	return out;
}

istream& operator >>(istream& in, String& rhs) {
	delete[]rhs._str;
	char *temp1 = new char[100];
	in >> temp1;
	rhs._str = new char[strlen(temp1) + 1];
	strcpy(rhs._str, temp1);
	delete[]temp1;
	return in;
}

// Public functions
int  String::length() const {
	return  strlen(_str);
}

void  String::print() const {
	if (_str != nullptr)
		cout << _str;
	cout << endl;
}

String & String::insert(int index, const char* str) {
	if (index > length() - 1) {
		IndexException *temp = new IndexException(index, length());
		throw temp;
	}
	else {
		cstring tempString = new char[length() + strlen(str) + 1]{};
		strncat(tempString, _str, index);
		strcat(tempString, str);
		for (uint i = strlen(tempString); i < strlen(tempString) + length(); ++i)
			tempString[i] = _str[index++];
		String *insert = new String(tempString);
		return *insert;
	}
}