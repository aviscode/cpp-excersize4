#ifndef _CLOCK_H_
#define _CLOCK_H_

#include"mytypes.h"
#include<iostream>
using namespace std;

class Clock {
private:
	uint _hour;
	uint _minute;
	uint _second;
public:
	Clock(uint hour = 0, uint minute = 0, uint second = 0);
	~Clock();

	//get and set the values for time.
	uint getHour();
	void setHour(uint);
	uint getMinute();
	void setminute(uint);
	uint getSecond();
	void setSecond(uint);
	
	//operators
	Clock& operator +=(uint);
	Clock& operator ++();		//++second	
	Clock operator ++(int);	//second++

	friend ostream& operator <<(ostream&, const Clock&);
	friend istream& operator >>(istream&, Clock&);

};




#endif // !_CLOCK_H_


