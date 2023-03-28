#include<stdio.h>
#include<stdlib.h>
#define n 10
struct stack
{
	int stk[n];
	int top;
};
typedef struct stack ST;
ST s;
int push()
{
	
	if(s.top == n-1)
	{
		printf("/nStack Overflow : ");
	}
	else
	{
		int x;
	printf("\nEnter an element to push : ");
	scanf("%d", &x);
		s.top++;
		s.stk[s.top] = x;
	}
}
int pop()
{
	if(s.top == -1)
	{
		printf("\nStack Underflow");
	}
	else
	{
		s.top--;
	}
}
int peek()
{
	if(s.top == -1)
	{
	printf("\nStack Underflow");	
	}
	else
	{
		printf("\n Peek element is : %d ", s.stk[s.top]);
	}
}
void display()
{
	int temp = s.top;
	if(temp == -1)
	{
		printf("\nStack Underflow");
	}
	else
	{
		printf("\n");
		while(temp>=0)
		{
			printf("\n %d ",s.stk[temp] );
			temp--;
		}
	}
	
}
int main()
{
	
	s.top = -1;
	int ch;
	do
	{
		printf("\nEnter a Choice : 0: EXIT! / 1: Push : / 2: Pop : / 3: Peek  : / 4: Display :\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				push();
			break;
			case 2:
				pop();
			break;
			case 3:
				peek();
			break;
			case 4:
				display();
			break;
			default:
				printf("\n Invalid choice! ");
		}
		
	}while(ch != 0);
	return 0;		
}
