//Siddharth Thakur, 1601CS46, Date-14/02/2017
//Bowling Distribution Problems

#include <stdio.h> //including required header files
#include <math.h>

void inputValues(int *toptr,int *moptr,int *bowlersptr); //function to take required inputs
void printBowlingCombinations(int to,int mo,int bowlers); //function to print unique bowling combinations
	
int i,j; //global iteration variables

int main(void) //main method
{
	int to;  //to store total no. of overs
	int mo; //to store a bowler's max no. of overs
	int bowlers; //no. of bowlers

	int *toptr=&to; //respective pointers
	int *moptr=&mo;
	int *bowlersptr=&bowlers;
	
	inputValues(toptr,moptr,bowlersptr); //input call
	
	printBowlingCombinations(to,mo,bowlers); //combination call
	
	
}

void inputValues(int *toptr,int *moptr,int *bowlersptr) //function to take required inputs
{
	printf("Total overs: ");
	scanf("%d",&(*toptr));
	printf("Maximum number of overs for one bowler: ");
	scanf("%d",&(*moptr));
	printf("Number of bowlers: ");
	scanf("%d",&(*bowlersptr));
}
	
void printBowlingCombinations(int to,int mo,int bowlers) //function to print unique bowling combinations
{
	int bowArray[bowlers]; //array to store bowling combinations
	for(i=0;i<bowlers;i++)
		bowArray[i]=0;

	int temp=to; 

	for(i=bowlers-1;i>=0;i--) //very first combination
	{
		if(temp>=mo)
			bowArray[i]=mo;
		else
			bowArray[i]=temp;
		temp-=bowArray[i];
	}
	
	int num=0; //to store the combination as a number
	
	for(i=0;i<bowlers;i++)
		num+=bowArray[i]*pow(10,i);

	printf("Output:\n");
	for(i=num;i>=0;i--)
	{
		
		temp=i;
		int flag=1; //flag raising
		int sumArray=0;
		for(j=0;j<bowlers;j++) //storing bowling combinations in a array out of the numbers
		{
			bowArray[j]=temp%10;
			temp/=10;
			sumArray+=bowArray[j];
		}
	
		if(sumArray==to) //condition check
		{
			for(j=bowlers-1;j>0;j--)
			{
				if(bowArray[j]<bowArray[j-1])
				{
					flag=-1;
					break;
				}
			}
			if(flag!=-1) //printing unique bowling combinations
			{
				for(j=bowlers-1;j>=0;j--)
					printf("%d ",bowArray[j]);
				puts("");
			}
		}
	}
}
