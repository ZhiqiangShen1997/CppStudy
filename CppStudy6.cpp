// CppStudy6.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//抽象类实例 具有未实现的纯虚函数的类即为抽象类 只有声明 没有实现 交给子类去实现 类似于Java中的抽象类
//A为抽象类 
//最初的抽象类的析构函数可以是纯虚函数 但是必须要有函数体 否则将无法释放该层内存 等于最初抽象类的析构函数必须是虚构函数而不能是纯虚函数
class A {
public:
	virtual ~A() =0 ;
	virtual void f1() = 0;
	virtual void f2() = 0;
	virtual void f3() {}
	virtual void f4() = 0;
};
//可以在最初的抽象类中就实现纯虚函数 但等于没有实现 子类仍然需要实现该纯虚函数
void A::f1(){
	cout << "A f1()" << endl;
}
A::~A() {
	cout << "~A()" << endl;
}
//B只实现了纯虚函数f1 仍为抽象类
class B :public A {
public:
	~B() {
		cout << "~B()" << endl;
	}
	void f1() {
		cout << "B f1()" << endl;
	}
};
//C实现了纯虚函数f2 继承了B的f1 仍为抽象类
class C :public B {
public:
	~C() {
		cout << "~C()" << endl;
	}
	void f2() {
		cout << "C f2()" << endl;
	}
};
//D实现了纯虚函数f4 继承了C的f1和f2 覆写了继承来的f3 已经不是抽象类
class D:public C {
public:
	~D() {
		cout << "~D()" << endl;
	}
	void f3() {
		cout << "D f3()" << endl;
	}
	void f4() {
		cout << "D f4()" << endl;
	}
};
int main()
{
	//抽象类无法生成实例
	//A a;
	//B b;
	//C c;

	//D为非抽象类 可以实例化
	D d;
	
	//不可以声明抽象类对象 但可以声明抽象类对象的指针或者引用 来指向子类
	A* pA = &d;
	B& refB = d;

	//可以通过基类指针或引用访问被覆写的函数
	refB.f3();
	pA->f4();

	//D 的d 自动释放空间 按调用构造函数的反顺序调用析构函数
	

    return 0;
}

