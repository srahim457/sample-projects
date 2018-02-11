
#ifndef HOLIDAY_H
#define HOLIDAY_H

#include<iostream>
#include<cstdlib>
#include<string>
#include"date.h"

using namespace std;

class holiday{
public:
	holiday(){};
	holiday(int yearIn);
	void nextHoliday(date d1, int y);//finds next holiday
	void in_bday();//changes the class in private with the user input
	void output();//outputs all date member classes
private:
	date bday; //birthday
	date thanGiv; //thanksgiving
	date schoolDay; //first school day
	date inde_day; //independence day
};

#endif