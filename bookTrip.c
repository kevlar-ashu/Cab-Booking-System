#include<stdio.h>

struct bookTrip {
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

void bookTrip(int id)
{
	FILE *fp;
	fp = fopen("BookedTrips.txt", "r");
	printf("UserID | Source | Destination | Seats | Fare\n");
	while (fread(&bt, sizeof(struct bookTrip), 1, fp) != 0) {
		if (id == bt.userId) {
			printf("%d\t%s\t%s\t%d\t%f\n", bt.userId, bt.Source, bt.Destination, bt.seats, bt.fare);
		}
	}
	fclose(fp);
}