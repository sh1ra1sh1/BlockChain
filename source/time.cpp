#include "../header/time.hpp"

GetDateTime::GetDateTime()
	: _t(), _localTime(), _ss(), _s()
{
}
void GetDateTime::set()
{
	_t = time(nullptr);
	_localTime = localtime(&_t);
	_ss << _localTime->tm_year + 1900;
	_ss << setw(2) << setfill('0') << _localTime->tm_mon + 1;
	_ss << setw(2) << setfill('0') << _localTime->tm_mday;
	_ss << setw(2) << setfill('0') << _localTime->tm_hour;
	_ss << setw(2) << setfill('0') << _localTime->tm_min;
	_ss << setw(2) << setfill('0') << _localTime->tm_sec;
	_s = _ss.str();
}
string GetDateTime::get() const
{
	return _s;
}