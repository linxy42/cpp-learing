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
	Student(long long number, string name, int age) {
		m_number = number;
		m_name = name;
		m_age = age;
	}
	string GetName()const {
		return m_name;
	}
	int GetAge() const {
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
	cout << "年龄" << endl;
	cin >> age;
	Student s(number, name, age);
	students.push_back(s);
	return true;
}

void ShowStudent(const vector<Student> &students) {
	if (students.empty()) {
		cout << "没有学生信息，请添加学生信息" << endl;
		cout << endl;
		return ;
	}
	for (int i=0;i<students.size();i++) {
			cout << "学号" << students[i].GetNumber() << endl;
			cout << "姓名" << students[i].GetName() << endl;
			cout << "年龄" << students[i].GetAge() << endl;
			cout << endl;
	}
}

void FindStudent(const vector<Student> &students) {
	long long number;
	if (students.empty()) {
		cout << "没有学生信息，请添加学生信息" << endl;
		cout << endl;
		return;
	}
	cout << "请输入要查找学生的学号" << endl;
	cin >> number;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].GetNumber() == number) {
			cout << "学号" << students[i].GetNumber() << endl;
			cout << "姓名" << students[i].GetName() << endl;
			cout << "年龄" << students[i].GetAge() << endl;
			cout << endl;
			return;
		}
	}
		cout << "没有找到该学生，请重新输入" << endl;
		cout << endl;
}
void DeleteStudent(vector<Student> & students) {
	if (students.empty()) {
		cout << "没有学生信息，请返回" << endl;
		return;
	}
	cout << "请输入要删除学生的学号" << endl;
	long long number;
	cin >> number;
	for (int i=0;i<students.size();) {
		if (students[i].GetNumber() == number) {
			students.erase(students.begin()+i);
			cout << "学生信息删除成功" << endl;
			return;
		}
		else {
			++i;
		}
	}
	cout << "没有找到该学生，请重新输入" << endl;
	cout << endl;
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
			ShowStudent(students);
			break;
		case 3:
			FindStudent(students);
			break;
		case 4:
			DeleteStudent(students);
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	}
	return 0;
}