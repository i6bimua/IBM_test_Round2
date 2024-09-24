//所编写的类必须要体现封装和继承的特性，最好可以体现出“继承”的关系，
// 并且在主函数中创建类的对象并调⽤类的⽅法进⾏演⽰以验证事件逻辑的完整性。
// 本实验只需要完成类和对象编程的基础部分，不对事件逻辑的复杂度进⾏严格考核。

#include<iostream>
using namespace std;

class human {
public:
	string name;
	string age;
};
class student :public human {
public:
	int schoolnum=123456;
	void showstudent() {
		cout << "学生姓名：" << name << endl;
		cout << "学生年龄：" << age << endl;
		cout << "学生学号：" << schoolnum << endl;
	}
};
class teacher :public human {
public:
	int ID=456789;
	void showteacher() {
		cout << "老师姓名：" <<name<< endl;
		cout << "老师年龄：" << age << endl;
		cout << "老师职工号：" << ID << endl;
	}
};
int main() {
	student stu;
	teacher tea;
	stu.name = "Peter";
	stu.age = "18";
	tea.name = "Larry";
	tea.age = "30";
	
	stu.showstudent();
	tea.showteacher();

	return 0;
}