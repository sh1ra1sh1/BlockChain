#include <string>
#include <iostream>
#include <vector>

#include "../header/block.hpp"

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