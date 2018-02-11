/*
Author: Shonel Rahim
Course: 135
Instructor: Raffi Khatchadourian
Assignment: Project3 date header file
*/
#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std; 

class date{
public:
	date(int dayIn, int monthIn, int yearIn);
	date(){};
	void alterClass(int dayIn);//alters the day of the class
	void alterYear(int yearIn);//alters the day of the class
	string weekday();//returns week day
	unsigned int modernTime();//returns modern time
	void leapYearCorrection();// makes birthday the 28 for non-leap year
	friend ostream& operator <<(ostream& outputStream, date& theDate);
	friend unsigned int operator -( date& date1, date& date2);
private:
	static string stringMon[12];
	int day, 
		month, 
		year;
	void testDate();//checks if the user inputted a valid date
	bool checkLeap();//checks if the inputted year is a leap year
	unsigned int dayInMonth(int month);
};

#endif