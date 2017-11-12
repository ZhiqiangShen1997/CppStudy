// CppStudy5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//静态多态 以重写的方式实现静态多态
class Quadrangle {
public:
	string name;
	double area() const {
		return -1;
	}
};
class Parallelogram:public Quadrangle{
public:
	Parallelogram(int width, int height) :width(width), height(height) {};
	double area() const {
		return width*height;
	}
protected:
	int width;
	int height;
};
class Trapezoid:public Quadrangle {
public:
	Trapezoid(int edge1,int edge2,int height):edge1(edge1),edge2(edge2),height(height) {};
	double area() const {
		return (edge1 + edge2)*height / 2;
	}
protected:
	int edge1;
	int edge2;
	int height;
};

int main()
{
	//基类调用自己的方法
	Quadrangle q;
	cout <<"Quadrangle:"<< q.area() << endl;

	//子类对象调用覆写过的方法
	Parallelogram p(5,10);
	cout << "Parallelogram:"<<p.area() << endl;

	Trapezoid t(3,4,5);
	cout <<"Trapezoid:"<< t.area() << endl;

	//在基类的方法未声明为虚函数的情况下 父类对象指针指向子类 调用的是基类的方法
	Quadrangle *qp;
	qp = &p;
	cout<<"parent pointer call area:"<<qp->area()<<endl;
	qp = &t;
	cout << "parent pointer call area:" << qp->area() << endl;

    return 0;
}

