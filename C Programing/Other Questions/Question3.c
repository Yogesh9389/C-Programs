// To convert decimal number to a hexadecimal number
#include<stdio.h>
int main()
{
	int num, i = 0, j;
	char hexNum[100];
	int rem;
	printf("\nEnter a number : ");
	scanf("%d", &num);
	int temp = num;
	while (num>0)
	{
		rem = num%16;
		
		if(rem >= 10)
		{
			rem = rem - 10;
			hexNum[i++] = 'A' + rem;
		}
		else
		{
			hexNum[i++] = 48 + rem;
		}
		
		num = num/10;
	}
	printf("\nConverted decimal number : %d to Hexadecimal form is : ",temp);
	for(j=i; j>=0; j--)
	{
		printf(" %c ",hexNum[j]);
	}
	return 0;
}
