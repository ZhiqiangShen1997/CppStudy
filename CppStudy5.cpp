// CppStudy5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
//静态多态 以重写的方式实现静态多态
class Quadrangle {
public:
	string name;
	double area() const {
		return -1;
	}
	//虚函数实现动态多态
	virtual void draw() {
		cout << "" << endl;
	}
};
class Parallelogram:public Quadrangle{
public:
	Parallelogram(int width, int height) :width(width), height(height) {};
	double area() const {
		return width*height;
	}
	void draw() {
		cout << "width:" << width << ",height:" << height<<endl;
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
	void draw() {
		cout << "edge1:" << edge1 << ",edge2:" << edge2 << ",height:" << height<<endl;
	}
protected:
	int edge1;
	int edge2;
	int height;
};
//虚函数的特性后代都将继承 如果某些子代未覆写 则将继续传递给子代 
//未覆写的子代 调用该函数时则将调用从父类继承来的
class Trangle {
public:
	virtual void draw() {
		cout << "trangle" << endl;
	}
};
class RightTrangle:public Trangle {
	//注意函数原型不相同 不能覆写
	void draw(string name) {
		cout << name << endl;
	}
};
class IsoRightTrangle:public RightTrangle {
	void draw() {
		cout << "iso right trangle" << endl;
	}
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

	//当基类的函数声明为虚函数 父类对象指针/引用 指向子类 调用的是子类覆写的函数 如果没有覆写 则调用基类函数
	Quadrangle& refP = p;
	Quadrangle& refT = t;
	
	qp = &p;
	qp->draw();
	refP.draw();

	qp = &t;
	qp->draw();
	refT.draw();

	RightTrangle rightTrangle;
	IsoRightTrangle isoRightTrangle;

	Trangle* pt = &rightTrangle;
	//RightTrangle未覆写基类虚函数 通过基类指针调用该函数时调用继承来的函数
	pt->draw();
	//IsoRightTrangle 基类未覆写虚函数 将该虚函数继续传递给当前子类 当前子类覆写基类虚函数 通过基类指针调用该函数时调用覆写的函数
	pt = &isoRightTrangle;
	pt->draw();
	

    return 0;
}

