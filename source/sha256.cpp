#ifndef SHA256
#include "../header/sha256.hpp"
#endif

#define MESSAGE_BLOCK_SIZE 64

unsigned char **Sha256::padding(char *input)
{
	int intLength = strlen(input);
	int intBlock = (intLength + 9 + (MESSAGE_BLOCK_SIZE - 1)) / MESSAGE_BLOCK_SIZE;
	unsigned char **output = (unsigned char **)malloc(sizeof(char *) * (intBlock + 1));
	int intP = 0;

	for (int intI = 0; intI < intBlock; intI++)
	{
		output[intI] = (unsigned char *)malloc(sizeof(char) * MESSAGE_BLOCK_SIZE);

		int intCopyLength = intLength - intP;
		if (intCopyLength > MESSAGE_BLOCK_SIZE)
		{
			intCopyLength = MESSAGE_BLOCK_SIZE;
		}
		else
		{
			if (intCopyLength < 0)
			{
				intCopyLength = 0;
			}
		}

		if (intCopyLength < MESSAGE_BLOCK_SIZE)
		{
			memset(output[intI], 0, sizeof(char) * MESSAGE_BLOCK_SIZE);
		}

		if (intCopyLength > 0)
		{
			memcpy(output[intI], &input[intP], sizeof(char) * intCopyLength);

			if (intCopyLength < MESSAGE_BLOCK_SIZE)
			{
				output[intI][intCopyLength] = 0x80;
			}
		}

		else
		{
			if (intLength % MESSAGE_BLOCK_SIZE == 0)
			{
				output[intI][0] = 0x80;
			}
		}

		if (intI == intBlock - 1)
		{
			int intBitLength = intLength * 8;

			output[intI][MESSAGE_BLOCK_SIZE - 4] = (unsigned char)(intBitLength >> 24 & (unsigned char)0xff);
			output[intI][MESSAGE_BLOCK_SIZE - 3] = (unsigned char)(intBitLength >> 16 & (unsigned char)0xff);
			output[intI][MESSAGE_BLOCK_SIZE - 2] = (unsigned char)(intBitLength >> 8 & (unsigned char)0xff);
			output[intI][MESSAGE_BLOCK_SIZE - 1] = (unsigned char)(intBitLength & (unsigned char)0xff);
		}

		intP = intP + MESSAGE_BLOCK_SIZE;
	}

	output[intBlock] = NULL;

	return output;
}

void Sha256::free_block(unsigned char **block)
{
	int intI = 0;
	while (block[intI] != NULL)
	{
		free(block[intI]);
		intI++;
	}
	free(block);
}

string Sha256::calc_hash(unsigned int *H)
{
	string ss = "";
	for (int intI = 0; intI < INIT_HASH_LENGTH; intI++)
	{
		ss += calc_hex(H[intI]);
	}

	return ss;
}

string Sha256::calc_hex(unsigned int i)
{
	stringstream s;
	unsigned int h;

	h = (i & 0xff000000) >> 24;
	s << hex << setw(2) << setfill('0') << (unsigned short int)(h);

	h = (i & 0x00ff0000) >> 16;
	s << hex << setw(2) << setfill('0') << (unsigned short int)(h);

	h = (i & 0x0000ff00) >> 8;
	s << hex << setw(2) << setfill('0') << (unsigned short int)(h);

	h = (i & 0x000000ff);
	s << hex << setw(2) << setfill('0') << (unsigned short int)(h);

	return s.str();
}

void Sha256::compute(unsigned char **block, unsigned int *H)
{
	int N = 0;
	while (block[N] != NULL)
	{
		N++;
	}

	unsigned int W[MESSAGE_BLOCK_SIZE];

	memcpy(H, H0, sizeof(int) * INIT_HASH_LENGTH);

	for (int i = 0; i < N; i++)
	{
		unsigned int a, b, c, d, e, f, g, h, T1, T2;

		char *msg = (char *)block[i];

		for (int t = 0; t < MESSAGE_BLOCK_SIZE; t++)
		{
			if (t < 16)
			{
				int p = t * 4;
				W[t] = (unsigned int)((msg[p] & 0xff) << 24) | (unsigned int)((msg[p + 1] & 0xff) << 16) | (unsigned int)((msg[p + 2] & 0xff) << 8) | (unsigned int)(msg[p + 3] & 0xff);
			}
			else
			{
				W[t] = sigma1(W[(t - 2)]) + W[(t - 7)] + sigma0(W[(t - 15)]) + W[(t - 16)];
			}
		}

		a = H[0];
		b = H[1];
		c = H[2];
		d = H[3];
		e = H[4];
		f = H[5];
		g = H[6];
		h = H[7];

		for (int t = 0; t < MESSAGE_BLOCK_SIZE; t++)
		{
			T1 = h + SIGMA1(e) + Ch(e, f, g) + K[t] + W[t];
			T2 = SIGMA0(a) + Maj(a, b, c);

			h = g;
			g = f;
			f = e;
			e = d + T1;
			d = c;
			c = b;
			b = a;
			a = T1 + T2;
		}

		H[0] = (a + H[0]) & 0xffffffff;
		H[1] = (b + H[1]) & 0xffffffff;
		H[2] = (c + H[2]) & 0xffffffff;
		H[3] = (d + H[3]) & 0xffffffff;
		H[4] = (e + H[4]) & 0xffffffff;
		H[5] = (f + H[5]) & 0xffffffff;
		H[6] = (g + H[6]) & 0xffffffff;
		H[7] = (h + H[7]) & 0xffffffff;
	}
}