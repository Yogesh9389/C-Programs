// Find max length Arithematic sub array of a given array
//
#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	int curr = 2; //current number of Arithematic sub-array
	int j = 2; // while loop variable
	int pd = a[1] - a[0];  //to check present difference
	int ans = 2;
	while(j<n)
	{
		
		if(pd == a[j] - a[j-1])
		{
			curr++;
		}
		else
		{
			pd = a[j] - a[j-1];
			curr = 2;
		}
		ans = (curr>ans)?curr:ans;
		j++;
	}
	printf("\n%d", ans);
	return 0;
}
