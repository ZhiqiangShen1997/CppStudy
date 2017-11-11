// CppStudy3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class People {
public:
	People(string name);
	string name;
	string getName() {
		return name;
	}
	static int number;
	
protected:
	int age;
	string getName(string name) {
		return name;
	};
};
int People::number = 0;
People::People(string name):name(name) {}
class Student:public People {
public:
	Student(int age,string name);
	//子类中定义与父类一样的成员 父类成员将被隐藏 但在权限允许的情况下仍可通过类名::成员来访问
	string name;
	string getName();
	int getAge();	
protected:
	People::age;
private:
	int id;
};
int Student::getAge() {
	return People::age;
}
string Student::getName() {
	string name = "baseName:" + People::name + "," + "studentName:" + this->name;
	return name;
}
Student::Student(int age,string name):People(name) {
	this->age = age;
	this->name = "std" + name;
	People::number=5;
}
int main()
{
	Student student(20,"shen");
	
	cout << student.getAge() << endl;
	cout << student.getName() << endl;
	
	student.number = 6;
	cout << student.number<<endl;
	cout << student.getName() << endl;
	
	People& p = student;
	//基类对象引用子类只能看到基类的成员
	//p.getAge() 对于基类来说是不存在的
	
	//指针指向子类对象 用->来访问子类对象成员
	People* pp = &student;
	//在未声明为虚函数时 通过父类对象的指针或者引用 指向子类的时候调用的方法为父类的方法
	cout << pp->getName() << endl;

	//调用基类的getName;
	cout << p.getName() << endl;
	//调用子类的getName;
	cout << student.getName() << endl;

    return 0;
}

