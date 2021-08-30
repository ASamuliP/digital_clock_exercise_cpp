#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <string>



int main() {
	
	int sec_prev = 0;
	while (1)
	{
		int seconds, minutes, hours;
		
		std::string str;

		//storing total seconds
		
		time_t totals_seconds = time(0);

		//getting values of seconds, minutes and hours

		struct tm* ct = localtime(&totals_seconds);

		seconds = ct->tm_sec;
		minutes = ct->tm_min;
		hours = ct->tm_hour;

		//converting it into 12 hour format

		if (hours>=12) 
			str = "PM";
		else
			str = "AM";
		


		//printing the result
		if (seconds == sec_prev + 1 || (sec_prev == 59 && seconds == 0))
		{
			system("CLS");
			std::cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << str << std::endl;
		}

		sec_prev = seconds;


	}
	return 0;
}