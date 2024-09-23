#include<bits/stdc++.h>
#include"studentt.h"
using namespace std;

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

