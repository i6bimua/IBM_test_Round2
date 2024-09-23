# 面向对象编程结果

本次opp实验中主要进行了**student*类对*person*类的属性继承并在student中通过public中的函数访问private信息

<img src="C:\Users\33859\Pictures\Screenshots\屏幕截图 2024-09-22 232532.png" style="zoom:33%;" />

## 1.基类的定义

```c++
class person
{
public:
	void setName(string name);
	void setGender(string gender);
	void setAge(int age);
	string m_name;
	string m_gender;
	int m_age;
};
```

studentt.cpp进行基类person的定义，并赋予其m_name，m_gender，m_age成员

## 2.派生类定义

```c++
class Student:public person 
{
public:
	void setID(int id);
	int getID();
	void display();
private:
	int m_id;
};
```

studentt.cpp进行派生类student的定义，继承基类person中的m_name，m_gender，m_age成员，并添加ID，并通过public中的函数访问private中的m_id.

## 3.类中函数的实现

```
void person::setName(string name)
{
	m_name = name;
}
void person::setGender(string gender)
{
	m_gender=gender;
}
void person::setAge(int age)
{
	m_age=age;
}
void Student::setID(int id)
{
	m_id=id;
}
void Student::display()
{        
	cout <<"Name: "<<m_name<<", Age: "<<m_age<<", Gender: "<<m_gender<<", ID: "<< m_id << endl;
}
```

在studentt.cpp中进行类person和student中函数的实现.

## 4.程序的执行输出

```c++
int main()
{
	Student s;
	s.setName("czh");
	s.setAge(19);
	s.setGender("man");
	s.setID(250945);
	s.display();
```

在test1中仅进行项目的测试输出，将所有的类的声明进行拆分使得代码可读性增强。