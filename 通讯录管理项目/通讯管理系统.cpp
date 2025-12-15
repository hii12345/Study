#include<iostream>
using namespace std;
#include<string>
#define Max 1000
// 新增：VS编译器强制GBK编码（如果是Dev-C++可跳过这行）
#pragma execution_character_set("gbk")

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
<<<<<<< HEAD
void addPerson(Addressbooks* abs) //添加联系人
=======
void addPerson(Addressbooks *abs) //添加联系人
>>>>>>> 323aeecc495220a302f90157dbd330158267492c
{
	//1.判断通讯录是否满
	if (abs->m_Size == Max) {
		cout << "通讯录已满" << endl;
	}
<<<<<<< HEAD
	else {
=======
	else{
>>>>>>> 323aeecc495220a302f90157dbd330158267492c
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
				//abs->personArray[abs->m_Size].m_Sex = sex;
<<<<<<< HEAD
				if (sex == 1) {
=======
				if (sex ==1) {
>>>>>>> 323aeecc495220a302f90157dbd330158267492c
					string cn_sex = "男";
					to_string(abs->personArray[abs->m_Size].m_Sex) = cn_sex;
				}
				else if (sex == 2) {
					string cn_sex = "女";
					to_string(abs->personArray[abs->m_Size].m_Sex) = cn_sex;
				}
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
		string number;
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
		system("cls");
	}
}

//显示联系人
<<<<<<< HEAD
void showperson(Addressbooks* abs)
{
	//判断通讯录中人数是否为0，为0 提示记录为空
	//如果不为0 显示记录的联系人
	if (abs->m_Size == 0) {
		cout << "当前联系人为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
=======
void showperson(Addressbooks *abs) 
{
	//判断通讯录中人数是否为0，为0 提示记录为空
	//如果不为0 显示记录的联系人
	if (abs->m_Size==0) {
		cout << "当前联系人为空" << endl;
	}
	else {
		for (int i = 0;  i < abs->m_Size;i++) {
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1?"男":"女") << "\t";
>>>>>>> 323aeecc495220a302f90157dbd330158267492c
			//cout << "性别：" << (abs->personArray[i].m_Sex == 1?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_age << "\t";
			cout << "电话：" << abs->personArray[i].m_phone << "\t";
			cout << "地址：" << abs->personArray[i].m_addr << endl;
		}
	}
	//清屏
	system("pause");
	system("cls");
}
//删除联系人

<<<<<<< HEAD
int deleteperson(Addressbooks* abs, string name) {
	//检查联系人是否存在，若存在返回联系人所存在的数据编号
	//不存在返回 -1
	//1.遍历你所有的数组中的人名，与输入的string name 相匹配 表示存在 不相符表示不存在
	for (int i = 0; i < abs->m_Size; i++) {
=======
int deleteperson(Addressbooks* abs,string name) {
	//检查联系人是否存在，若存在返回联系人所存在的数据编号
	//不存在返回 -1
	//1.遍历你所有的数组中的人名，与输入的string name 相匹配 表示存在 不相符表示不存在
	for (int i = 0; i < abs->m_Size;i++) {
>>>>>>> 323aeecc495220a302f90157dbd330158267492c
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
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
			showperson(&abs);
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