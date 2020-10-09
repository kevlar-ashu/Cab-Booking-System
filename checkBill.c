#include<stdio.h>

struct bookTrip{
	int driverid;
//int carId;
int userId;
int seats;
char Source[20];
char Destination[20];
int dd;
int mm;
int yyyy;
char carModel[30];
char status[30];
float fare;
}bt;

void checkBill(int id) {
	FILE *fp;
	fp = fopen("BookedTrips.txt", "r");

	//printf("UserId | Source | Destination | DD-MM-YYYY | Fare\n");
	while (fread(&bt, sizeof(struct bookTrip), 1, fp) != 0) {
		if (id == bt.userId) {
			//printf("%d\t%s\t%s\t%d-%d-%d\t%f\n", bt.userId, bt.Source, bt.Destination, bt.dd, bt.mm, bt.yyyy, bt.fare);
			printf("Your Bill Amount is: %f\n", bt.fare);
		}
	}
	fclose(fp);
}