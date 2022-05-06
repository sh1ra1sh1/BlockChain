#ifndef BITCOIN
#include "../header/bitcoin.hpp"
#endif

int main()
{
	Bitcoin bitcoin;
	int N;
	string data;
	string name, store, merchandise, price;

	cout << "ビットコインシミュレーション" << endl;
	cout << "CopyRight 白石研究室 2022" << endl;
	cout << "--" << endl;
	cout << "入力データをもとにブロックチェーンを作成します．" << endl;
	cout << "データ数を入力してください．" << endl;
	cout << "データ数: ";
	cin >> N;
	cout << "--" << endl;
	cout << "氏名，店名，商品名，値段[円]を半角スペース区切りで入力してください．" << endl;
	cout << "--" << endl;
	for(int intI = 0; intI < N; intI++)
	{
		data = "";
		cout << intI + 1 << "件目" << endl;
		cout << "-> ";
		cin >> name >> store >> merchandise >> price;
		data = name + '.' + store + '.' + merchandise + '.' + price;
		bitcoin.chain(data);
		cout << "--" << endl;
	}

	return 0;
}