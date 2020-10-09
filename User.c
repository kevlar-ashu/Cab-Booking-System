#include <stdio.h>
#include <conio.h>
#include <string.h>
#include"scheduledTrip.h"

void SignUpAsCustomer();
void LoginAsCustomer();
void Cdisplay();
void checkCabDriverDetail(int);
void checkCabDetails(int);
void bookTrip(int);
void checkBill(int);
void makePayment(int);
//void scheduleTrip(int);

struct customer {
	int id;
	char name[25];
	char mail[25];
	char password[25];
};

char dummy; int cctr = 1;

void SignUpAsCustomer() {																	//New Customer sign up, gets added to linked list
	FILE *customers;
	struct customer temp;
	char confirmPassword[20];
	customers = fopen("users.txt", "a");														//open file in append mode
	
	FILE *countuser;
	int choice;
	countuser = fopen("ccounter.txt", "a+");
	while (fread(&cctr, sizeof(int), 1, countuser) != 0) {}
	customers = fopen("users.txt", "a+");													//open file in append mode

	if (customers == NULL) {
		printf("File not created");
	}
	else {
		printf("Enter Details as Customer: \n");
		temp.id = cctr;
		printf("Enter name: \n");
		gets(temp.name);
		printf("Enter email: \n");
		gets(temp.mail);
		printf("Enter Password: \n");
		gets(confirmPassword);
		printf("Confirm Password: ");
		gets(temp.password);
		while (strcmp(temp.password, confirmPassword)) {									//re-enter password for confirmation
			printf("Password does not match\n");
			printf("Confirm Password: ");
			gets(temp.password);
		}
		printf("\n\nYour Customer ID is %d. Remember it and your password while logging in.\n\n", temp.id);
		fwrite(&temp, sizeof(struct customer), 1, customers);
		cctr++;
		fwrite(&cctr, sizeof(int), 1, countuser);
		fclose(countuser);
		fclose(customers);
	}
	
}


void LoginAsCustomer() {																		//Login as existing customer
	int Cid, Cchoice;
	struct customer temp;
	char Cpassword[20];
	printf("Enter your Customer ID: \n");
	scanf("%d", &Cid); scanf("%c", &dummy);
	printf("Enter Password: \n");
	gets(Cpassword);
	FILE *fp;
	fp = fopen("users.txt", "r");
	while (fread(&temp, sizeof(struct customer), 1, fp) != 0) {
		if (temp.id == Cid && !strcmp(Cpassword, temp.password)) {
			printf("Welcome %s\n", temp.name);
			
			while (1) {
				printf("\n\nCustomer Menu:\n1.Schedule trips\n2.Book trip\n3.Check Cab Driver Details\n4.Check Cab Details\n5.Check bill\n6.Make Payments\n0. Log Out\n");
				printf("Enter choice: ");
				scanf("%d", &Cchoice); scanf("%c", &dummy);
				switch (Cchoice) {
				case 1:printf("Schedule trips\n\n");
					ScheduleTrip(temp.id); 
					break;
				case 2:printf("Book trip\n\n"); 
					bookTrip(temp.id);
					break;
				case 3:printf("Check Cab Driver Details\n\n");
					checkCabDriverDetail(temp.id);
					break;
				case 4:printf("Check Cab Details\n\n"); 
					checkCabDetails(temp.id);
					break;
				case 5:printf("Check bill\n\n");
					checkBill(temp.id);
					break;
				case 6:printf("Make Payments\n\n"); 
					makePayment(temp.id);
					break;
				case 0:printf("Thanks for using our system. Please visit again.\n\n"); return;
				default:printf("Retry\n\n"); continue;
				}
			}
		}
	}
	/*while (fread(&temp, sizeof(struct customer), 1, fp) != 0) {
		printf("%d\t%s\t%s\n", temp.id, temp.name, temp.mail);
	}*/
	printf("Please register as a new user.\n\n");
	fclose(fp);
}

void Cdisplay() {
	struct customer temp;

	FILE *fp;
	fp = fopen("users.txt", "r");
	printf("USERS: \n");
	while (fread(&temp, sizeof(struct customer), 1, fp) != 0) {
		printf("%d\t%s\t%s\n", temp.id, temp.name, temp.mail);
	}
	fclose(fp);
}