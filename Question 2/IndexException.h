/*
File: INDEXEXCPTION.h
Description: This is the header file of ERROR struct.
Course: 150018 C++ Workshop,
Exercise 4, Question 2
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#ifndef _INDEXEXCPTION__
#define _INDEXEXCPTION__

struct IndexException {
	uint index;
	uint maxIndex;
	IndexException(int ind, int max) : index(ind), maxIndex(max) {}
};

#endif // !_INDEXEXCPTION__
