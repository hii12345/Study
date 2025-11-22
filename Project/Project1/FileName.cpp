#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;
#include <vector>
//int main() {
//	int i;
//	cout << "请输入数字，开始倒计时";
//	cin >> i;
//	while (i > 0)
//	{
//		Sleep(2000);
//		cout << i << endl;
//		i--;
////等待2秒后执行
//	}
//	cout << "Happy new year!";
//
//	return 0;
//}
int main() {

	bool ships[4][4] = {
	{ 0, 1, 1, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 1, 0 },
	{ 0, 0, 1, 0 }
	};
	int hits = 0;
	int NumberOfTurns = 0;
	while (hits<4) {
		int row, column;
		cout << "请输入选的行数";
		cin >> row;
		if (row>4)
		{
			cout << "输入的行数超出范围";
			cout << "请重新输入选的行数";
			cin >> row;
		}
		cout << "请输入列";
		cin >> column;
		if (column > 4)
		{
			cout << "输入的列数超出范围";
			cout << "请重新输入选的列";
			cin >> column;
		}
		if (ships[row][column]) {
			ships[row][column] = 0;
			hits++;
			cout << "我们还有" << 4 - hits << "未击沉\n";
		}
		else
		{
			cout << "未击中\n\n";
		}
		NumberOfTurns++;
	}
	cout << "胜利！\n";
	cout << "您在 " << NumberOfTurns << " 轮内获胜";
}


