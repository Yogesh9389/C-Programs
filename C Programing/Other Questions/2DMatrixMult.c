// 2D Array matrix multiplication
#include<stdio.h>
int main()
{
	int r, c;
	int i, j, k;
	printf("Enter number of rows : ");
	scanf("%d", &r);
	printf("\nEnter number of columns : ");
	scanf("%d", &c);
	int arr1[r][c];
	int arr2[r][c];
	int pro[r][c];
	printf("\n Enter elements in the 1 array : ");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	printf("\n Enter elements in the 2 array : ");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	}
		printf("\n Array 1 is : ");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("%d", arr1[i][j]);
		}
	}
		printf("\n Array 2 is : ");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("%d", arr2[i][j]);
		}
	}
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			pro[i][j] = 0;
			for(k = 0; k<c; k++)
			{
				pro[i][j]+= arr1[i][k] * arr2[k][j]; 
			}
		}
	}
	printf("\n Multiplication of array1 and array2 is : ");
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			printf("%d ", pro[i][j]);
		}
	}
	return 0;
}
