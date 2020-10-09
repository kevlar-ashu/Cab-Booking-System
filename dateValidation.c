#include<stdio.h>

int dateValidation(int dd, int mm, int yyyy) {
	//check year
	if (yyyy >= 1900 && yyyy <= 9999) {
		//check month
		if (mm >= 01 && mm <= 12) {
			if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)){
			return 1;
			}
			else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11)) {
				return 1;
			}
			else if ((dd >= 1 && dd <= 28) && (mm == 2)) {
				return 1;
			}
			else if (dd == 29 && mm == 2 && (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))) {
				return 1;
			}
			else {
				return 1;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
	return 0;
}