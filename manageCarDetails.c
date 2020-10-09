#include<stdio.h>
#include<stdlib.h>

#define MAX 30

//Here Code for Manage Car details
void insert(int);
void read(int);
void update(int);

//structure for car details for cab driver
struct cabDetail {
	int carId;
	int driverId;
	char carName[MAX];
	char carNumber[MAX];
	char carModel[MAX];
	int noOfSeats;
}node;

FILE *fp;// file pointer
char dummy;


void manageCarDetails(int id)
{

	int ch;

	while (1) {
		printf("--------------------------Manage Car Details---------------------------\n");
		printf("1.Enter details Of Car\n");
		printf("2.View Details of Car\n");
		printf("3.Update Details of car\n");
		printf("0.Quit\n");

		printf("Enter Your choice:\n");
		scanf("%d", &ch);
		scanf("%c", &dummy);

		switch (ch) {
		case 1:
			insert(id);
			break;

		case 2:
			read(id);
			break;

		case 3:
			update(id);
			break;

		case 0:
			return;

		default:
			printf("Enter correct choice\n");
			break;
		}
	}
}

//view details of car
void read(int id) {
	fp = fopen("cabDetails.txt", "r");

	printf("DriverId\tCar Id\tCar Name\tCar Number\tCar Model\tNo Of Seats\n");
	while (fread(&node, sizeof(struct cabDetail), 1, fp) != 0)
	{
		if (node.driverId == id) {
			printf("%d\t%s\t%s\t%s\t%d\n", node.driverId, node.carName, node.carNumber,node.carModel,node.noOfSeats);
		}
	}

	fclose(fp);
}

//insert employee detail in file

void insert(int id)
{
	char name[30];
	char number[30];
	char model[30];

	fp = fopen("CabDetails.txt", "a+");//here(a+) is use because: a+ : opens a text file in both reading and appending mode. New data is appended at the end of the file and does not overwrite the existing content.

	node.carId = 1;
	node.driverId = id;
	printf("Enter Your car name\n");
	gets(name);
	strcpy(node.carName, name);
	printf("Enter the car Number : \n");
	gets(number);
	strcpy(node.carNumber, number);

	printf("Enter the car model : \n");
	gets(model);
	strcpy(node.carModel, model);


	printf("Enter no of seats available in your car\n");
	scanf("%d", &node.noOfSeats);

	//fprintf(fp, "%d,%s,%s\n", node.carId, node.carName, node.carNumber);//write detail to file
	fwrite(&node, sizeof(struct cabDetail), 1, fp);

	fclose(fp);
}

//update list of employee

void update(int id) {
	FILE *fp1;//temperory file
	int name[30], number[30];
	int flag = 0;
	fp = fopen("cabDetails.txt", "r");
	fp1 = fopen("cabDetail.txt", "w");
	while (fread(&node, sizeof(struct cabDetail), 1, fp) != 0){
		if (id == node.driverId) {
			printf("Enter New Car Name\n");
			gets(name);
			strcpy(node.carName, name);
			printf("Enter updated car number\n");
			gets(number);
			strcpy(node.carNumber, number);
			printf("Enter updated no of seats available in your car\n");
			scanf("%d", &node.noOfSeats);
			fwrite(&node, sizeof(struct cabDetail), 1, fp1);
			flag = 1;
		}
		else {
			fwrite(&node, sizeof(struct cabDetail), 1, fp1);
		}
	}

	if (flag == 0) {
		printf("Enter correct car id to update\n");
	}

	fclose(fp);
	fclose(fp1);
	remove("cabDetails.txt");
	rename("cabDetail.txt", "cabDetails.txt");

}
