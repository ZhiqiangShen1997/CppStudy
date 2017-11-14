// CppStudy7.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template<typename T>
bool greater(const T& a,const T& b){
	return a > b;
}
typedef char* cstring;
//模板特化
template<>
bool greater<cstring>(const cstring& a, const cstring& b) {
	return strcmp(a, b) > 0 ? true : false;
}
//模板可以传常量
template<typename T,const int min>
bool Greater(const T& a, const T& b) {
	return a > b&&a > min;
}
int main() 
{	
	//不在调用处显示传入类型 将根据传入的参数类型产生实例函数
	cout <<"1"<< (greater(1,2)?">":"<=")<<"2"<< endl;
	char* s1 = "123", *s2 = "111";
	cout << "123" << (greater(s1, s2) ? ">" : "<=") << "111" << endl;
	cout << "52" << (Greater<int, 5>(444, 33)?"<":"<=") << "33" << endl;
	/*
		函数调用顺序
		首先选择原形完全匹配的函数
		其次选择模板函数
		最后选择参数个数相同的重载函数 自动进行类型转换
		如果都无法匹配 则报错
	*/
    return 0;
}

