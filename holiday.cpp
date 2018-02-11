/*
Author: Shonel Rahim
	Holiday class which holds date classes for all the holidays in the year 
	inputted by the user. The program considers 4 holidays: Independence Day, Thanksgiving, 
	the first day of school and the user's inputted birthday.
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include"date.h"
#include"holiday.h"

using namespace std;

// initializes the 3 holiday date type members 
holiday::holiday(int yearIn)
:inde_day(4,7, yearIn){ 	

	 int d, dL, November, August, count;
	 d = 1;
	 dL = 31;
	 November = 11;
	 August = 8;
	 count = 0;

	 date d1(d,November,yearIn);
	 for(int i=1; i <= 30; i++){
	 	d1.alterClass(i);
	 	if(d1.weekday()=="Thursday"){
	 		count++;
	 	}
	 	if(count==4){
	 		break;
	 	}
	 }
	 thanGiv = d1;
	 count = 0;

	 date d2(dL,August,yearIn);
	 for(int i = 31; i >= 1; i--){
	 	d2.alterClass(i);
	 	if(d2.weekday()=="Monday"){
	 		break;
	 	}
	 }
	 schoolDay = d2;
}
// inputs the birthdate
void holiday::in_bday(){
	int m,d,y;

	cout<< "Input your birthdate: \n";
	cout<< "Enter year(1901 or later): ";
	cin>> y;	
	cout<< "Enter month(1-12): ";
	cin>> m;
	cout<< "Enter day(1-31): ";
	cin>> d;

	date d1(d,m,y);

	bday = d1;
}
// outputs all the date members of holiday
void holiday::output(){
	cout<< "Independence Day is: \n"
		<< inde_day
		<< "Thanksgiving is: \n"
		<< thanGiv
		<< "The first school day is: \n"
		<< schoolDay
		<< endl;
}
// outputs the next holiday and how many days away it is
void holiday::nextHoliday(date d, int y){
	holiday nextYear(y+1); //initializes the 3 holidays of next year
	date bday_thisYear = bday; //dummy date class equal to inputted birthday
	bday_thisYear.alterYear(y); //alter to current year
	bday_thisYear.leapYearCorrection();
	
	cout<< bday_thisYear;

	nextYear.bday = bday_thisYear; //make next year and this year's birthday equal
	nextYear.bday.alterYear(y+1); //alter to next year
	nextYear.bday.leapYearCorrection();

	int h1 = bday - d, //number of days between given date and the holiday
		h2 = inde_day - d,
		h3 = schoolDay - d,
		h4 = thanGiv - d,
		h5 = nextYear.bday - d,
		h6 = nextYear.inde_day - d,
		closest = 365;
	
	int holidarray[6] = {h1,h2,h3,h4,h5,h6};

	for(int i=0; i<6; i++){
		if(holidarray[i]>0){
			if(holidarray[i]<closest){
				closest = holidarray[i];
			}
		}
	}
	cout<< "The next holiday is";
	if((h1 == closest)||(h5 == closest)){
		cout<<" your Birthday";
	}
	else if((h2 == closest)||(h6 == closest)){
		cout<<" Independence Day";
	}
	else if(h3 == closest){
		cout<<" the first day of school";
	}
	else if(h4 == closest){
		cout<<" Thanksgiving";
	}
	cout<<", which is "
		<< closest
		<< " away!\n";
}