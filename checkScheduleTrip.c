#include<stdio.h>
#include <time.h>

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

FILE *fp;

void checkScheduleTrip(int id)
{
	int ch;

	FILE *fp1, *fp2;

	fp = fopen("BookedTrips.txt", "a+");
	fp1 = fopen("ScheduledTrips.txt", "r");
	// variables to store date and time components
	int  day, month, year;
	// time_t is arithmetic time type
	time_t now;
	// Obtain current time
	// time() returns the current time of the system as a time_t value
	time(&now);

	// localtime converts a time_t value to calendar time and 
	// returns a pointer to a tm structure with its members 
	// filled with the corresponding values
	struct tm *local = localtime(&now);

	day = local->tm_mday;        	// get day of month (1 to 31)
	month = local->tm_mon + 1;   	// get month of year (0 to 11)
	year = local->tm_year + 1900;	// get year since 1900

	// print current date
	//printf("Date is : %02d-%02d-%d\n", day, month, year);
	printf("DriverId | User ID | Source | Dest. | Date\n");
	while (fread(&t, sizeof(struct trip), 1, fp1) != 0) {
		if (t.driverid == id){					//(day == t.dd && month == t.mm && year == t.yyyy && t.driverid == id) {
			printf("%d\t%d\t%s\t%s\t%d-%d-%d\n", t.driverid, t.userId, t.Source, t.Destination, t.dd, t.mm, t.yyyy);
		}
	}
	fclose(fp1);

	fp1 = fopen("ScheduledTrips.txt", "r");

	printf("Choose user(userId) trip you want to proceed\n");
	scanf("%d", &ch);

	while (fread(&t, sizeof(struct trip), 1, fp1) != 0) {
		if (t.userId == ch && t.driverid == id) {
			bt.driverid = id;
			bt.userId = t.userId;
			strcpy(bt.Source, t.Source);
			strcpy(bt.Destination, t.Destination);
			bt.dd = t.dd;
			bt.mm = t.mm;
			bt.yyyy = t.yyyy;
			strcpy(bt.carModel, t.carModel);
			bt.seats = t.seats;
			bt.fare = 100 * t.seats;
			strcpy(bt.status, "booked");
			fwrite(&bt, sizeof(struct bookTrip), 1, fp);
		}
	}
	fclose(fp1);
	fclose(fp);

	/*fp = fopen("BookedTrips.txt", "r");
	fp2 = fopen("dummy.txt", "w");*/

	/*while (fread(&t, sizeof(struct trip), 1, fp1) != 0) {
		fp = fopen("BookedTrips.txt", "r");
		while (fread(&bt, sizeof(struct bookTrip), 1, fp) != 0){
			if (bt.userId == t.userId && bt.driverid == t.driverid) {
				continue;
			}
			else {
				fwrite(&t, sizeof(struct trip), 1, fp2);
			}
		}
	}*/
	/*fclose(fp);
	fclose(fp1);
	fclose(fp2);*/
}