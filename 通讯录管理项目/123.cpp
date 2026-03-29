// 引入输入输出流头文件，用于控制台输入输出操作
#include<iostream>
// 使用std命名空间，避免每次调用cout/cin都写std::
using namespace std;
// 引入字符串处理头文件，用于string类型的使用
#include<string>
// 引入自定义的通讯管理系统头文件（当前代码未实际使用，保留原引用）
#include "通讯管理系统.h"
// 定义常量Max，表示通讯录最大存储容量
#define Max 1000
// VS编译器编码设置，强制使用GBK编码以支持中文显示（Dev-C++可注释）
#pragma execution_character_set("gbk")

// 定义人员结构体，存储单个联系人的所有信息
struct Person
{
    string m_name;   // 联系人姓名（字符串类型）
    int m_Sex;       // 联系人性别（1=男，2=女，整型便于存储和判断）
    int m_age;       // 联系人年龄（整型）
    string m_phone;  // 联系人电话号码（字符串可存储带特殊字符的号码）
    string m_addr;   // 联系人地址（字符串类型）
};

// 定义通讯录结构体，管理多个联系人
struct Addressbooks
{
    struct Person personArray[Max];  // 存储联系人的数组，最大容量Max
    int m_Size;                      // 记录当前通讯录中实际的联系人数量
};

// 函数功能：添加新联系人到通讯录
// 参数：Addressbooks* abs - 通讯录结构体的指针（地址传递，直接修改原数据）
// 设计思路：先判断通讯录是否已满，未满则逐字段录入信息，最后更新联系人数量
void addPerson(Addressbooks* abs)
{
    // 1. 判断通讯录是否达到最大容量，满则提示并退出函数
    if (abs->m_Size == Max)
    {
        cout << "通讯录已满，无法添加新联系人！" << endl;
        return; // 终止函数执行
    }
    else
    {
        // 2. 录入联系人姓名
        string name;
        cout << "请输入联系人姓名：" << endl;
        cin >> name;
        // 将姓名赋值给当前最后一个空位置的联系人（abs->m_Size为当前最后一个索引）
        abs->personArray[abs->m_Size].m_name = name;

        // 3. 录入联系人性别（做合法性校验，确保输入1或2）
        int sex = 0;
        cout << "请输入性别：" << endl;
        cout << "1------男" << endl;
        cout << "2------女" << endl;
        // 循环输入直到用户输入合法值
        while (true)
        {
            cin >> sex;
            // 校验性别输入是否为1或2
            if (sex == 1 || sex == 2)
            {
                // 将合法的性别值存入结构体（直接存整型，显示时再转换为中文）
                abs->personArray[abs->m_Size].m_Sex = sex;
                break; // 输入合法，退出循环
            }
            cout << "输入有误，请重新输入（1=男/2=女）！" << endl;
        }

        // 4. 录入联系人年龄
        int age;
        cout << "请输入年龄：" << endl;
        cin >> age;
        abs->personArray[abs->m_Size].m_age = age;

        // 5. 录入联系人电话号码
        string number;
        cout << "请输入电话号码：" << endl;
        cin >> number;
        abs->personArray[abs->m_Size].m_phone = number;

        // 6. 录入联系人地址
        string address;
        cout << "请输入地址：" << endl;
        cin >> address;
        abs->personArray[abs->m_Size].m_addr = address;

        // 7. 更新通讯录联系人数量（新增后数量+1）
        abs->m_Size++;
        cout << "新增联系人成功！" << endl;

        // 暂停控制台，让用户查看提示信息
        system("pause");
        // 清屏操作，使界面更整洁
        system("cls");
    }
}

// 函数功能：显示通讯录中所有联系人信息
// 参数：Addressbooks* abs - 通讯录结构体指针（地址传递，读取原数据）
// 设计思路：先判断是否为空，非空则遍历数组逐行打印每个联系人信息
void showperson(Addressbooks* abs)
{
    // 1. 判断通讯录是否为空
    if (abs->m_Size == 0)
    {
        cout << "当前通讯录中无联系人记录！" << endl;
    }
    else
    {
        // 2. 遍历通讯录数组，打印每个联系人的信息
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_name << "\t";
            // 三元运算符：将整型性别转换为中文显示（1=男，2=女）
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_age << "\t";
            cout << "电话：" << abs->personArray[i].m_phone << "\t";
            cout << "地址：" << abs->personArray[i].m_addr << endl;
        }
    }
    // 暂停控制台，让用户查看信息
    system("pause");
    // 清屏，返回主菜单界面
    system("cls");
}

