//Siddharth Thakur, 1601CS46, 24 January, 2017
//Shipbuilding Company's Problem

#include <stdio.h>

/* After carefully examining and analysing results of various inputs(i.e., no. of months), the output turned out to be in Fibonacci Series i.e. a series in which subsequent elements are the sum of preceding two elements. */

int fibonacci(int); //Recursive function to find out the fibonacci terms

int main() //Main method
{
	int n,choices; //"n" to store no. of months, 'choices' for all possibilities

	printf("Enter the month after which the area is to be closed: ");
	scanf("%d",&n); //inputting value
	
	choices=fibonacci(n); //generating result

	printf("There are %d choices of plan.\n",choices); //displaying output
}

int fibonacci(int n) //Recursive function to find out the fibonacci terms
{
	if(n==1)
		return 1; //Base cases
	else if(n==2)
		return 2;
	else
		return (fibonacci(n-1)+fibonacci(n-2)); //recursions
}
	
	
