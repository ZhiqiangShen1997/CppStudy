// CppStudy9.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//实验作业1
class List {
	
private:
	class Node {
	private:
		int data;
		Node* next;
		Node* pre;
		//声明List为Node的友元 以便访问到其内部的私有成员
		friend class List;
	public:
		Node(int data) :data(data) {}
	};
	Node* first;
	Node* last;
public:
	
	//构造函数
	List(Node* first=NULL,Node* last=NULL):first(first),last(last) {}
	
	//深复制构造函数
	List(const List& list) {
		Node* p=list.first;
		while (p) {
			push_back(p->data);
			p = p->next;
		}
	}
	
	//析构函数
	~List() {
		//clear();
	}

	//链表置空
	void clear() {
		Node* p = first;
		while (p) {
			Node* dNode = p;
			p = p->next;
			delete dNode;
		}
		first = last = NULL;
	}

	//插入结点
	List& push_back(int data) {
		Node* node = new Node(data);
		node->next = NULL;
		node->pre = NULL;

		if (first == NULL) {
			first = node;
			last = node;
		}
		else {
			last->next = node;
			node->pre = last;
			last = node;
		}
		return *this;
	}

	//删除结点
	List& pull_back(int data) {
		if (first != NULL) {
			Node* dNode = find(data);
			if (dNode!=NULL) {
				if (first == last) {
					delete dNode;
					first = last = NULL;
				} 
				else if (dNode == first) {
					dNode->next->pre = NULL;
					first = dNode->next;
					delete dNode;
				}
				else if (dNode == last) {
					dNode->pre->next = NULL;
					last = dNode->pre;
					delete dNode;
				}
				else {
					dNode->pre->next = dNode->next;
					dNode->next->pre = dNode->pre;
					delete dNode;
				}
			}
		}
		return *this;
	}

	//查找结点
	Node* find(int data) {
		Node* p=first;
		while (p) {
			if (p->data == data) {
				return p;
			}
			p = p->next;
		}
		return NULL;
	}

	//两个链表连接
	List& link(const List& list) {
		List* newList = new List(*this);
		Node* p = list.first;
		while (p) {
			newList->push_back(p->data);
			p = p->next;
		}
		return *newList;
	}
	
	//结点数据排序
	List& sort() {
		Node* p = first;
		while (p) {
			change(p);
			p = p->next;
		}
		return *this;
	}

	void change(Node* p) {
		Node* pNext = p->next;
		if (pNext) {
			if (p->data > pNext->data) {
				pNext->next->pre = p;
				pNext->pre = p->pre;
				p->pre->next = pNext;
				p->next = pNext->next;
				pNext->next = p;
			}
			change(p);
		}
	}

	//两个有序链表的合并
	List& sortMerge(const List& list) {
		Node* p1 = this->first,*p2 = list.first;
		List* newList=new List();
		while (p1&&p2) {
			if (p1->data <= p2->data) {
				newList->push_back(p1->data);
				p1 = p1->next;
			}
			else {
				newList->push_back(p2->data);
				p2 = p2->next;
			}
		}
		while (p1) { newList->push_back(p1->data); p1 = p1->next; }
		while (p2) { newList->push_back(p2->data); p2 = p2->next; }

		return *newList;
	}

	//重载+=运算符
	List& operator +=(int data) {
		push_back(data);
		return *this;
	}

	//重载运算符-=
	List& operator -=(int data) {
		pull_back(data);
		return *this;
	}

	//输出链表
	void print() {
		Node* p = this->first;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};
int main()
{
	List list1;
	
	list1 += 1;
	list1 += 2;
	list1 += 3;
	list1.print();
	
	list1 -= 3;
	list1.print();

	List list2;
	list2 += 3;
	list2 += 4;

	List newList1 = list1.link(list2);
	newList1.print();
	
	List newList2 = list1.sortMerge(list2);
	newList2.print();

	List list3 = list2;
	list3.print();
	
	List* list4 = new List();
	list4->push_back(5);
	list4->push_back(6);

	List list5 = *list4;
	delete list4;

	list5.print();

	
}

