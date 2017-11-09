// CppStudy3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class People {
public:
	string name;
	string getName() {
		return name;
	}
	
protected:
	int age;
	string getName(string name) {
		return name;
	};
};
class Student:private People {
public:
	Student(int age);
	
	
	People::getName;
	int getAge();	
protected:
	People::age;
private:
	int id;
	People::name;
};
int Student::getAge() {
	return People::age;
}
Student::Student(int age) {
	this->age = age;
}
int main()
{
	Student student(20);
	cout << student.getAge() << endl;
	cout << student.getName("12") << endl;
    return 0;
}

