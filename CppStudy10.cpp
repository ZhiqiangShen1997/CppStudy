// CppStudy10.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;

class Graphics
{
public:
	virtual double area() = 0;
	virtual void draw() { cout << "Graphics的draw()被调用" << endl; }
	virtual ~Graphics() { cout << "Graphics类对象被析构" << endl << endl; }
};

class Points : public Graphics
{
protected:
	int x;
	int y;
public:
	Points() :x(0), y(0) {}
	Points(int x0, int y0) :x(x0), y(y0) {}
	double area() {
		return 0;
	}
	void draw() {
		cout << "Points的draw()被调用" << endl;
		cout << "x=" << x << ",y=" << y << endl;
	}
	~Points() { cout << "Points类对象被析构" << endl; }
};

class Circle : public Points
{
private:
	int r;
public:
	Circle() :Points(), r(0) {};
	Circle(int x0, int y0, int r0) :Points(x0, y0), r(r0) {};
	double area() {
		return 3.14*r*r;
	};
	void draw()
	{
		cout << "Circle的draw()被调用" << endl;
		cout << "x=" << x << ",y=" << y << ",r=" << r << endl;
		cout << "Circle的面积为：" << area() << endl;
	}
	~Circle() { cout << "Circle类对象被析构" << endl; }
};

class Ellipse : public Points
{

private:
	int a;
	int b;
public:
	Ellipse() :Points(), a(0), b(0) {};
	Ellipse(int x0, int y0, int a0, int b0) :Points(x0, y0), a(a0), b(b0) {};
	double area() { return 3.14*a*b; };
	void draw()
	{
		cout << "Ellipse的draw()被调用" << endl;
		cout << "x=" << x << ",y=" << y << ",a=" << a << ",b=" << b << endl;
		cout << "Ellipse的面积为：" << area() << endl;
	}
	~Ellipse() { cout << "Ellipse类对象被析构" << endl; }
};


int main()
{
	Graphics *ptr;
	cout << "Graphics类指针指向派生类：" << endl << endl;
	ptr = new Points(1, 1);
	ptr->draw();
	delete ptr;

	ptr = new Circle(2, 2, 4);
	ptr->draw();
	delete ptr;

	ptr = new Ellipse(3, 3, 2, 1);
	ptr->draw();
	delete ptr;

	Points *p_ptr;
	cout << "Points类指针指向派生类：" << endl << endl;
	p_ptr = new Circle(4, 4, 8);
	p_ptr->draw();
	delete p_ptr;

	p_ptr = new Ellipse(6, 6, 4, 2);
	p_ptr->draw();
	delete p_ptr;

	return 0;
	/*
		运行结果：
		Graphics类指针指向派生类：
		Points的draw()被调用
		x = 1, y = 1
		Points类对象被析构
		Graphics类对象被析构

		Circle的draw()被调用
		x = 2, y = 2, r = 4
		Circle的面积为：50.24
		Circle类对象被析构
		Points类对象被析构
		Graphics类对象被析构

		Ellipse的draw()被调用
		x = 3, y = 3, a = 2, b = 1
		Ellipse的面积为：6.28
		Ellipse类对象被析构
		Points类对象被析构
		Graphics类对象被析构

		Points类指针指向派生类：

		Circle的draw()被调用
		x = 4, y = 4, r = 8
		Circle的面积为：200.96
		Circle类对象被析构
		Points类对象被析构
		Graphics类对象被析构

		Ellipse的draw()被调用
		x = 6, y = 6, a = 4, b = 2
		Ellipse的面积为：25.12
		Ellipse类对象被析构
		Points类对象被析构
		Graphics类对象被析构

	*/

}

class Graphics
{
public:
	virtual double area() = 0;
	void draw() { cout << "Graphics的draw()被调用" << endl; };
	~Graphics() { cout << "Graphics类对象被析构" << endl << endl; }
};

class Points : public Graphics
{
protected:
	int x;
	int y;
public:
	Points() :x(0), y(0) {};
	Points(int x0, int y0) :x(x0), y(y0) {};
	double area() {
		return 0;
	};
	virtual void draw() {
		cout << "Points的draw()被调用" << endl;
		cout << "x=" << x << ",y=" << y << endl;
	}
	virtual ~Points() { cout << "Points类对象被析构" << endl; }
};

class Circle : public Points
{
private:
	int r;
public:
	Circle() :Points(), r(0) {};
	Circle(int x0, int y0, int r0) :Points(x0, y0), r(r0) {};
	double area() {
		return 3.14*r*r;
	};
	void draw()
	{
		cout << "Circle的draw()被调用" << endl;
		cout << "x=" << x << ",y=" << y << ",r=" << r << endl;
		cout << "Circle的面积为：" << area() << endl;
	}
	~Circle() { cout << "Circle类对象被析构" << endl; }
};

class Ellipse : public Points
{

private:
	int a;
	int b;
public:
	Ellipse() :Points(), a(0), b(0) {};
	Ellipse(int x0, int y0, int a0, int b0) :Points(x0, y0), a(a0), b(b0) {};
	double area() { return 3.14*a*b; };
	void draw()
	{
		cout << "Ellipse的draw()被调用" << endl;
		cout << "x=" << x << ",y=" << y << ",a=" << a << ",b=" << b << endl;
		cout << "Ellipse的面积为：" << area() << endl;
	}
	~Ellipse() { cout << "Ellipse类对象被析构" << endl; }
};