// 函数功能：检查指定姓名的联系人是否存在
// 参数：Addressbooks* abs - 通讯录指针；string name - 要查询的姓名
// 返回值：存在则返回联系人在数组中的索引，不存在返回-1
// 设计思路：遍历数组对比姓名，找到匹配项立即返回索引，遍历结束未找到返回-1
int isExist(Addressbooks* abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        // 对比当前索引的联系人姓名与查询姓名
        if (abs->personArray[i].m_name == name)
        {
            return i; // 找到，返回索引
        }
    }
    return -1; // 未找到，返回-1
}

// 函数功能：删除指定姓名的联系人
// 参数：Addressbooks* abs - 通讯录指针（地址传递，修改原数据）
// 设计思路：先调用isExist检查是否存在，存在则将后续数据前移覆盖，最后数量-1
void deleteperson(Addressbooks* abs)
{
    cout << "请输入要删除的联系人姓名：" << endl;
    string name;
    cin >> name;

    // 调用isExist函数检查联系人是否存在，接收返回的索引/状态
    int ret = isExist(abs, name);
    if (ret != -1) // 存在该联系人
    {
        // 从删除位置开始，将后续联系人数据向前移动一位（覆盖被删除数据）
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        // 通讯录联系人数量减1（更新实际存储数量）
        abs->m_Size--;
        cout << "删除联系人成功！" << endl;
    }
    else // 不存在该联系人
    {
        cout << "通讯录中查无此人！" << endl;
    }
    // 暂停控制台，查看操作结果
    system("pause");
    // 清屏，返回主菜单
    system("cls");
}

// 函数功能：显示通讯录管理系统的主菜单sdf
// 设计思路：纯输出函数，清晰展示所有功能选项，方便用户选择操作
void showmean()
{
    cout << "=====================通讯录管理系统=====================" << endl;
    cout << "=======================功能菜单=======================" << endl;
    cout << "1. 添加联系人" << endl;
    cout << "2. 显示联系人" << endl;
    cout << "3. 删除联系人" << endl;
    cout << "4. 查询联系人" << endl;
    cout << "5. 修改联系人" << endl;
    cout << "6. 清空联系人" << endl;
    cout << "0. 退出系统" << endl;
    cout << "======================================================" << endl;
    cout << "请输入您要执行的操作序号：";
}

// 主函数：程序入口，控制整体流程
// 设计思路：初始化通讯录→循环显示菜单→接收用户选择→调用对应功能函数→直到选择退出
int main123()
{
    int select = 0; // 存储用户输入的菜单选择序号
    Addressbooks abs; // 创建通讯录结构体实例（栈区分配，自动初始化）
    abs.m_Size = 0; // 初始化通讯录：当前联系人数量为0

    // 无限循环，直到用户选择0退出
    while (true)
    {
        showmean(); // 显示主菜单
        cin >> select; // 接收用户输入的操作序号

        // 分支选择：根据用户输入调用对应功能函数
        switch (select)
        {
        case 1: // 选择1：添加联系人
            // 传递通讯录地址，通过指针修改原数据（值传递无法修改实参）
            addPerson(&abs);
            break; // 结束当前分支，回到循环开头
        case 2: // 选择2：显示联系人
            showperson(&abs); // 传递地址读取通讯录数据
            break;
        case 3: // 选择3：删除联系人
            deleteperson(&abs); // 传递地址修改通讯录数据
            break;
        case 4: // 选择4：查询联系人（暂未实现）
            cout << "查询联系人功能暂未实现！" << endl;
            system("pause");
            system("cls");
            break;
        case 5: // 选择5：修改联系人（暂未实现）
            cout << "修改联系人功能暂未实现！" << endl;
            system("pause");
            system("cls");
            break;
        case 6: // 选择6：清空联系人（暂未实现）
            cout << "清空联系人功能暂未实现！" << endl;
            system("pause");
            system("cls");
            break;
        case 0: // 选择0：退出系统
            cout << "感谢使用通讯录管理系统，已退出！" << "\n";
            system("pause"); // 暂停查看退出提示
            return 0; // 终止程序，返回0表示正常退出
            break;
        default: // 输入非法序号
            cout << "输入序号有误，请重新输入！" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}