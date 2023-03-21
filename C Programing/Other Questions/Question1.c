//Program to replace last repeting number from a given array.
//Example: Input: 1125718, replacing: 1,replacement: 6, Output: 1125768
#include<stdio.h>
int main()
{
	int m = 0; // to check whether element found in the array.
	int n, i;
	printf("Enter size of array : ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter elements in the array : ");
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nYou have enterd : ");
		for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	int num;
	printf("\nEnter the number to replace : ");
	scanf("%d", &num);
	int temp;
	printf("\nEnter the replacement : ");
	scanf("%d",&temp);
	for(i=0; i<n; i++)
	{
		if(arr[i] == num)
		{
			m = i;
		}
	}
	if(m == 0)
	{
		printf("\nNumber not found in the array : ");
	}
	else
	{
	arr[m] = temp;
	} 
	printf("\nNew array is : ");
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	/*int ch;
	printf("\nEnter choice : 0 OR 1 : ");
	scanf("%d", &ch);
	if( ch == 0 )
	{
	goto lable;
    }
    else
    {
    	return 0;
	}*/
	return 0;
}
