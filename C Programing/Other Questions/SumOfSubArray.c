//Sum of all the sub array of a given array
// number of sub array = n*(n+1)/2
#include<stdio.h>
int main()
{
	int n,i,j,current;
	scanf("%d", &n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	for(i=0;i<n;i++)
	{
		current = 0;
		for(j=i;j<n;j++)
		{
			current+= arr[j];
		   	printf("\n%d ", current);
		}
		printf("\n");
	}
	return 0;
}
