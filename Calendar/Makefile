project3: date.o holiday.o project3.o
	g++ -o project3 date.o holiday.o project3.o
	
date.o: date.h date.cpp
	g++ -c date.cpp
	
holiday.o: date.h holiday.h holiday.cpp
	g++ -c holiday.cpp
	
project3.o: date.h date.cpp holiday.h holiday.cpp project3.cpp
	g++ -c project3.cpp
	
clean:
	rm project3*.o
