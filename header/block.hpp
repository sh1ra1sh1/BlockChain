#ifndef BLOCK
#define BLOCK

#include <iomanip>
#include <iostream>
#include <string>
#ifndef SHA256
#include "../header/sha256.hpp"
#endif
#ifndef TIME
#include "../header/time.hpp"
#endif

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

#endif