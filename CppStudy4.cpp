// CppStudy4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//多继承实例
class A {
public:
	A(int a);
	~A();
private:
	int a;
};
A::A(int a) {
	cout << "Constructor A " + a << endl;
}
A::~A() {
	cout << "~A()" << endl;
}
class B {
public:
	B(int b);
	~B();
private:
	int b;
};
B::B(int b) {
	cout << "Constructor B " + b << endl;
}
B::~B() {
	cout << "~B()" << endl;
}
class C {
public:
	C();
	~C();
};
C::C() {
	cout << "Constructor C *" << endl;
}
C::~C() {
	cout << "~C()" << endl;
}
class D :public A, public B, public C {
public:
	D(int a, int b, int c, int d);
	~D();
	A ma;
	B mb;
	C mc;
};
//无论初始化列表按什么顺序写 构造函数的调用按照继承顺序完成 对象成员的初始化按照在类中声明顺序完成
D::D(int a, int b, int c, int d) :mb(c), B(a), A(b), ma(d) {
	cout << "Constructor D..." << endl;
}
D::~D() {
	cout << "~D()" << endl;
}
//隐藏基类成员实例
class B1 {
public:
	int nV;
	void fun() {
		cout << "Member of B1"<< endl;
		cout << nV << endl;
	}
};
class B2 {
public:
	int nV;
	void fun() {
		cout << "Member of B2"<< endl;
		cout << nV << endl;
	}
};
class C1 :public B1, public B2 {
public:
	int nV;
	void fun() {
		cout << "Member of C1"<< endl;
		cout << nV << endl;
	}
};
//二义性问题1
class E1 {
public:
	void f();
};
class E2 {
public:
	void f();
	void g();
};
class E3: public E1,public E2{
public:
	void g();
};
//二义性问题2
class F {
public:
	int f;
};
class F1:public F {
private:
	int f1;
};
class F2:public F {
private:
	int f2;
};
class F3:public F1,public F2 {
	
};
int main()
{
	//初始化多继承对象
	D d(1, 2, 3, 4);
	
	 /*
	 初始化顺序应为A(2),B(1),C(),A(4),B(3),C();
	 析构函数的调用与构造函数的调用顺序相反
	 因为是用栈在管理对象生命周期
	 析构顺序为~D() ~C() ~B() ~A() ~C() ~B() ~A();
	 */

	C1 c1;
	c1.nV = 1;
	c1.fun();
	
	//子类对象访问被隐藏的基类成员
	c1.B1::nV = 2;
	c1.B1::fun();

	c1.B2::nV = 3;
	c1.B2::fun();
	
	E3 e3;
	
	//无二义性
	e3.g();

	//存在二义性
	//e3.f();

	/*
		解决方法
		1.通过类名限定
		2.在E3类中声明一个f函数 根据不同情况进行调用
		void f(){
			switch(condition){
				case condition1:
					E1::f();
					break;
				case condition2:
					E2::f();
					break;
			}
		}
	*/
	e3.E1::f();
	e3.E2::f();

	F3 f3;
	//有二义性
	//f3.f;
	//f3.B::f;
	/*
		F1继承F
		F2继承F
		F3继承F1和F2
		继承关系从下到上
		F	F
		F1	F2
		  F3
		则F3有两个基类F
		有两个继承来的f
	*/
	//无二义性
	f3.F1::f;
	f3.F2::f;

    return 0;
}

