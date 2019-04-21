/*
File: string.h
Description: This is the header file of string.cpp.
Course: 150018 C++ Workshop,
Exercise 4, Question 1
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#ifndef __ String_H
#define __ String_H

#include <iostream>
#include"mytypes.h"
#include"IndexException.h"

using namespace std;

class  String {
private:
	char * _str;                      // Internal data container - for dynamic c- String
	void setString(const char* s);   // Modifier - for internal usage
public:
	// constructors
	String(const char* s = nullptr); // Default and from c- String
	String(const  String& s);         // Copy ctor
	String(String&& s);              // Move ctor
	~String();                       // Dtor

	char* getString() const;         // Viewer

	// Operators
	String& operator = (const  String&);    // Copy Assignment
	String& operator = (String&&);          // Move Assignment
	bool operator == (const String&) const; // Equality
	String& operator += (const String&);    // Addition to object by concatenation
	friend String operator + (String, const  String&); // Symmetric addition as friend
	String& operator *= (uint);     // Multiplication by replicating
	friend String operator * (String, uint);  // Symmetric multiplication as friend
	int& operator[](cstring contained);

	bool operator <(const String&)const;
	bool operator >(const String&)const;
	bool operator <=(const String&)const;
	bool operator >=(const String&)const;
	bool operator !=(const String&)const;

	friend ostream& operator <<(ostream& out, const String&);
	friend istream& operator >>(istream& in, String&);

	// Public functions
	int length() const; // Length of the  String
	void print() const; // Print the  String
	String& insert(int index, const char* str);
};

String operator + (String, const  String&); // Declaration of addition operator (global)
String operator * (String, uint);  // Declaration of mulitiplication oeprator (global)

#endif // __ String_H
