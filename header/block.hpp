#include <iomanip>
#include <iostream>
#include <string>
#include "../header/sha256.hpp"
#include "../header/time.hpp"

using namespace std;

class Block
{
private:
	string _data;
	string _hash;
	string _previousHash;
	unsigned long long _timeStamp;

public:
	Block(string &data, string &previousHash);

public:
	string Hash();
};