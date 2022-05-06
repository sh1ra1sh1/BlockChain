#ifndef TIME
#define TIME

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class GetDateTime
{
private:
	time_t _t;
	const tm *_localTime;
	stringstream _ss;
	string _s;

public:
	GetDateTime();

public:
	void set();
	string get() const;
};

#endif