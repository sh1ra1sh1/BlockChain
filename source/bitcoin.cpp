#include "../header/bitcoin.hpp"

Bitcoin::Bitcoin()
	: _blockchain(), _previousHash2()
{
}

void Bitcoin::chain(string data)
{
	string previousHash;

	if (_blockchain.size() == 0)
	{
		previousHash = "0";
	}
	else
	{
		previousHash = _previousHash2;
	}

	Block block(data, previousHash);
	_previousHash2 = block.Hash();
	_blockchain.push_back(_previousHash2);

	cout << "data: " << data << endl;
	cout << "previousHash: " << previousHash << endl;
	cout << "Hash: " << _previousHash2 << endl;
}

// bool Bitcoin::isValidBlockChain()
// {
// }