
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

struct payment {
	int userid;
	char modeOfPayment[20];
	float billAmount;
	char statusOfPayment[20];
}p;

void makePayment(int id) {
	
	int ch;
	float bill;
	FILE *fp;
	FILE *fp1;
	fp = fopen("BookedTrips.txt", "r");
	while (fread(&bt, sizeof(struct bookTrip), 1, fp) != 0) {
		if (id == bt.userId) {
			bill = bt.fare;
			printf("Your Bill Amount is: %f\n", bt.fare);
		}
	}

	fp1 = fopen("payments.txt", "a+");
	
	printf("How you want to make your payment\n");
	printf("1.Credit Card\n");
	printf("2.Debit Card\n");
	printf("3.Cash\n");

	printf("Enter your choice\n");
	scanf("%d", &ch);

	switch (ch) {
		case 1:
			p.userid = id;
			strcpy(p.modeOfPayment, "Credit Card");
			p.billAmount = bill;
			strcpy(p.statusOfPayment, "paid");
			break;
		case 2:
			p.userid = id;
			strcpy(p.modeOfPayment, "Debit Card");
			p.billAmount = bill;
			strcpy(p.statusOfPayment, "paid");
			break;
		case 3:
			p.userid = id;
			strcpy(p.modeOfPayment, "Cash");
			p.billAmount = bill;
			strcpy(p.statusOfPayment, "paid");
			break;
		default:
			printf("Enter Correct choice for Payment\n\n");
			break;
	}
	fwrite(&p, sizeof(struct payment), 1, fp1);

	fclose(fp);
	fclose(fp1);

	fp1 = fopen("payments.txt", "a+");

	printf("User id | Mode Of Payment | Bill Amount | Status Of Payment\n");
	while (fread(&p, sizeof(struct payment), 1, fp1) != 0) {
		printf("%d\t%s\t%f\t%s", p.userid, p.modeOfPayment, p.billAmount, p.statusOfPayment);
	}
}
