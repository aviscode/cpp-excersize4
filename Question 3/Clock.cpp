/*
File: Clock.cpp
Description: This is the Clock.cpp file .
Course: 150018 C++ Workshop,
Exercise 4, Question 3
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#include "Clock.h"

//constractor
Clock::Clock(const uint hour, const uint minute, const uint second) : _hour(0), _minute(0), _second(0) {
	if (hour > 23 || hour < 0)
		_hour = 0, _minute = 0, _second = 0;
	else if (minute > 59 || minute < 0)
		_hour = 0, _minute = 0, _second = 0;
	else if (second > 59 || second < 0)
		_hour = 0, _minute = 0, _second = 0;
	else {
		_hour = hour;
		_minute = minute;
		_second = second;
	}
}

//get and set valus in the time fileds.
uint Clock::getHour() {
	return _hour;
}

void Clock::setHour(uint hour) {
	if (hour > 23 || hour < 0) {
		_hour = 0, _minute = 0, _second = 0;
		throw hour;
	}
	_hour = hour;
}

uint Clock::getMinute() {
	return _minute;
}

void Clock::setminute(uint minute) {
	if (minute > 59 || minute < 0) {
		_hour = 0, _minute = 0, _second = 0;
		throw minute;
	}
	_minute = _minute;
}

uint Clock::getSecond() {
	return _second;
}

void Clock::setSecond(uint second) {
	if (second > 59 || second < 0) {
		_hour = 0, _minute = 0, _second = 0;
		throw second;
	}
	_second = second;
}

//opreators
Clock& Clock::operator +=(uint second) {
	_hour = (_hour + ((_minute + ((_second + second) / 60)) / 60)) % 24;
	_minute = (_minute + ((_second + second) / 60)) % 60;
	_second = (_second + second) % 60;
	return *this;
}
// ++ second function
Clock& Clock::operator ++() {
	if (++_second == 60) {
		_second = 0;
		if (++_minute == 60) {
			_minute = 0;
			if (++_hour == 24)
				_hour = 0;
		}
	}
	return *this;
}

//second++ function
Clock Clock::operator ++(int) {
	Clock temp = *this;
	++(*this);
	return temp;
}

//out << operator 
ostream& operator <<(ostream& out, const Clock& time) {
	out << setfill('0') << setw(2) << time._hour << ":";
	out << setfill('0') << setw(2) << time._minute << ":";
	out << setfill('0') << setw(2) << time._second;
	return out;
}

//in >> operator 
istream& operator >>(istream& in, Clock& time) {
	in >> time._hour >> time._minute >> time._second;
	if (time._hour > 23) {
		cout << "Wrong time format" << endl << "Invalid time - more than 24 hours\n";
		time._hour = 0, time._minute = 0, time._second = 0;
		return in;
	}
	if (time._minute > 59) {
		cout << "Wrong time format" << endl << "Invalid time - more than 60 minutes\n";
		time._hour = 0, time._minute = 0, time._second = 0;
		return in;
	}
	if (time._second > 59) {
		cout << "Wrong time format" << endl << "Invalid time - more than 60 seconds\n";
		time._hour = 0, time._minute = 0, time._second = 0;
		return in;
	}
	if (time._hour < 0) {
		cout << "Wrong time format" << endl << "Invalid time - negative number of hours\n";
		time._hour = 0, time._minute = 0, time._second = 0;
		return in;
	}
	if (time._minute < 0) {
		cout << "Wrong time format" << endl << "Invalid time - negative number of minutes\n";
		time._hour = 0, time._minute = 0, time._second = 0;
		return in;
	}
	if (time._second < 0) {
		cout << "Wrong time format" << endl << "Invalid time - negative number of seconds\n";
		time._hour = 0, time._minute = 0, time._second = 0;
		return in;
	}
	return in;
}
