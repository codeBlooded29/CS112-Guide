// Siddharth Thakur, 1601CS46
// Railway FlexiFare Scheme

#include <stdio.h>
int main() //main method
{
	float bfare; //to store base fare
	int seat,sold; //to store remaining no. of seats and sold out percentage

	printf("Enter the base fare: ");
	scanf("%f",&bfare);
	printf("Enter the remaining seats: "); //taking inputs
	scanf("%d",&seat);

	sold = (700-seat)/7;

	if(sold<=10) //calculating ticket price
		printf("Your ticket price is: %.2f",bfare);
	else if(sold<=20)
		printf("Your ticket price is: %.2f",(1.1*bfare));
	else if(sold<=30)
		printf("Your ticket price is: %.2f",(1.2*bfare));
	else if(sold<=40)
		printf("Your ticket price is: %.2f",(1.3*bfare));
	else if(sold<=50)
		printf("Your ticket price is: %.2f",(1.4*bfare));
	else
		printf("Your ticket price is: %.2f",(1.5*bfare));
	puts("");
}
