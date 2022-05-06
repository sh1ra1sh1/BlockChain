#ifndef BLOCK
#include "../header/block.hpp"
#endif

Block::Block(string &data, string &previousHash)
	: _data(), _hash(), _previousHash(), _timeStamp()
{
	_data = data;
	_previousHash = previousHash;
	GetDateTime getDateTime;
	getDateTime.set();
	_timeStamp = stoull(getDateTime.get());
	_hash = Hash();
}

string Block::Hash()
{
	string str = _data + _previousHash + to_string(_timeStamp);
	const char *message = str.c_str();
	unsigned int H[INIT_HASH_LENGTH];

	Sha256 sha256;

	unsigned char **result = sha256.padding((char *)message);

	sha256.compute(result, H);
	string hashValue = sha256.calc_hash(H);

	sha256.free_block(result);

	return hashValue;
}