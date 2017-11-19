// CppStudy8.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//作业3
class Rectangle {
private:
	double length;
	double width;
public:
	//构造函数
	Rectangle(double len=0,double wid=0);
	//拷贝构造函数
	Rectangle(const Rectangle& r);
	
	//求面积
	double area();

	//类成员函数重载=
	Rectangle& operator =(const Rectangle& r);
	//类成员函数重载+
	double operator +(const Rectangle& r);
	//类成员函数重载-
	double operator -(const Rectangle& r);
	
	//类成员函数重载前缀++
	Rectangle& operator ++();
	//类成员函数重载后缀++
	Rectangle operator ++(int);
	
	//类成员函数重载前缀--
	Rectangle& operator --();
	//类成员函数重载后缀--
	Rectangle operator --(int);
	
	//类成员函数重载+=
	Rectangle& operator +=(const Rectangle& r);
	//类成员函数重载-=
	Rectangle& operator -=(const Rectangle& r);

	//类成员函数重载==
	int operator ==(const Rectangle& r);
	//类成员函数重载>
	int operator >(const Rectangle& r);
	//类成员函数重载<
	int operator <(const Rectangle& r);

	//友元函数重载+
	friend double operator +(const Rectangle& r1, const Rectangle& r2);
	//友元函数重载-
	friend double operator -(const Rectangle& r1, const Rectangle& r2);

	//友元函数重载前缀++
	friend Rectangle& operator++(Rectangle& r);
	//友元函数重载后缀++
	friend Rectangle operator++(Rectangle& r,int);
	
	//友元函数重载前缀--
	friend Rectangle& operator--(Rectangle& r);
	//友元函数重载后缀--
	friend Rectangle operator--(Rectangle& r, int);

	//友元函数重载+=
	friend Rectangle& operator +=(Rectangle& r1, const Rectangle& r2);
	//友元函数重载-=
	friend Rectangle& operator -=(Rectangle& r1, const Rectangle& r2);

	//友元函数重载==
	friend int operator ==(const Rectangle& r1, const Rectangle& r2);
	//友元函数重载>
	friend int operator >(const Rectangle& r1, const Rectangle& r2);
	//友元函数重载<
	friend int operator <(const Rectangle& r1, const Rectangle& r2);

};
//实现构造函数
Rectangle::Rectangle(double len, double wid):length(len),width(wid) {}
//实现拷贝构造函数
Rectangle::Rectangle(const Rectangle& r) {
	length = r.length;
	width = r.width;
}
//实现求面积函数
double Rectangle::area() {
	return length*width;
}

//实现类成员函数重载=
Rectangle& Rectangle::operator =(const Rectangle& r) {
	length = r.length;
	width = r.width;
	return *this;
}
//实现类成员函数重载+
double Rectangle::operator +(const Rectangle& r) {
	return width*length + r.width*r.length;
}
//实现类成员函数重载-
double Rectangle::operator -(const Rectangle& r) {
	return width*length - r.width*r.length;
}

//实现类成员函数重载前缀++
Rectangle& Rectangle::operator ++() {
	length++; width++;
	return *this;
}
//实现类成员函数重载后缀++
Rectangle Rectangle::operator ++(int) {
	Rectangle temp(length, width);
	length++; width++;
	return temp;
}

//实现类成员函数重载前缀--
Rectangle& Rectangle::operator --() {
	length--; width--;
	return *this;
}
//实现类成员函数重载后缀--
Rectangle Rectangle::operator --(int) {
	Rectangle temp(length, width);
	length--; width--;
	return temp;
}

//实现类成员函数重载+=
Rectangle& Rectangle::operator +=(const Rectangle& r) {
	length += r.length;
	width += r.width;
	return *this;
}
//实现类成员函数重载-=
Rectangle& Rectangle::operator -=(const Rectangle& r) {
	length -= r.length;
	width -= r.width;
	return *this;
}

//实现类成员函数重载==
int Rectangle::operator ==(const Rectangle& r) {
	return length*width == r.length*r.width;
}
//实现类成员函数重载>
int Rectangle::operator >(const Rectangle& r) {
	return length*width > r.length*r.width;
}
//实现类成员函数重载<
int Rectangle::operator <(const Rectangle& r) {
	return length*width < r.length*r.width;
}

//实现友元函数重载+
double operator +(const Rectangle& r1, const Rectangle& r2) {
	return r1.length*r1.width + r1.length*r1.width;
}
//实现友元函数重载-
double operator -(const Rectangle& r1, const Rectangle& r2) {
	return r1.length*r1.width - r1.length*r1.width;
}

//实现友元函数重载前缀++
Rectangle& operator++(Rectangle& r) {
	r.length++; r.width++;
	return r;
}
//实现友元函数重载后缀++
Rectangle operator++(Rectangle& r, int) {
	Rectangle temp(r.length, r.width);
	r.length++; r.width++;
	return temp;
}

//实现友元函数重载前缀--
Rectangle& operator--(Rectangle& r) {
	r.length--; r.width--;
	return r;
}
//实现友元函数重载后缀--
Rectangle operator--(Rectangle& r, int) {
	Rectangle temp(r.length, r.width);
	r.length--; r.width--;
	return temp;
}

//实现友元函数重载+=
Rectangle& operator +=(Rectangle& r1, const Rectangle& r2) {
	r1.length += r2.length;
	r1.width += r2.width;
	return r1;
}
//友元函数重载-=
Rectangle& operator -=(Rectangle& r1, const Rectangle& r2) {
	r1.length += r2.length;
	r1.width += r2.width;
	return r1;
}

//实现友元函数重载==
int operator ==(const Rectangle& r1, const Rectangle& r2) {
	return r1.length*r1.width == r2.length*r2.width;
}
//实现友元函数重载>
int operator >(const Rectangle& r1, const Rectangle& r2) {
	return r1.length*r1.width > r2.length*r2.width;
}
//实现友元函数重载<
int operator <(const Rectangle& r1, const Rectangle& r2) {
	return r1.length*r1.width < r2.length*r2.width;
}

int main()
{
	Rectangle r1(10, 5);
	Rectangle r2(20, 10);

	/*
	分析拷贝构造函数和重载运算符的区别
	拷贝构造函数是由已知对象生成新的对象
	重载运算符是在=左边对象已经有实例的情况用=来将右侧的对象复制到对象来
	*/
	
	//此处是在r3通过已有对象来创建实例 调用拷贝构造函数
	Rectangle r3 = r1;
	cout << "Rectangle r3=r1;  r3 get instance from exist object ,call copy constructor" << endl;
	cout << "r1 area:" << r1.area() << ",r3 area:" << r3.area() << endl;
	//此处是r3已经被实例化过的情况下将右边对象赋值给左边对象 调用重载运算符=
	r3 = r2;
	cout << "r3=r2; r3 has had instance and use = to copy ,call override operator= " << endl;
	cout << "r2 area:" << r2.area() << ",r3 area:" << r3.area() << endl;
	
}

