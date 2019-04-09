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
	// con _structors
	String(const char* s = nullptr); // Default and from c- String
	String(const  String& s);         // Copy ctor
	String(String&& s);              // Move ctor
	~String();                       // Dtor

	char* getString() const;         // Viewer

	// Operators
	String& operator = (const  String&);     // Copy Assignment
	String& operator = (String&&);          // Move Assignment
	bool operator == (const String&) const; // Equality
	String& operator += (const String&);    // Addition to object by concatenation
	friend String operator + (String, const  String&); // Symmetric addition as friend
	String& operator *= (uint);     // Multiplication by replicating
	friend String operator * (String, uint);  // Symmetric multiplication as friend
	bool operator <(const String&)const;
	bool operator >(const String&)const;
	bool operator <=(const String&)const;
	bool operator >=(const String&)const;
	bool operator !=(const String&)const;
	int& operator[](cstring index);
	friend ostream& operator <<(ostream& out, const String&);
	friend istream& operator >>(istream& in, String&);

	// Public functions
	int length() const; // Length of the  String
	void print() const; // Print the  String
	String& insert(int index, const char* str);
};

String operator + (String, const  String&); // Declaration of addition operator (global)
String operator * (String, unsigned int);  // Declaration of mulitiplication oeprator (global)

#endif // __ String_H
