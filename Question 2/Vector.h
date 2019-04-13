/*
File: Vector.h
Description: This is the header fileof Vector.cpp.
Course: 150018 C++ Workshop,
Exercise 4, Question 2
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#ifndef __ Vector_
#define __ VEector_H

#include"mytypes.h"
#include <iostream>
#include"IndexException.h"
using namespace std;

class Vector {
private:
	uint _capacity;
	uint _size = 0;
	int *_data = new int[_capacity];
public:
	//constructors
	Vector(uint capacity = 10); // Default  constructor (10) or user input 
	Vector(const Vector&); // Copy cto
	Vector(Vector&&);  // Move ctor
	~Vector();   // Dtor
	
	// Operators
	Vector& operator = (const  Vector&); // Copy Assignment operator
	Vector& operator = (Vector&&); //Move Assignment operator
	bool operator ==(const Vector&)const;
	friend ostream& operator <<(ostream&, const Vector&);
	const int& operator[](int) const;
	int & operator[](int );
	int * operator * (const Vector&)const;
	friend Vector operator + (const Vector&, const Vector&);

	// Public functions
	uint getCapacity()const;
	uint getSize()const;
	void setSize(const uint);
	int * getData() const;
	void delLast();
	void clear();
	void insert(int val);
};

#endif // __ Vector_H
