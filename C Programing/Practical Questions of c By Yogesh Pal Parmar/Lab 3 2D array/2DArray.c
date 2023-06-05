#include<stdio.h>
int transpose(int n, int m, int arr1[][m]) //function to find transpose
{
		int arr2[n][m];
		int i,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			arr2[j][i] = arr1[i][j];	
		}
	}
	printf("\nTranspose of the given 2D array is :\n");
		for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			printf("%d ", arr2[i][j]);	
		}
		printf("\n");
	}
	return 0;
}
int matrixMultiply(int n, int m, int arr1[][m]) //function to find multiplication of two matrix
{
	int arr2[n][m];
	int arr3[n][m];
	int i,j,k;
	printf("\n Enter elements in array 2 :\n ");
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			arr3[i][j] = 0;
			for(k=0; k<n; k++)
			{
				arr3[i][j] += arr1[i][k] * arr2[k][j]; 
			}
		}
	}
	printf("\nMultiplication of array1 and array2 is : \n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int changeDiagonal(int n, int m, int arr1[][m])  // changing diagonals
	{
		int i,j;
		int temp;
		if(n==m)
		{
			for(i=0; i<n; i++)
			{
				temp = arr1[i][i];
				arr1[i][i] = arr1[i][n-1-i];
				arr1[i][n-1-i] = temp;			
			}
		}
		printf("\nArray after inter-changing diagonals is : \n");
		for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
		return 0;
	}
//main method
int main()
{
	printf("Yogesh Pal Parmar MCA 2B 70");
	int n, m;
	int i,j;
	int ch;
	printf("\n Enter number of rows : ");
	scanf("%d", &n);
	printf("\n Enter number of columns : ");
	scanf("%d", &m);
	int arr1[n][m];
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	do
	{
		printf("\nEnter a choice 0 1  2  3 : ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1: 
				transpose(n, m, arr1);
			break;
			case 2: 
				matrixMultiply(n, m, arr1); 
			break;
			case 3: 
				changeDiagonal(n, m, arr1);
			break;
			default:
				printf("\nInvalid choice");
		}
	}while(ch != 0);
	
}

