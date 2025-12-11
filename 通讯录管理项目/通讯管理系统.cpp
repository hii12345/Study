#include<iostream>
using namespace std;
#include<string>
#define Max 1000


struct Person //人员结构体
{
	string m_name;
	int m_Sex;  //1 男。2 女
	int m_age;
	string m_phone;
	string m_addr;
};
struct Addressbooks //通讯录结构体
{
	struct Person  personArrary[Max];
	int m_Size;
};
void addPerson(Addressbooks *abs) {
	//1.判断通讯录是否满
	if (abs->m_Size == Max) {
		cout << "通讯录已满" << endl;
	}
	else{
		string name;
		cout << "输入用户名" << endl;
		cin >> name;
		abs->personArrary[abs->m_Size].m_name = name;
	}
}
void showmean() {
	cout << "1.添加联系人" << endl;
	cout << "2.显示联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.查询联系人" << endl;
	cout << "5.修改联系人" << endl;
	cout << "6.清空联系人" << endl;
	cout << "0.退出" << endl;
}
int main() {
	int select = 0;
	//创建一个通讯录的结构体变量
	Addressbooks abs;
	//初始化通讯录当前人员个数
	abs.m_Size = 0;
	while (true)
	{
		showmean();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);//利用地址传递 修饰实参
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			cout << "已退出" << "\n";
			system("pause");
			return 0;
			break;
		}
	}
}