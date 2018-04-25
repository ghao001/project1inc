
#include <stdio.h>

void displaySeats(char seats[15][30]);
int main()
{
	char seats[15][30];
	int ticket = 0;
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 30; j++)
			seats[i][j] = '#';
	float rowPrice[15];
	float totalSale = 0;
	for (int i = 0; i < 15; i++)
	{
		printf("Enter the price for row%d\n",i);
		scanf("%f",&rowPrice[i]);
	}
	displaySeats(seats);
	char status;
	do
	{
		printf("Welcome to theater, how many tickets you want to buy?");
		int n,r,c;
		scanf("%d",&n);
		printf("\n");
		float ticketPrice = 0;
		while (n > 0)
		{
			printf("Enter Row and column of an available seat:");
			scanf("%d %d",&r,&c);
			if (r <= 15 && c <= 30)
				if (seats[r - 1][c - 1] == '#')
				{
					seats[r - 1][c - 1] = '*';
					n--;
					ticket++;
					ticketPrice += rowPrice[r - 1];
				}
				else printf("Seat has been taken.\n");
			else printf("Wrong number.\n");
		}
		printf("Total price is: %.2f\n",ticketPrice);
		displaySeats(seats);
		totalSale += ticketPrice;
		printf("Total sale of tickets is: %.2f\n",totalSale);
		printf("%d tickets have been sold.\n",ticket);
		printf("%d seats are available.\n",450-ticket);
		for (int i = 0; i < 15; i++)
		{
			int numRow = 0;
			for (int j = 0; j < 30; j++)
			{
				if (seats[i][j] == '*')
					numRow++;
			}
			printf("Row%d has %d available.  ",i+1,30-numRow);
		}
		printf("\n");
		printf("Continue to run?(Y/N)");
		do
		{
			scanf("%c",&status);
		} while (status != 'Y' && status != 'N');

	} while (status == 'Y');
	return 0;
}
void displaySeats(char seats[15][30])
{
	printf("\t");
	for(int a=0;a<3;a++)
		for (int s = 1; s < 11; s++)
		{
			printf("%d",s % 10);
		}
	printf("\n");
	for (int i = 0; i < 15; i++)
	{
		printf("Row %-4d", i+1);
		for (int j = 0; j < 30; j++)
		{
			printf("%c",seats[i][j]);
		}
		printf("\n");
	}
}

