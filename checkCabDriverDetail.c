#include<stdio.h>
#include<stdlib.h>

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

struct driver {
	int id;
	char name[20];
	char mail[20];
	char password[20];
}temp;

void checkCabDriverDetail(int id) {
	FILE *fp, *fp1;

	fp = fopen("ScheduledTrips.txt", "r");
	fp1 = fopen("cabDrivers.txt", "r");

	/*while (fread(&t, sizeof(struct trip), 1, fp) != 0) {
		printf("%d\t%d\t%d\t%s\t%s\t%s\n", t.driverid, t.userId, t.seats, t.Source, t.Destination, t.carModel);
	}*/

	printf("the Driver for your trip will be: \n");
	printf("Driver Id\tDriver Name\tDriver Mail\n");

	while (fread(&t, sizeof(struct trip), 1, fp) != 0){
		fp1 = fopen("cabDrivers.txt", "r");
		while (fread(&temp, sizeof(struct driver), 1, fp1) != 0) {
			if (id == t.userId && t.driverid == temp.id) {
				printf("%d\t%s\t%s\n", temp.id, temp.name, temp.mail);
			}
		}
	}
	fclose(fp);
	fclose(fp1);

}