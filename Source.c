#include <stdio.h>
#include <conio.h>
#include <string.h>
#include"dateValidation.h"

char dummy;

void main() {
	int type;
	do {
		//system("CLS");
		printf("------------------------------------------------------------------- WELCOME TO CAB BOOKING SYSTEM ------------------------------------------------------------------- \n");
		printf("What do you wish to do today: \n\n1. Register as Driver\n2. Register as Customer\n3. Login as Driver\n4. Login as Customer\n0. Quit App\n");
		printf("Enter choice: ");
		scanf("%d", &type);
		scanf("%c", &dummy);
		if (type == 1) {
			SignUpAsDriver();
		}
		else if (type == 2) {
			SignUpAsCustomer();
		}
		else if (type == 3) {
			LoginAsDriver();
		}
		else if (type == 4) {
			LoginAsCustomer();
		}
		else if (type == 5) {
			Ddisplay();
		}
		else if (type == 6) {
			Cdisplay();
		}
		else if (type == 0) {
			printf("Exiting App...\n");
			return;
		}
		else printf("Invalid Choice\n\n");
	} while (1);
	getch();
}







