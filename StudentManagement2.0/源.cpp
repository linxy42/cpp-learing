#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<limits>
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

void AgeJudgment(int &age) {
	while (true) {
		cin >> age;
		if (cin.fail()) {
			cout << "年龄格式输入错误" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
			continue;

		}
		if (age <= 0 || age > 100) {
			cout << "年龄格式有误,请重新输入" << endl;
			cout << endl;
			continue;
		}
		else {
			break;
		}
	}
}
void NumberJudgment(long long& number) {
	while (true) {
		cin >> number;
		if (cin.fail()) {
			cout << "学号格式输入错误" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
			continue;
		}
		if (number <=  0) {
			cout << "学号格式输入错误，请重新输入" << endl;
			cout << endl;
			continue;
		}
		else {
			break;
		}
	}
}
void ChoiceJudgment(int& choice) {
	while (true) {
		cin >> choice;
		if (cin.fail()) {
			cout << "菜单格式输入错误" << endl;
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (choice < 0||choice > 6) {
			cout << "菜单格式输入错误，请重新输入" << endl;
			cout << endl;
			continue;
		}
		else {
			break;
		}
	}
}

void SavedsizeJudgment(int &Savedsize) {
	while (true) {
		cin >> Savedsize;
		if (cin.fail()) {
			cout << "菜单格式输入错误" << endl;
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (Savedsize < 1 || Savedsize > 2) {
			cout << "菜单格式输入错误，请重新输入" << endl;
			cout << endl;
			continue;
		}
		else {
			break;
		}
	}
}

bool addStudent(vector<Student>& students) {
	string name;
	int age;
	long long number;
	cout << "请输入学生学号:" << endl;
	NumberJudgment(number);
	for (int i = 0; i < students.size(); i++) {
		if (students[i].GetNumber() == number) {
			cout << "学生学号已存在，请重新输入" << endl;
			return false;
		}
	}
	cout << "姓名:" << endl;
	cin >> name;
	cout << "年龄:" << endl;
	AgeJudgment(age);
	Student s(number, name, age);
	students.push_back(s);
	cout << "学生添加成功" << endl;
	cout << endl;
	return true;
}

void ShowStudent(const vector<Student> &students) {
	if (students.empty()) {
		cout << "没有学生信息，请添加学生信息" << endl;
		cout << endl;
		return ;
	}
	for (int i=0;i<students.size();i++) {
			cout << "学号:" << students[i].GetNumber() << endl;
			cout << "姓名:" << students[i].GetName() << endl;
			cout << "年龄:" << students[i].GetAge() << endl;
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
	NumberJudgment(number);
	for (int i = 0; i < students.size(); i++) {
		if (students[i].GetNumber() == number) {
			cout << "学号:" << students[i].GetNumber() << endl;
			cout << "姓名:" << students[i].GetName() << endl;
			cout << "年龄:" << students[i].GetAge() << endl;
			cout << endl;
			return;
		}
	}
		cout << "没有找到该学生，请重新输入" << endl;
		cout << endl;
}
bool DeleteStudent(vector<Student> & students) {
	if (students.empty()) {
		cout << "没有学生信息，请返回" << endl;
		return false;
	}
	cout << "请输入要删除学生的学号" << endl;
	long long number;
	NumberJudgment(number);
	for (int i=0;i<students.size();) {
		if (students[i].GetNumber() == number) {
			students.erase(students.begin()+i);
			cout << "学生信息删除成功" << endl;
			cout << endl;
			return true;
		}
		else {
			++i;
		}
	}
	cout << "没有找到该学生，请重新输入" << endl;
	cout << endl;
	return false;
}

bool SaveStudent(const vector<Student>& students) {

	ofstream ofs("students.txt", ios::out);
	if (!ofs.is_open()) {
		cout << "文件打开失败" << endl;
		cout << endl;
		return false;
	}
	for (int i=0;i<students.size();++i) {
		ofs << students[i].GetNumber() << " " << students[i].GetName() << " " << students[i].GetAge() << endl;
	}
	ofs.close();
	cout << "学生信息保存成功" << endl;
	cout << endl;
	return true;
}

void LoadStudent(vector<Student>& students) {
	ifstream ifs("students.txt", ios::in);
	if(!ifs.is_open()){
		return;
	}
	long long number;
	string name;
	int age;
	while (ifs >> number >> name >> age) {
		Student s(number, name, age);
		students.push_back(s);
	}
	ifs.close();
}

bool ModifyStudent(vector<Student>& students) {
	if (students.empty()) {
		cout << "没有学生信息，请先添加学生信息" << endl;
		cout << endl;
		return false;
	}
	cout << "请输入需要修改的学生的学号" << endl;
	long long number;
	NumberJudgment(number);
	for (int i = 0; i < students.size(); ++i) {
		if (students[i].GetNumber() == number) {
			string name;
			int age;
			cout << "请输入要修改的姓名" << endl;
			cin >> name;
			cout << "请输入要修改的年龄" << endl;
			AgeJudgment(age);
			Student s(number, name, age);
			students[i] = s;
			cout << "修改成功" << endl;
			cout << endl;
			return true;
		}
	}
	cout << "没有找到该学生信息，请重新输入" << endl;
	cout << endl;
	return false;
}

int main() {
	bool isSaved = true;
	int choice;
	vector<Student> students;
	LoadStudent(students);
	while (true) {
		cout << "1添加学生" << endl;
		cout << "2查看所有学生" << endl;
		cout << "3查找学生" << endl;
		cout << "4删除学生" << endl;
		cout << "5保存到文件" << endl;
		cout << "6修改学生信息" << endl;
		cout << "0退出" << endl;
		ChoiceJudgment(choice);
		switch (choice) {
		case 0:
			if (isSaved == false) {
				cout << "是否保存数据" << endl;
				cout << endl;
				cout << "输入1保存，输入2不保存" << endl;
				int savedsize;
				SavedsizeJudgment(savedsize);
				if (savedsize == 1) {
					if (SaveStudent(students)) {
						return 0;
					}
					else {
						cout << "文件保存失败" << endl;
						break;
					}
					
				}
				else {
					return 0;
				}
				
			}
			else {
				return 0;
			}
		case 1:
			cout << endl;
			if (addStudent(students)) {
				isSaved =false;
			}
			break;
		case 2:
			cout << endl;
			ShowStudent(students);
			break;
		case 3:
			cout << endl;
			FindStudent(students);
			break;
		case 4:
			cout << endl;
			if (DeleteStudent(students)) {
				isSaved = false;
			}
			break;
		case 5:
			cout << endl;
			if (SaveStudent(students)) {
				isSaved = true;
			}
			break;
		case 6:
			cout << endl;
			if (ModifyStudent(students)) {
				isSaved = false;
			}
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	}
	return 0;
}