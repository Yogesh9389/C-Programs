#include<stdio.h>
int num;
int num1;
int num2;
int n;
int febonacci(int num)
{
	if(num == 0)
	{
		return 0;
	}
	else if(num == 1)
	{
		return 1;
	}
	else
	{
		return febonacci(num-1) + febonacci(num-2);	
	}
}
int Hcf(int num1, int num2)
{
	if(num1 == 1 && num2 == 1)
	{
		return 1;
	}
	else if(num1 > num2)
	{
		return Hcf(num1-num2, num2);
	}
	else if(num2 > num1)
	{
		return Hcf(num1, num2-num1);
	}
	else
	{
		return num1;
	}
}
int factorial(int n)
{
	if(n == 0)
	{
	 	return 1;	
	}
	else
	{
	return n*factorial(n-1);
	}
}
int lcm(n,n1)
{
	static int least = 1;
	if(least % n==0 && least % n1==0)
	{
		return least;
	}
	else
	{
		least++;
		lcm(n,n1);
		return least;
	}
}
int main()
{
	int ch;
	printf("Enter your choice : 1 OR 2 OR 3 OR 4 : ");
	scanf("%d", &ch);
	lable:
	switch (ch)
	{
		case 1:
			printf("\nEnter a number : ");
			scanf("%d", &num);
			printf("\n%d", febonacci(num));
		break;
		case 2:
			printf("\nEnter two numbers : ");
			scanf("%d %d", &num1, &num2);
			printf("\nHCF of %d and %d is : %d",num1, num2, Hcf(num1,num2));
		break;
		case 3:
			printf("\nEnter a number : ");
			scanf("%d", &n);
			printf("\nFactorial of %d is = %d",n,factorial(n));
		break;
		case 4:
			printf("\nEnter a number : ");
			scanf("%d", &n);
			int n1;
			printf("\nEnter 2 number : ");
			scanf("%d", &n1);
			printf("\nLCM of %d and %d is = %d",n,n1,lcm(n,n1));
		break;
		default:
			printf("\nInvalid Choice!");
			break;
	}
	printf("\nEnter choice again : ");
	scanf("%d", &ch);
	if(ch==1 || ch==2|| ch==3 || ch==4)
	{
		goto lable;
	}
	else
	{
		printf("\nInvalid choice ");
	}
	return 0;
}
