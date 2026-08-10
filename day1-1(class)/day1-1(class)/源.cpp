#include<iostream>
#include<string>
using namespace std;
/*私有成员：name（字符串）、age（整数）
公有成员函数：setName(string n) - 设置姓名
setAge(int a) - 设置年龄（年龄不能小于0，大于150）
show() - 打印个人信息
*/
class student {
private:
	string m_name;
	int m_age;

public:
	void setName(string n) {
		m_name = n;
	}
	void setAge(int a) {
		if (a > 150 || a < 0) {
			return;
		}
		m_age = a;
	}
	void show() {
		cout << m_name << ' ' << m_age << endl;
	}

};




int main() {
	student p;
	p.setName("张三");
	p.setAge(20);
	p.show();

	// 测试边界情况
	p.setAge(-5);  // 应该拒绝
	p.show();

	return 0;
}
