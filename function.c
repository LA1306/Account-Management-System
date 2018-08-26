#include <function.h>

int AccAdd()
{
	FILE *pFile;
	sInfo sAdd;

	puts("Enter today's date (mm/dd/yyyy):");
	scanf("%d/%d/%d", sAdd.iAddMonth, sAdd.iAddDay, sAdd.iAddYear);
	puts("Enter the name:");
	scanf("%s", sAdd.cName);
	puts("Enter account number:");
	scanf("%s", sAdd.cAccNumber);
	puts("Enter account type:
		\n\t 1: Platium
		\n\t 2: Gold
		\n\t 3: Silver");
	scanf("%d", &sAdd.iAccType);


}
