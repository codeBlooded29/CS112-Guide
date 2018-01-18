//Siddharth Thakur, 1601CS46, 24 January,2017
//7 Segment Display

#include <stdio.h>

//function prototypes
void printDisplay(int digit, char ch); //function to print 7-segment figure
void printHL(char ch); //to print horizontal line
void printVL1(char ch); //to print vertical line
void printVL2(char ch); //to print vertical line
void printVL3(char ch); //to print double vertical lines

int i=0; //global i for iterations

int main() //main method
{
	int rno,d1,d2; //to store roll no. and its digits
	char ch; //character for display
	
	//inputting values
	printf("Enter the Character for display (Used for 7-segment display): ");
	scanf("%c",&ch);
	printf("Enter last two digits of your Roll.No: ");
	scanf("%d",&rno);
	
	//extracting digits
	d2=rno%10;
	rno/=10;
	d1=rno%10;
	
	//displaying output
	puts("");
	printDisplay(d1,ch);
	puts("");
	printDisplay(d2,ch);
	puts("");
	
	return 0;
}

void printDisplay(int digit, char ch) //7-segment display method
{
	//for different digits
	switch(digit)
	{
		case 0: printHL(ch);
			printVL3(ch);
			printVL3(ch);
			printHL(ch);
			break;

		case 1: printVL2(ch);
   			printVL2(ch);
			printVL2(ch);
			break;
		
		case 2: printHL(ch);
			printVL2(ch);
			printHL(ch);
			printVL1(ch);
			printHL(ch);
			break;

		case 3: printHL(ch);
			printVL2(ch);
			printHL(ch);
			printVL2(ch);
			printHL(ch);
			break;

		case 4: printVL3(ch);
			printHL(ch);
			printVL2(ch);
			break;

		case 5: printHL(ch);
			printVL1(ch);
			printHL(ch);
			printVL2(ch);
			printHL(ch);
			break;

		case 6: printHL(ch);
			printVL1(ch);
			printHL(ch);
			printVL3(ch);
			printHL(ch);
			break;

		case 7: printHL(ch);
			printVL2(ch);
			printVL2(ch);
			break;
		
		case 8: printHL(ch);
			printVL3(ch);
			printHL(ch);
			printVL3(ch);
			printHL(ch);
			break;
		
		case 9: printHL(ch);
			printVL3(ch);
			printHL(ch);
			printVL2(ch);
			break;
		
		default: puts("Data error!");
			 break;

	}
	puts("");
}	

void printHL(char ch) //to print horizontal line
{
	for(i=1;i<=5;i++)
		printf("%c",ch);
	puts("");
	
}

void printVL1(char ch) //to print vertical line
{
	for(i=1;i<=3;i++)
		printf("%c    \n",ch);
}

void printVL2(char ch) //to print vertical line
{
	for(i=1;i<=3;i++)
		printf("    %c\n",ch);
}

void printVL3(char ch) //to print double vertical lines
{
	for(i=1;i<=3;i++)
		printf("%c   %c\n",ch,ch);
}
