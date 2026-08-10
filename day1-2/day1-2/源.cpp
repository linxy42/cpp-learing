#include <iostream>
#include <string>
using namespace std;
class student {
private:
    string m_name;
    int m_age;

public:
    // 构造函数：名字和类名相同，没有返回类型
    student(string name = "无名", int age = 0) {
        m_name = name;
        if (age >= 0 && age <= 150) {
            m_age = age;
        }
        else {
            m_age = 0;
            cout << "年龄无效，已设为0" << endl;
        }
    }

    void show() {
        cout << m_name << "，年龄：" << m_age << endl;
    }
};

int main() {
    student s1("张三", 20);   // 调用带参数的构造函数
    student s2;                // 调用默认构造函数（使用了默认参数）
    s1.show();
    s2.show();
    return 0;
}