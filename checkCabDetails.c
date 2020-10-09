#include<stdio.h>
#include<stdlib.h>

#define MAX 30

struct cabDetail {
	int carId;
	int driverId;
	char carName[MAX];
	char carNumber[MAX];
	char carModel[MAX];
	int noOfSeats;
}node;

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
	char carModel[30];
}t;

void checkCabDetails(int id)
{
	FILE *fp;
	FILE *fp1;
	FILE *tex;

	fp = fopen("ScheduledTrips.txt", "r");
	//tex = fopen("cabDetails.txt", "r");

	/*while (fread(&t, sizeof(struct cabDetail), 1, tex) != 0) {
		printf("%d\t%d\t%s\t%s\t%s\t%d\n", node.driverId, node.carId, node.carNumber, node.carName, node.carModel, node.noOfSeats);
	}
	fclose(tex);*/

	while (fread(&t, sizeof(struct trip), 1, fp) != 0) {
		fp1 = fopen("cabDetails.txt", "r");
		while (fread(&node, sizeof(struct cabDetail), 1, fp1) != 0) {
			if (t.userId == id && t.driverid == node.driverId) {
				printf("%s\t%s\t%s\t%d\n",  node.carName, node.carNumber, node.carModel, node.noOfSeats);
			}
		}
	}

	fclose(fp);
	fclose(fp1);
}