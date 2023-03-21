// Max till i
// Given an array a[] of size n. For every i from 0 to n-1 output max(a[0],a[1],...,a[i]).
#include<stdio.h>
int main()
{
	int n, i, max;
	scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	max = -19999;
	for(i=0; i<n; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
		printf("\n %d ", max);
	}
	return 0;
}

