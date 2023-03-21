//Find sub string to of a given string.
// Input: abcdefabcghiabc, abc Output: 3
#include<stdio.h>
#include<string.h>
int main()
{
	int i, j;
	int count = 0;
	char str1[20];
	char str2[3];
	printf("Enter first string : ");
	gets(str1);
	printf("\nEnter second string : ");
	gets(str2);
	printf("\nFirst string : %s ",str1);
	printf("\nSecond String : %s ",str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(i=0; i<len1; i++)  //loop to traverse first string
	{
		for(j=0; j<len2; j++)   //loop to traverse second string
		{
			if(str1[i] == str2[j])
			{
				if(j == len2-1)
				{
					count++;
				}
				break;
			}
			else
			{
				continue;
			}
		}
		//count++;
	}
	printf("\n%s is present in %s : %d times.",str2,str1,count);
	return 0;
}
