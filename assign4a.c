//Siddharth Thakur, 1601CS46, 31/01/2017
//Perfect Squares in a Range of Numbers

#include <stdio.h> //including necessary header files
#include <math.h>

int perfectSquares(int l, int u); //function to check for perfect squares

int main(void) //main method
{
	int l,u,check; /*variables 'l' and 'u' to store lower and upper limits respectively of the range of numbers. Variable 'check' to check occurences of perfect squares. */

	printf("Enter the range of numbers (separated by dash '-') : "); //inputting range
	scanf("%d-%d",&l,&u);
	
	do //genrating perfect squares
	{
		check=perfectSquares(l,u);
		if(check!=1)
		{
			printf("No perfect square exists. Please enter another range (separated by dash '-') : ");
	  		scanf("%d-%d",&l,&u);
		}
	}
	while(check!=1);
	
	puts("");
	return 0;	
}

int perfectSquares(int l, int u) //function to check for perfect squares
{
	int i,s,count=0; //'count' for counting number of perfect squares

	for(i=sqrt(l);i<=sqrt(u);i++)
	{
		s=i*i;
		
		if(s>=l && s<=u)
		{
			count++;
			if(count==1)
				printf("The perfect squares in the given range are: ");
			printf("%d, ",s);
		}
	}
	if(count==0)
		return 0;
	else
		return 1;
}
