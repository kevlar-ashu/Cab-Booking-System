#include<stdio.h>
#include<stdlib.h>

#define MAX 30
FILE *fp;

struct driverDetail {
	int driverId;
	char driverName[MAX];
	char driverEmail[MAX];
}node;



//Code view details of all drivers

void cabDriverDetails(int id) {
	fp = fopen("cabDrivers.txt", "r");

	while (fread(&node, sizeof(struct driverDetail), 1, fp) != 0)
	{
		if (feof(fp) != 0)
			break;
		printf("%d\t%s\t%s\n", node.driverId, node.driverName, node.driverEmail);
	}

	fclose(fp);
}
