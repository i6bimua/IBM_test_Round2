#pragma once
#include<bits/stdc++.h>
using namespace std;

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
class Student:public person 
{
public:
	void setID(int id);
	int getID();
	void display();
private:
	int m_id;
};



