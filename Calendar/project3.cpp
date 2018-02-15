/*
Author: Shonel Rahim
Calendar Program:
	This program will prompt the user to input a date and birthdate. 
	The program will then output the date, day, days until the next holiday and 
	moderntime which is the number of days since January 1, 1901.
	There are only 4 holidays which will be considered: Independence day, Thanksgiving,
	the first day of school and the user inputted birthday.
	If there are no more holiday in the same year after the date the user inputs the 
	output will be the number of days until the earliest holiday in the next year.
	Leap years are taken into account when doing the calculations.
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include"date.h"
#include"holiday.h"

using namespace std;

int main(){
	
	int m,d,y;

	cout<< "Enter year(1901 or later): ";
	cin>> y;
	cout<< "Enter month(1-12): ";
	cin>> m;
	cout<< "Enter day(1-31): ";
	cin>> d;
	
	date givenDate(d,m,y);
	cout<< givenDate;
	holiday thisYear(y);
	thisYear.in_bday();//initialize birthday
	thisYear.output();//prints the 3 non-birthday holidays	
	thisYear.nextHoliday(givenDate, y); //this function prints the birthday in the current year and the next holiday
}
