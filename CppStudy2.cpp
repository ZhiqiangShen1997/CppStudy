
#include "stdafx.h"
#include <iostream>
#include<string>
using namespace std;
class Point;
class Caculator;
class People {
private:
	string name;
	
public:
	int age;
	People(string name, string country);
	People(const People& p);
	~People();
	string getName();
	void setName(const char* name);
	void setName(char* name);
	int getX(const Point& p);
	class Son;
};
class People::Son {
private:
	string name;
public:
	string getName() {
		return name;
	}
	friend string show(const People::Son& s);
};
string show(const People::Son& s) {
	return s.name;
}


string People::getName(){
	return this->name;
}
People::People(string name="Tom",string country="中国"):name(name){
	
}
People::~People() {
	cout << "~People" << endl;
}
void People::setName(const char* name) {
	char* pName = const_cast<char *>(name);
}
void People::setName(char* name) {
	const char* cName = name;
}
People::People(const People& p) {
	this->name = name;
	this->age = age;
	cout << "People(const People& p)" << endl;
}
class Point {
private:
	int x, y;
public:
	friend double mod(const Point& p);
	friend int People::getX(const Point& p);
	friend class Caculator;
};
int People::getX(const Point& p) {
	return p.x;
}
double mod(const Point& p) {
	return sqrt(p.x*p.x + p.y*p.y);
}
class Caculator {
public:
	static double getDistance(const Point& p1,const Point& p2);
};
double Caculator::getDistance(const Point& p1,const Point& p2) {
	return sqrt((p1.x-p2.x)*(p1.x - p2.x)+ (p1.y - p2.y)*(p1.y - p2.y));
}

/*int main()
{
	People p;
	People np = People();
	const People& pRef = p;
	People* pArray = new People[5];
	delete []pArray;
	People p2(p);
	
	
	int People::*pAge;
	string(People::*pGet)();

	pAge = &People::age;
	pGet = &People::getName;

	cout<<p.*pAge<<endl;
	cout << (p.*pGet)()<<endl;
	Point point;
	cout<<mod(point)<<endl;
	cout<<p.getX(point) << endl;
	
	cout<<Caculator::getDistance(point,point)<<endl;
	People::Son son;
	cout<<son.getName()<<endl;
    return 0;
}*/
class Complex
{
private:
	int real;
	int imag;
public:
	Complex(int real, int imag);
	Complex(const Complex& c);
	Complex operator +(const Complex& c);
	Complex operator -(const Complex& c);
	operator double();
	friend ostream& operator <<(ostream& o,const Complex& c);
	friend istream& operator >>(istream& i,Complex& c);
	Complex& operator +();
	Complex operator -();
	Complex operator ++(int);
	Complex& operator ++();
	Complex& operator =(const Complex& c);
	
};

Complex::Complex(int real, int imag) :real(real), imag(imag) {}

Complex::Complex(const Complex& c):real(c.real),imag(c.imag){}

Complex Complex::operator +(const Complex& c) {
	return Complex(real + c.real, imag + c.imag);
}
Complex Complex::operator -(const Complex& c) {
	return Complex(real - c.real, imag - c.imag);
}
Complex::operator double() {

	return sqrt(real*real + imag*imag);
}
ostream& operator <<(ostream& o,const Complex& c) {
	o << "(" << c.real <<","<<c.imag<<")"<< endl;
	return o;
}
istream& operator >>(istream& i, Complex& c) {
	i >> c.real >> c.imag;
	return i;
}
Complex& Complex::operator +() {
	return *this;
}
Complex Complex::operator -() {
	return Complex(-real, -imag);
}
Complex Complex::operator ++(int) {
	Complex temp=Complex(real, imag);
	real++; imag++;
	return temp;
}
Complex& Complex::operator ++() {
	real++; imag++;
	return *this;
}
Complex& Complex::operator =(const Complex& c) {
	real = c.real;
	imag = c.imag;
	return *this;
}

int main() {
	Complex c1(5,10);
	Complex c2(3, 10);
	cout << c1;

	cout << c1++;
	cout << ++c1;

	cin >> c2;
	cout << c1+c2;
	
	double mod = c1;
	cout << mod << endl;
	
	cout << -c1;

	//call copy Constructor
	Complex c3(c2);
	cout << c3;
	//call copy =
	c3 = c1;
	cout << c3;
}


