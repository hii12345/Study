#ifndef TESTUSERDB_H
#define TESTUSERDB_H

#include <string>
#include <stdexcept>
#include <mysql.h>

// 定义用户数据结构体（与数据库表字段对应）
struct TestUser {
    std::string m_name;
    int m_Sex;      // 1=男 2=女
    int m_age;
    std::string m_phone;
    std::string m_addr;
};

// 数据库操作类
class TestUserDB {
public:
    // 构造函数：初始化数据库连接
    TestUserDB(const std::string& host,
        const std::string& user,
        const std::string& password,
        const std::string& dbname,
        unsigned int port = 3306);

    // 析构函数：释放连接
    ~TestUserDB();

    // 核心方法：插入用户数据到数据库
    bool insertUser(const TestUser& user);

private:
    MYSQL* mysql_conn;  // MySQL 连接句柄
    bool is_connected;  // 连接状态标记

    // 辅助方法：检查连接有效性
    bool checkConnection();

    // 辅助方法：防止SQL注入（转义特殊字符）
    std::string escapeString(const std::string& str);
};

#endif // TESTUSERDB_H