int main()
{
	Graphics *ptr;
	cout << "Graphics类指针指向派生类：" << endl << endl;
	ptr = new Points(1, 1);
	ptr->draw();
	delete ptr;

	ptr = new Circle(2, 2, 4);
	ptr->draw();
	delete ptr;

	ptr = new Ellipse(3, 3, 2, 1);
	ptr->draw();
	delete ptr;

	Points *p_ptr;
	cout << "Points类指针指向派生类：" << endl << endl;
	p_ptr = new Circle(4, 4, 8);
	p_ptr->draw();
	delete p_ptr;

	p_ptr = new Ellipse(6, 6, 4, 2);
	p_ptr->draw();
	delete p_ptr;

	return 0;
	/*
		运行结果：
		Graphics类指针指向派生类：
		
		Graphics的draw()被调用
		Graphics类对象被析构

		Graphics的draw()被调用
		Graphics类对象被析构

		Graphics的draw()被调用
		Graphics类对象被析构

		Points类指针指向派生类：

		Circle的draw()被调用
		x = 4, y = 4, r = 8
		Circle的面积为：200.96
		Circle类对象被析构
		Points类对象被析构
		Graphics类对象被析构

		Ellipse的draw()被调用
		x = 6, y = 6, a = 4, b = 2
		Ellipse的面积为：25.12
		Ellipse类对象被析构
		Points类对象被析构
		Graphics类对象被析构
		*/
}
#include <iostream>
#include <string.h>
using namespace std;

class Graphics
{
public:
	virtual double area() = 0;
	void draw() { cout << "Graphics的draw()被调用" << endl; };
	~Graphics() { cout << "Graphics类对象被析构" << endl << endl; }
};

class Points : public Graphics
{
protected:
	int x;
	int y;
public:
	Points() :x(0), y(0) {};
	Points(int x0, int y0) :x(x0), y(y0) {};
	double area() {
		return 0;
	};
	void draw() {
		cout << "Points的draw()被调用" << endl;
		cout << "x=" << x << ",y=" << y << endl;
	}
	~Points() { cout << "Points类对象被析构" << endl; }
};

class Circle : public Points
{
private:
	int r;
public:
	Circle() :Points(), r(0) {};
	Circle(int x0, int y0, int r0) :Points(x0, y0), r(r0) {};
	double area() {
		return 3.14*r*r;
	};
	void draw()
	{
		cout << "Circle的draw()被调用" << endl;
		cout << "x=" << x << ",y=" << y << ",r=" << r << endl;
		cout << "Circle的面积为：" << area() << endl;
	}
	~Circle() { cout << "Circle类对象被析构" << endl; }
};

class Ellipse : public Points
{

private:
	int a;
	int b;
public:
	Ellipse() :Points(), a(0), b(0) {};
	Ellipse(int x0, int y0, int a0, int b0) :Points(x0, y0), a(a0), b(b0) {};
	double area() { return 3.14*a*b; };
	void draw()
	{
		cout << "Ellipse的draw()被调用" << endl;
		cout << "x=" << x << ",y=" << y << ",a=" << a << ",b=" << b << endl;
		cout << "Ellipse的面积为：" << area() << endl;
	}
	~Ellipse() { cout << "Ellipse类对象被析构" << endl; }
};


int main()
{
	Graphics *ptr;
	cout << "Graphics类指针指向派生类：" << endl << endl;
	ptr = new Points(1, 1);
	ptr->draw();
	delete ptr;

	ptr = new Circle(2, 2, 4);
	ptr->draw();
	delete ptr;

	ptr = new Ellipse(3, 3, 2, 1);
	ptr->draw();
	delete ptr;

	Points *p_ptr;
	cout << "Points类指针指向派生类：" << endl << endl;
	p_ptr = new Circle(4, 4, 8);
	p_ptr->draw();
	delete p_ptr;

	p_ptr = new Ellipse(6, 6, 4, 2);
	p_ptr->draw();
	delete p_ptr;
	/*
	运行结果：
	Graphics类指针指向派生类：

	Graphics的draw()被调用
	Graphics类对象被析构

	Graphics的draw()被调用
	Graphics类对象被析构

	Graphics的draw()被调用
	Graphics类对象被析构

	Points类指针指向派生类：

	Points的draw()被调用
	x=4,y=4
	Points类对象被析构
	Graphics类对象被析构

	Points的draw()被调用
	x=6,y=6
	Points类对象被析构
	Graphics类对象被析构
	
	*/
	return 0;
}
/*
分析：
程序1中的Graphics的各个函数都为虚函数
输出特点：
Graphics类指针指向其子类时调用相应函数时调用子类覆写的函数 析构时调用子类的析构函数

分析：
程序2中的Graphics只有area()以及Points的draw()和析构函数为虚函数
输出特点：
Graphics类指针指向其子类时调用draw()调用的是基类的draw() 调用析构函数时 只调用基类的析构函数
Points类指针指向其子类时调用子类中覆写的draw()以及析构时调用子类的析构函数

分析：
程序3中只有Graphics的area()为虚函数
输出特点：
Graphics类指针指向派生类时调用的draw()都是Graphics的draw() 而析构时也是调用Graphics的析构函数
Points类指针指向派生类时调用draw()时调用的是Points的draw()而析构时也是调用Points的析构函数

规律：
当基类中声明为虚函数 用基类指针指向派生类时 调用相应的函数时调用的是子类覆写的函数
当基类中未声明为虚函数 用基类指针指向派生类时 调用相应的函数时调用的是基类的函数
虚函数的性质在继承时会被子类继承下去
*/

