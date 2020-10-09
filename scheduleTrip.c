#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dateValidation.h"

#define MAX 30
char dummy;

struct trip {
	int driverid;
	//int carId;
	int userId;
	int seats;
	char Source[20];
	char Destination[20];
	int dd;
	int mm;
	int yyyy;
	char carModel[MAX];
};

struct cabDetail {
	int carId;
	int driverId;
	char carName[MAX];
	char carNumber[MAX];
	char carModel[MAX];
	int noOfSeats;
}node;

void ScheduleTrip(int id) {
	int choice, seats;
	int flag = 1;
	int dd, mm, yyyy;

	struct trip t;
	FILE* fp = NULL, *fp1, *fp2;
	fp = fopen("ScheduledTrips.txt", "a+");
	fp1 = fopen("cabDetails.txt", "r");
	//fp2 = fopen("ScheduledTrips.txt", "r");
	/*while (fread(&t,sizeof(struct trip),1,fp2)) {
		printf("%d\t%s\t%d\n", t.driverid, t.carModel, t.seats);
	}*/

	t.userId = id;

	printf("Source :\n");
	scanf(" ");
	gets(t.Source);

	printf("Destination :\n");
	scanf(" ");
	gets(t.Destination);

	if (!strcmp(t.Source, t.Destination))
	{
		printf("\nERROR: Source and Destination are same : \n");
		ScheduleTrip(id);
	}

	printf("Enter Date you want to travel on (DD-MM-YYYY): ");
	scanf("%d-%d-%d", &dd, &mm, &yyyy);
	int temp = dateValidation(dd, mm, yyyy);
	if (temp == 1) {
		t.dd = dd;
		t.mm = mm;
		t.yyyy = yyyy;
	}
	else {
		printf("Enter Date in given format only\n");
		ScheduleTrip(id);
	}

	printf("Enter Number of Seats :\n");
	scanf("%d", &seats);scanf("%c", &dummy);

	printf("DriverId\tNo of Seats\tCar Model\n");
	while (fread(&node, sizeof(struct cabDetail), 1, fp1) != 0) {
		if (seats == node.noOfSeats) {
			printf("%d\t%d\t%s\n", node.driverId, node.noOfSeats, node.carModel);
			flag = 0;
		}
	}
	if (flag == 1) {
		printf("No cars available\n");
		return;
	}
	
	printf("Select driver id which car you want to book\n ");
	scanf("%d", &choice);scanf("%c", &dummy);
	fp1 = fopen("cabDetails.txt", "r");
	while (fread(&node, sizeof(struct cabDetail), 1, fp1) != 0) {
		if (choice == node.driverId) {
			//carMode[MAX] = node.carModel;
			t.driverid = node.driverId;
			strcpy(t.carModel, node.carName);
			t.seats = seats;
		}
	}
		fclose(fp1);

	fwrite(&t, sizeof(struct trip), 1, fp);
	printf("Your trip has been scheduled.\n ");
	fclose(fp);
	fclose(fp1);

	/*fp = fopen("ScheduledTrips.txt", "r");
	while (fread(&t, sizeof(struct trip), 1, fp) != 0) {
		printf("%d\t%d\t%d\t%s\t%s\t%d-%d-%d\t%s\n", t.userId, t.driverid,t.seats, t.Source, t.Destination, t.dd, t.mm, t.yyyy, t.carModel);
	}
	fclose(fp);*/
}
