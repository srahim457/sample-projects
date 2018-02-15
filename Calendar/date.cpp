/*
Author: Shonel Rahim
	Date class that holds the day, month and year. 
	The member functions are all to make alterations and small corrections 
	such as for leap year.
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include"date.h"

using namespace std;

//date constructor
date::date(int dayIn, int monthIn, int yearIn){

	day = dayIn;
	month = monthIn;
	year = yearIn;
	testDate();
}
//static string array
string date:: stringMon[12]={"January","February", "March", 
									 "April","May","June","July","August",
									 "September","October","November","December"};
//returns the weekday
string date::weekday(){
	string days[7]={"Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday","Monday"};
	int i = modernTime()%7;

	return (days[i]); 
}
//date class outstream operator overload
ostream& operator <<(ostream& outputStream, date& theDate){
	outputStream<< theDate.weekday()
				<< " "
				<< theDate.stringMon[theDate.month-1]
				<< " "
				<< theDate.day
				<< ", "
				<< theDate.year
				<< "; "
				<< "modern time: "
				<< theDate.modernTime()
				<< endl;
		/*
		if (theDate.checkLeap()){
			outputStream<< " \n\t this is a leap year\n";
		}
		else{
			outputStream<< " \t this is not leap year\n";
		}
		*/
	return (outputStream);//cout date object
}
//returns the difference between two classes
unsigned int operator -(date& date1, date& date2){
	int diff;
	diff = date1.modernTime() - date2.modernTime();
	return (diff);
}
//tests if the year is a leap year
bool date::checkLeap(){ //checks if inputted year is a leap year
	bool leap;
	if (year%4 != 0){
			leap = false;
		}
		else if (year%100 != 0){
			leap = true;
		}
		else if (year%400 != 0){
			leap = false;
		}
		else{
			leap = true;
		}
	return (leap);
}
//tests for valid date
void date::testDate(){ //checks constructor values for valid date inputs
	
	if(year < 1901){ //check for valid year
		cout<< "invalid year value\n";
		exit(1);
	}
	else if((month < 1)||(month > 12)){ //check for valid month
		cout<< "invalid month value\n";
		exit(1);
	}

	//checking day values for the month
	else if(month == 2){ //leap year of February
		if( (checkLeap()) && ((day<1)||(day>29)) ){
			cout<< "invalid day value\n";
			exit(1);
		}
		else if( (!checkLeap()) && ((day<1)||(day>28)) ){
			cout<< "invalid day value\n";
			exit(1);
		}
	}
	//months that are 31 days
	else if((month == 1)||(month == 3)||(month == 5)||(month == 7)||(month == 8)||(month == 10)||(month == 12)){
		if ((day<1)||(day>31)){
			cout<< "invalid day value\n";
			exit(1);
		}
	}
	//months that are 30 days
	else if((month == 4)||(month == 6)||(month == 9)||(month == 11)){
		if ((day<1)||(day>30)){
			cout<< "invalid day value\n";
			exit(1);
		}
	}
}
//finds the modern time
unsigned int date::modernTime(){ 

	int sum = 0,
		common = 365,
		leap = 366;

	for(int i = 0; i < year - 1901; i++){

		int chkYear = 1901 + i;
		if (chkYear%4 != 0){
			sum += common;
		}
		else if (chkYear%100 != 0){
			sum += leap;
		}
		else if (chkYear%400 != 0){
			sum += common;
		}
		else{
			sum += leap;
		}
	}
	for(int i = month - 1; i > 0; i--){
		sum+= dayInMonth(i);
	}
	sum += day - 1;
	return (sum);
}
//finds number of days per months
unsigned int date::dayInMonth( int month ){

	if ((month == 1)||(month == 3)||(month == 5)||(month == 7)||(month == 8)||(month == 10)||(month == 12)){
		return 31;
	}
	else if((month == 4)||(month == 6)||(month == 9)||(month == 11)){
		return 30;
	}
	else if(month==2){
		if(checkLeap()){
			return 29;
		}
		else if(!checkLeap()){
			return 28;
		}
	}
	return 0;
}
//changes just the day
void date::alterClass(int dayIn){

	day = dayIn;
}
//changes the year
void date::alterYear(int yearIn){

	year = yearIn;
}
//corrects the leap birthday for a common year
void date::leapYearCorrection(){
	if ((month == 2)&&(day == 29)){
		if (!checkLeap()){
			day = 28;
		}
	}
}
