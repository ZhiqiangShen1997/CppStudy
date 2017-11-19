

#include "stdafx.h"
#include <iostream>
using namespace std;
class Date {
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int getMonthDay(int month,int year);
public:
	Date(int year,int month,int day,int hour,int minute,int second);

	Date(const Date& date);

	void showDate();

	void addSecond(int second);
	void addMinute(int minute);
	void addHour(int hour);
	void addDay(int day); 
	void addMonth(int month);
	void addYear(int year);

	void reduceSecond(int second);
	void reduceMinute(int minute);
	void reduceHour(int hour);
	void reduceDay(int day);
	void reduceMonth(int month);
	void reduceYear(int year);
};
Date::Date(int year=2000, int month=1, int day=1, int hour=0, int minute=0, int second=0) {
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}
Date::Date(const Date& date) {
	this->year = date.year;
	this->month = date.month;
	this->day = date.day;
	this->hour = date.hour;
	this->minute = date.minute;
	this->second = date.second;
}
void Date::showDate() {
	printf("%d-%02d-%02d %02d:%02d:%02d\n", this->year, this->month, this->day, this->hour, this->minute, this->second);
}
void Date::addYear(int year) {
	this->year += year;
	if (this->year > 9999) {
		this->year = 2000;
		cout << "The year overflow,reset to 2000"<<endl;
	}
}
void Date::addMonth(int month) {
	this->month += month;

	while (this->month > 12) {
		this->month -= 12;
		this->addYear(1);
	}
}
void Date::addDay(int day) {
	this->day += day;
	
	int monthDay = getMonthDay(this->month, this->year);
	
	while (this->day > monthDay) {
		this->addMonth(1);
		this->day -= monthDay;
		monthDay = getMonthDay(this->month,this->year);
	}
}
void Date::addHour(int hour) {
	this->hour += hour;

	while (this->hour >=24) {
		this->hour -= 24;
		this->addDay(1);
	}
}
void Date::addMinute(int minute) {
	this->minute += minute;

	while (this->minute >= 60) {
		this->minute -= 60;
		this->addHour(1);
	}
}
void Date::addSecond(int second) {
	this->second += second;
	while (this->second >= 60) {
		this->second -= 60;
		this->addMinute(1);
	}
}
void Date::reduceYear(int year) {
	this->year -= year;
	while (this->year < 1) {
		this->year = 2000;
		cout << "The year underflow,reset to 2000" << endl;
	}
}
void Date::reduceMonth(int month) {
	this->month -= month;
	while (this->month <= 0) {
		this->month += 12;
		this->reduceYear(1);
	}
}
void Date::reduceDay(int day) {
	this->day -= day;
	while (this->day <=0) {
		this->reduceMonth(1);
		int monthDay = this->getMonthDay(this->month,this->year);
		this->day += monthDay;
	}
}
void Date::reduceHour(int hour) {
	this->hour -= hour;
	while (this->hour < 0) {
		this->hour += 24;
		this->reduceDay(1);
	}
}
void Date::reduceMinute(int minute) {
	this->minute -= minute;
	while (this->minute < 0) {
		this->minute += 60;
		this->reduceHour(1);
	}
}
void Date::reduceSecond(int second) {
	this->second -= second;
	while (this->second < 0) {
		this->second += 60;
		this->reduceMinute(1);
	}
}
int Date::getMonthDay(int month, int year) {
	int monthDay;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		monthDay = 31;
	}
	else if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			monthDay = 29;
		}
		else {
			monthDay = 28;
		}
	}
	else {
		monthDay = 30;
	}
	return monthDay;
}




class singleInstanceClass {
private:
	static singleInstanceClass* singleInstance;
	singleInstanceClass();
public:
	static singleInstanceClass* getInstance();
	int flag;
};
singleInstanceClass* singleInstanceClass::singleInstance = NULL;

singleInstanceClass::singleInstanceClass() {}

singleInstanceClass* singleInstanceClass::getInstance(){
	if (singleInstance == NULL) {
		singleInstance = new singleInstanceClass();
	}
	return singleInstance;
}

int main(void){
	cout << "---question one---" << endl;
	Date date(2017,10,20,18,5,34);
	cout << "Create a new date,print the date:" << endl;
	date.showDate();
	
	Date copyDate = date;
	cout << "Clone a date,print the clone date:" << endl;
	copyDate.showDate();

	date.addSecond(3600);
	cout << "add 3600secs:" << endl;
	date.showDate();
	
	date.addMinute(800);
	cout << "add 800mins:" << endl;
	date.showDate();

	date.addHour(24);
	cout << "add 24 hours:" << endl;
	date.showDate();

	date.addDay(20);
	cout << "add 20 days:" << endl;
	date.showDate();

	date.addMonth(30);
	cout << "add 30 months:" << endl;
	date.showDate();

	date.addYear(10);
	cout << "add 10 years:" << endl;
	date.showDate();

	date.reduceSecond(333);
	cout << "reduce 333 secs:" << endl;
	date.showDate();

	date.reduceMinute(34);
	cout << "reduce 34 secs:" << endl;
	date.showDate();

	date.reduceHour(100);
	cout << "reduce 100 hours:" << endl;
	date.showDate();

	date.reduceDay(45);
	cout << "reduce 45 days:" << endl;
	date.showDate();

	date.reduceMonth(80);
	cout << "reduce 80 months:" << endl;
	date.showDate();

	date.reduceYear(50);
	cout << "reduce 50 years:" << endl;
	date.showDate();
	cout << endl;
	cout << endl;

	cout << "---question two---" << endl;
	singleInstanceClass* s1 = singleInstanceClass::getInstance();
	singleInstanceClass* s2 = singleInstanceClass::getInstance();
	
	s1->flag = 1;

	if (s1 == s2) {
		cout << "singleInstance-->true" << endl;
		cout << "s1-->flag " << s1->flag << endl;
		cout << "s2-->flag " << s2->flag << endl;
	}
	else {
		cout << "singleInstance-->false" << endl;
		cout << "s1-->flag " << s1->flag << endl;
		cout << "s2-->flag " << s2->flag << endl;
	}

	delete s1;
	return 0;
}
