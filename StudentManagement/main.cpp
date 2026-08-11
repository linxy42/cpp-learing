#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student {
private:
	long long m_number;
	string m_name;
	int m_age;

public:
	Student( long long number,string name, int age) {
		m_number = number;
		m_name = name;
		m_age = age;
	}
	string GetName()const {
		return m_name;
	}
	int GetAge() const{
		return m_age;
	}
	long long GetNumber()const {
		return m_number;
	}
};
bool addStudent(vector<Student>& students) {
	string name;
	int age;
	long long number;
	cout << "请输入学生学号" << endl;
	cin >> number;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].GetNumber() == number) {
			return false;
		}
	}
	cout << "姓名" << endl;
	cin >> name;
	cout<< "年龄" << endl;
	cin >> age;
	Student s(number, name, age);
	students.push_back(s);
	return true;
}

int main() {
	int choice;
	vector<Student> students;
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
			if (addStudent(students)) {
				cout << "添加成功" << endl;
			}
			else {
				cout << "该学生已存在，请重新输入" << endl;
			}
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