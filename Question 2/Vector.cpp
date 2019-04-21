/*
File: Vector.cpp
Description: This is the  Vector.cpp.
Course: 150018 C++ Workshop,
Exercise 4, Question 2
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#include "Vector.h"

Vector::Vector(uint capacity) {
	_capacity = capacity;
}

Vector::~Vector() {
	delete[]_data; // delete operators handle nullptr by themselves
	_data = nullptr;
}

//assignment
Vector::Vector(const Vector& other) {
	_size = other._size;
	_capacity = other._capacity;
	_data = other.getData();
}

//move 
Vector::Vector(Vector&& other) :_data(other._data), _capacity(other._capacity), _size(other._size) {
	other._data = nullptr;
	other._capacity = 0;
	other._size = 0;
}

//operators
// Copy Assignment operator.
Vector& Vector::operator = (const  Vector& rhs) {
	if (this == &rhs)return *this;		//if eqals 
	if (_capacity != rhs._capacity)
		_capacity = rhs._capacity;
	if (_size != rhs._size) {
		delete[]_data;
		_size = rhs._size;
		_data = rhs.getData();
		return *this;
	}
	for (uint i = 0; i < _size; ++i)
		if (_data[i] != rhs._data[i]) {
			delete[]_data;
			_data = rhs.getData();
			break;
		}
	return *this;
}

//Move Assignment operator
Vector& Vector::operator = (Vector&& rhs) {
	delete[]_data;
	_data = rhs._data;
	_size = rhs._size;
	_capacity = rhs._capacity;
	rhs._data = nullptr;
	rhs._size = 0;
	rhs._capacity = 0;
	return *this;
}

bool Vector::operator ==(const Vector& rhs)const {
	if (_size != rhs._size || _capacity != rhs._capacity)
		return false;
	for (uint i = 0; i < _size; ++i)
		if (_data[i] != rhs._data[i])
			return false;
	return true;
}

//out<< poerator 
ostream& operator <<(ostream& out, const Vector& rhs) {
	out << "capacity : " << rhs._capacity << " size : " << rhs._size << " content : ";
	for (uint i = 0; i < rhs._size; ++i)
		out << rhs._data[i] << " ";
	out << endl;
	return out;
}

//index operator get 
const int& Vector::operator[](int index) const
{
	if (index > _size - 1)
	{
		IndexException *temp = new IndexException(index, _size - 1);
		throw temp;
	}
	return _data[index];
}

//index operator set 
int& Vector::operator[](int index) {
	if (index > _size - 1) {
		IndexException *temp = new IndexException(index, _size - 1);
		throw temp;
	}
	return _data[index];
}

//mult operator
int* Vector::operator * (const Vector&rhs)const {
	if (_size != rhs._size) {
		IndexException *temp = new IndexException(_size, rhs._size);
		throw temp;
	}
	int * tempSum = new int[_size] {};
	for (uint i = 0; i < _size; ++i)
		tempSum[i] = _data[i] * rhs._data[i];
	return tempSum;
}
//add operator.
Vector operator + (const Vector& lhs, const Vector& rhs) {
	Vector temp(lhs._capacity + rhs._capacity);
	temp._size = (lhs._size + rhs._size);
	uint i = 0;
	for (i; i < lhs._size; ++i)
		temp._data[i] = lhs._data[i];
	for (uint k = 0; k < rhs._size; ++k, ++i)
		temp._data[i] = rhs._data[k];
	return temp;
}

// Public functions	
uint Vector::getCapacity()const {
	return _capacity;
}

uint Vector::getSize()const {
	return _size;
}

void Vector::setSize(const uint size) {
	_size = size;
}

//dalete last value in a vector function
void Vector::delLast() {
	if (!_size)throw 0;
	_data[--_size] = {};
}

int *Vector::getData() const {
	if (_data == nullptr)return nullptr;

	int* temp = new int[_capacity];
	for (uint i = 0; i < _size; ++i)
		temp[i] = _data[i];
	return temp;
}

//clear data of a vector function 
void Vector::clear() {
	*_data = {};
	_size = 0;
}

//insert a value in the vector if there if plase
void Vector::insert(int val) {
	if (_size == _capacity) throw _capacity; // if the array is full
	_data[_size++] = val;
}



