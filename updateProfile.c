#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
FILE *fp;//global file pointer


struct driver {
	int id;
	char name[MAX];
	char mail[MAX];
	char password[20];
}temp;



void updateProfile(int id) {

	FILE *fp1;//temporary file pointer
	char email[MAX];
	int flag = 0;
	

	fp = fopen("cabDrivers.txt", "r");
	fp1 = fopen("DriverDummy.txt", "w");
	/*while (fread(&temp, sizeof(struct driverDetail), 1, fp) != 0) {
		printf("%d\t%s\t%s\n", temp.driverId, temp.driverName, temp.driverEmail);
	}*/

	while (fread(&temp, sizeof(struct driver), 1, fp) != 0)
	{
		if (id == temp.id) {
			
			printf("Enter updated Email-Id\n");
			scanf(" ");
			gets(email);
			strcpy(temp.mail, email);
			fwrite(&temp, sizeof(struct driver), 1, fp1);
			flag = 1;
		}
		else
		{
			fwrite(&temp, sizeof(struct driver), 1, fp1);
		}
	}
	if (flag == 0) {
		printf("Enter correct car id to update\n");
	}
	
	fclose(fp);
	fclose(fp1);
	remove("cabDrivers.txt");
	rename("DriverDummy.txt", "cabDrivers.txt");
}