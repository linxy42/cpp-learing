#include<iostream>
#include<string>
using namespace std;
class Student {
private:
	string m_name;
	int m_age;
	int m_number;

public:

};
int main() {
	int choice;
	while (true) {
		cout << "1添加学生" << endl;
		cout << "2查看所有学生" << endl;
		cout << "3查找学生" << endl;
		cout << "4删除学生" << endl;
		cout << "0退出" << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			return 0;
		case 1:
			cout << "该项目开发中" << endl;
			break;
		case 2:
			cout << "该项目开发中" << endl;
			break;
		case 3:
			cout << "该项目开发中" << endl;
			break;
		case 4:
			cout << "该项目开发中" << endl;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	}
	return 0;
}