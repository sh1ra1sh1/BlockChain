#ifndef BITCOIN
#define BITCOIN

#include <string>
#include <iostream>
#include <vector>

#ifndef BLOCK
#include "../header/block.hpp"
#endif

using namespace std;

class Bitcoin
{
public:
	vector<string> _blockchain;
	string _previousHash2;

public:
	Bitcoin();

public:
	void chain(string data);
	bool isValidBlockChain();
};

#endif