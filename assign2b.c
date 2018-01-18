//Siddharth Thakur, 1601CS46 Date-17/01/2017	
//Tortoise & Hare Race

#include <stdio.h>

int main(void) //main method
{
	int x,y; //storing x and y
	float harePos,torPos,timeHare,timeTor,margin; //storing positions and time taken of both tortoise and hare
	
	printf("Enter X(seconds) = "); //taking inputs
	scanf("%d",&x);
	printf("Enter Y(seconds) = ");
	scanf("%d",&y);
	puts("");

	harePos=1.4*x; //calculating individual postions
	torPos=0.9*(x+y);
	timeTor=(18-torPos)/0.9;
	timeHare=(18-harePos)/1.4;


	if(timeTor<timeHare) //deciding winner
	{
		harePos+=1.4*timeTor;
		torPos+=0.9*timeTor;
		puts("Winner: Tortoise");
	}
	else if(timeTor==timeHare)
	{
		harePos+=1.4*timeTor;
                torPos+=0.9*timeTor;
		puts("Its a TIE!");
	}
	else
	{
		harePos+=1.4*timeHare;
                torPos+=0.9*timeHare;
		puts("Winner: Hare");
	}
	
	margin=harePos-torPos; //calculating winning margin
	if(margin<0)
		margin*=-1;
	printf("Winning distance margin: %.2f\n",margin);

	return 0;
}
	
