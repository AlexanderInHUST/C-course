#include <stdio.h>
#include <stdbool.h>


enum Month {January=31,
			February=28, 
			March=31, 
			April=30, 
			May=31, 
			June=30, 
			July=31, 
			August=31, 
			September=30, 
			October=31, 
			November=30, 
			December=31} ;

bool isLeapYear(int year)
{
	if((year % 4==0 && year % 100!=0)||year%400==0) return true;
	return false;
}

void main()
{
	int year;
	scanf("%d", &year);
	printf("January,%d\n", January);
	printf("February,%d\n", isLeapYear(year)?(February+1):(February));
	printf("March,%d\n", March);
	printf("April,%d\n", April);
	printf("May,%d\n", May);
	printf("June,%d\n", June);
	printf("July,%d\n", July);
	printf("August,%d\n", August);
	printf("September,%d\n", September);
	printf("October,%d\n", October);
	printf("November,%d\n", November);
	printf("December,%d\n", December);
}