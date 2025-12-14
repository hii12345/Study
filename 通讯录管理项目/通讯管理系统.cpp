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
	struct Person  personArray[Max];
	int m_Size;
};
void addPerson(Addressbooks *abs) {
	//1.判断通讯录是否满
	if (abs->m_Size == Max) {
		cout << "通讯录已满" << endl;
	}
	else{
		//用户名
		string name;
		cout << "输入用户名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;
		//性别
		int sex = 0;
		cout << "请输入性别" << endl;
		cout << "1------男" << endl;
		cout << "2------女" << endl;
		while (true) {
			//如果输入的正常 退出。输入有误继续操作。
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误 请重新输入" << endl;
		}
		//年龄
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_age = age;
		//电话号码
		int number;
		cout << "请输入电话号码" << endl;
		cin >> number;
		abs->personArray[abs->m_Size].m_phone = number;
		//地址
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_addr = address;
		//更新数组数量
		abs->m_Size++;
		cout << "新增通讯录成功" << endl;
		//清屏
		system("pause");
		int asd = 123;
		int asd = 123;
		system("cls");
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