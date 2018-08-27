#include <stdio.h>
#include <string.h>

typedef struct
{
	int	iAccNumber;
	char	cAccName[20];
	char	cAccType[10];
} sInfo;

int AccAdd()
{
	FILE *fpLog;

	sInfo sAdd, sExist;

	int iAccTypeIndex;
	char cQuit = '0';

/*	sAdd.iAccNumber = 0;
	strcpy(sAdd.cAccName, "0");
	strcpy(sAdd.cAccType, "0");
*/
	fpLog = fopen("Log.txt", "a+");

//	puts("Enter today's date (mm/dd/yyyy):");
//	scanf("%d/%d/%d", sAdd.iAddMonth, sAdd.iAddDay, sAdd.iAddYear);

	printf("Enter the account number (6 number): ");
	scanf("%d", &sAdd.iAccNumber);
	while(fscanf(fpLog, "%d %s %s\n", &sExist.iAccNumber, sExist.cAccName, sExist.cAccType) != EOF)
	{
		if(sAdd.iAccNumber == sExist.iAccNumber)
		{
			printf("Account already exist! [Q] ");
			while (cQuit != 'q')
			{
				scanf("%c", &cQuit);
			}

			return 0;
		}
	}

//	puts("Enter the name:");	// puts: tu dong xuong hang
	printf("Enter the name: ");
	scanf("%s", sAdd.cAccName);
	
	printf("Account type:\n\t 1: Platium\n\t 2: Gold\n\t 3: Silver \nSelect account type: ");
	scanf("%d", &iAccTypeIndex);
	switch (iAccTypeIndex)
	{
		case 1:	strcpy(sAdd.cAccType, "Platium");
			break;
		case 2: strcpy(sAdd.cAccType, "Gold");
			break;
		case 3: strcpy(sAdd.cAccType, "Silver");
			break;
		default:
			break;
	}

	fprintf(fpLog, "%d %s %s\n", sAdd.iAccNumber, sAdd.cAccName, sAdd.cAccType);
	fclose(fpLog);
	puts("Account created successfully! [Q]");
	while (cQuit != 'q')
	{
		scanf("%c", &cQuit);
	}

	return 0;
}

int main()
{
/*	FILE *fpLog;
	fpLog = fopen("Log.txt", "w+");
	fprintf(fpLog, "%d %s %s\n", 0, "0", "0");
	fclose(fpLog);
*/
	AccAdd();

	return 0;
}
