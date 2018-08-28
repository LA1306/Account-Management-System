#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int	iAccNumber;
	char	cAccName[20];
	char	cAccType[10];
} S_INFO;

int AccAdd()
{
	FILE *fpLog;

	S_INFO sAdd, sExist;

	int iAccTypeIndex;
	char cQuit = '0';

	fpLog = fopen ("Log.txt", "a+");

	printf ("Enter the account number (6 number): ");
	scanf ("%d", &sAdd.iAccNumber);
	while (fscanf(fpLog, "%d %s %s\n", &sExist.iAccNumber, sExist.cAccName, sExist.cAccType) != EOF)
	{
		if (sAdd.iAccNumber == sExist.iAccNumber)
		{
			printf ("Account already exist! [Q] ");
			while (cQuit != 'q')
			{
				scanf ("%c", &cQuit);
			}
			return 0;
		}
	}

//	puts ("Enter the name:");	// puts: tu dong xuong hang
	printf ("Enter the name: ");
	scanf ("%s", sAdd.cAccName);

	printf ("Account type:\n\t 1: Platium\n\t 2: Gold\n\t 3: Silver \nSelect account type: ");
	scanf ("%d", &iAccTypeIndex);
	switch (iAccTypeIndex)
	{
		case 1:	strcpy (sAdd.cAccType, "Platium");
			break;
		case 2: strcpy (sAdd.cAccType, "Gold");
			break;
		case 3: strcpy (sAdd.cAccType, "Silver");
			break;
		default:
			break;
	}

	fprintf (fpLog, "%d %s %s\n", sAdd.iAccNumber, sAdd.cAccName, sAdd.cAccType);
	fclose (fpLog);
	puts ("Account created successfully! [Q]");
	while (cQuit != 'q')
	{
		scanf("%c", &cQuit);
	}

	return 0;
}

int iScanQuit ()
{
	char iQuit = '0';

	printf ("[Q] ");

	while (iQuit != 'q')
	{
		scanf ("%c", &iQuit);
	}
	return 0;
}

int iViewAcc ()
{
	S_INFO VIEW;
	int	iAccNumberTemp;
//	char	cQuit = '0';

	FILE *fpLog;
	fpLog = fopen ("Log.txt", "a+");

	system ("clear");
	puts ("VIEW ACCOUNT INFO FUNCTION");
	printf ("Enter the account number: ");
	scanf ("%d", &iAccNumberTemp);

	while (fscanf (fpLog, "%d %s %s\n", &VIEW.iAccNumber, VIEW.cAccName, VIEW.cAccType) != EOF)
	{
		if (iAccNumberTemp == VIEW.iAccNumber)
		{
			printf ("Name: %s\n", VIEW.cAccName);
			printf ("Type: %s\n", VIEW.cAccType);
/*			while (cQuit != 'q')
			{
				scanf ("%c", &cQuit);
			{
*/			iScanQuit();

			return 0;
		}
	}

	fclose (fpLog);
	puts ("Account not found!");
	iScanQuit();

	return 0;
}

int main()
{
//	AccAdd();
	iViewAcc();

	return 0;
}
