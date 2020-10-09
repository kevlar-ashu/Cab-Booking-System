#include <stdio.h>
#include <conio.h>
#include <string.h>

void SignUpAsDriver();
void LoginAsDriver();
void Ddisplay();
void updateProfile(int);
void manageCarDetails(int);
void checkScheduleTrip(int);
void checkBookTrip(int);

struct driver {
	int id;
	char name[20];
	char mail[20];
	char password[20];
};

//struct amancabDetail {
//	int carId;
//	char carName[30];
//	char carNumber[30];
//}node;

char dummy; int dctr = 1;

void SignUpAsDriver() {																		//New Driver sign up, gets added to linked list
	FILE *drivers;
	struct driver temp;
	char confirmPassword[20];

	FILE *countdriver;
	int choice;
	countdriver = fopen("dcounter.txt", "a+");
	while (fread(&dctr, sizeof(int), 1, countdriver) != 0) {}
	drivers = fopen("cabDrivers.txt", "a+");													//open file in append mode
	
	if (drivers == NULL) {
		printf("File not created");
	}
	else {
		printf("Enter Details as Driver: \n");
		temp.id = dctr;
		printf("Enter name: \n");
		gets(temp.name);
		printf("Enter email: \n");
		gets(temp.mail);
		printf("Enter Password: \n");
		gets(confirmPassword);
		printf("Confirm Password: ");														//re-enter password for confirmation
		gets(temp.password);
		while (strcmp(temp.password, confirmPassword)) {
			printf("Password does not match\n");
			printf("Confirm Password: ");
			gets(temp.password);
		}
		printf("\n\nYour Driver ID is %d. Remember it and your password while logging in: \n\n\n", temp.id);
		fwrite(&temp, sizeof(struct driver), 1, drivers);
		dctr++;
		fwrite(&dctr, sizeof(int), 1, countdriver);
		
		fclose(countdriver);
		fclose(drivers);
		
	}
	
}




void LoginAsDriver() {																		//Login as existing driver
	int Did, Dchoice, count;
	char Dpassword[20];
	struct driver temp;
	printf("Enter Driver ID id: \n");
	scanf("%d", &Did); scanf("%c", &dummy);
	printf("Enter Password: \n");
	gets(Dpassword);
	FILE *fp;
	fp = fopen("cabDrivers.txt", "r");
	while (fread(&temp, sizeof(struct driver), 1, fp) != 0) {
		if (temp.id == Did && !strcmp(Dpassword, temp.password)) {
			printf("Welcome %s\n", temp.name);
			
			while (1) {
				printf("\n\nDriver Menu:\n1. Update Profile\n2. Manage Car Details\n3. Check Scheduled Trips\n4. Check Booked Trips\n5. Marked Completed Trips\n0. Log Out\n");
				printf("Enter choice: ");
				scanf("%d", &Dchoice); scanf("%c", &dummy);
				switch (Dchoice) {
				case 1:printf("Update Profile\n\n"); updateProfile(temp.id); break;

				case 2:printf("Manage Car Details\n\n");manageCarDetails(temp.id); break;

				case 3:printf("Check Scheduled Trips\n\n");checkScheduleTrip(temp.id); break;

				case 4:printf("Check Booked Trips\n\n");checkBookTrip(temp.id); break;

				case 5:printf("Marked Completed Trips\n\n"); break;

				case 0:printf("\n\nThanks for using our system. Please visit again....\n\n"); return;

				default:printf("Retry\n"); break;
				}
			}
		}
	}
	/*while (fread(&temp, sizeof(struct driver), 1, fp) != 0) {
		printf("%d\t%s\t%s\n", temp.id, temp.name, temp.mail);
	}*/

	/*FILE *fp2;
	fp2 = fopen("carDetails.txt", "r");
	while (fread(&node, sizeof(struct amancabDetail), 1, fp2) != 0) {
		printf("%d \t %s \t %s\n", node.carId, node.carName, node.carNumber);
	}*/

	printf("Please register as a new driver.\n\n");
	fclose(fp);
}

void Ddisplay() {
	struct driver temp;

	FILE *fp;
	fp = fopen("cabDrivers.txt", "r");
	printf("DRIVERS: \n");
	while (fread(&temp, sizeof(struct driver), 1, fp) != 0) {
		printf("%d\t%s\t%s\n", temp.id, temp.name, temp.mail);
	}
}