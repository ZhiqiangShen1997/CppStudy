// CppStudy11.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

class Quadrangle {
protected:
	string name;
public:
	virtual double area()=0;
	virtual void draw() = 0;
	virtual void what() {
		cout << name << endl;
	};
};

class Parallelogram :public Quadrangle {
protected:
	double width;
	double height;
public:
	Parallelogram() {
		width = rand() % 30;
		height = rand() % 30;
		name = "Parallelogram";
	}
	virtual double Width() {
		return width;
	}
	virtual double Height() {
		return height;
	}
	double area() {
		return width*height;
	}
	void draw() {
		cout << "length=" << width << "," << "height=" << height << endl;
	}
};

class Rect:public Parallelogram {
public:
	Rect() {
		name = "Rectangle";
	}
};

class Square :public Quadrangle {
private:
	double width;
public:
	Square() {
		width = rand() % 30;
		name = "Square";
	}
	double Width() {
		return width;
	}
	double area() {
		return width*width;
	}
	void draw() {
		cout << "length=" << width << endl;
	}
};

class Trapezoid :public Parallelogram {
private:
	double width2;
public:
	Trapezoid() {
		width2 = rand()%30;
		name = "Trapezoid";
	}
	double Width2() {
		return width2;
	}
	double area() {
		return (width+width2)*height/2;
	}
	void draw() {
		cout << "first length=" << width << "," << "second length=" << width2 << "," << "height=" << height << endl;
	}
};

class Diamond:public Parallelogram {
public:
	Diamond() {
		name = "Diamond";
	}
	double area() {
		return width*height/2;
	}
	void draw() {
		cout << "first diagonal=" << width << "," << "second diagonal=" << height << endl;
	}
};

template<typename T>
class List{
private:
	class Node {
	private:
		T data;
		Node* next;
		friend class List;
	public:
		Node(const T& data) {
			this->data = data;
		}
	};
	Node* first, *last;
public:
	List() {
	}
	~List() {
		Node* p = first;
		Node* dp;
		while (p)
		{
			dp = p;
			p = p->next;
			delete dp;
		}
	}
	int size() {
		int size = 0;
		Node* p = first;
		while (p) {
			size += 1;
			p = p->next;
		}
		return size;
	}

	void push_back(const T& data) {
		Node* node = new Node(data);
		if (last==NULL)
		{
			first = last = node;
		}
		else {
			last->next = node;
			last = node;
		}
	}

	T& operator[](int index) {
		if (index>=0&&index<size)
		{
			Node* p = first;
			for (int i = 0; i < index; i++) {
				p = p->next;
			}
			return *p;
		}
		else
		{
			return NULL;
		}
	}
	void traverse(void (*f)(T q)) {
		Node* p = first;
		while (p) {
			f(p->data);
			p = p->next;
		}
	}
	void pop_back() {
		int size = size();
		if (size !=0)
		{
			if (size==1)
			{
				delete first;
				first = last = null;
			}
			else {
				Node* p = first;
				Node* pre;
				for (int i = 0; i < size-1; i++) {
					p = p->next;
				}
				pre = p;

				p = first;
				for (int i = 0; i < size - 1; i++) {
					p = p->next;
				}
				delete p;
				last = pre;
			}
		}
	}
};

void learnQuadrangle(Quadrangle* q) {
	q->what();
	q->draw();
	cout << "please caculator the area of the quadrangle:" << endl;
	double result;
	cin >> result;
	if (result==q->area())
	{
		cout << "result correct" << endl;
	}
	else {
		cout << "result incorrect" << endl;
	}
}

int main() {
	List<Quadrangle*> quadrangles;
	string command;
	int choice;
	srand((unsigned)time(NULL));
	do
	{
		Quadrangle* q = NULL;
		choice = rand() % 5;
		switch (choice)
		{
		case 0:
			q=new Rect();
			break;
		case 1:
			q = new Square();
			break;
		case 2:
			q = new Parallelogram();
			break;
		case 3:
			q = new Trapezoid();
			break;
		case 4:
			q = new Diamond();
			break;
		}

		learnQuadrangle(q);
		quadrangles.push_back(q);

		cout << "enter stop to stop,others will continue" << endl;
		cin >> command;
	} while (command!="stop");
	
	quadrangles.traverse(&learnQuadrangle);
}


