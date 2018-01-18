//Siddharth Thakur, 1601CS46, 31/01/2017
//Binary and Hexadecimal representation

#include <stdio.h> //including necessary header files

int count=0,i=0; //global variables for counting and iterarations respectively

int binary(int,int[]); //function to convert from decimal to binary
void hammingWeight(int[],int); //function to find hamming weight of a binary string
void hammingDistance(int[],int,int[]); //function to find hamming distance between two binary strings of same length
void hexaDecimal(int[],int); //function to convert from binary to hexadecimal

int main(void) //main method
{
	int a,b,flag1,flag2; //'a' and 'b' to store decimal inputs and 'flag1' and 'flag2' to store lengths of binary strings
	int string1[100]; //to store the equivalent binary string for first input 
	int string2[100]; //to store the equivalent binary string for second input
	
	for(i=0;i<100;i++) //initializations of the arrays
	{
		string1[i]=-1;
		string2[i]=-1;
	}
	
	printf("Enter two decimal integers (separated by ','): "); //getting input from user
	scanf("%d,%d",&a,&b);
	
	flag1=binary(a,string1); //converting to binary and storing the length
	flag2=binary(b,string2);
	
	count=1;
	hammingWeight(string1,flag1); //finding out the hamming weights
	count=2;
	hammingWeight(string2,flag2);
	
	if(flag1==flag2) //calculating hamming distance of two binary strings of equal length
		hammingDistance(string1,flag1,string2);

	count=1;
	hexaDecimal(string1,flag1); //converting from binary to hexadecimal 
	count=2;
	hexaDecimal(string2,flag2);
	
	return 0;
}

int binary(int num, int array[]) //function to convert from decimal to binary
{
	int hold=num;
	i=0;
	int flag=0;

	while(hold!=0) //converting into binary system
	{
		array[i]=hold%2;
		hold/=2;
		i++;
	}
	
	i=-1;
	while(array[i+1]!=-1)
		i++;
	
	flag=i; //getting length of the binary string
	printf("The binary representation for %d is ",num); //printing the binary string

	for(;i>=0;i--)
		printf("%d",array[i]);

	puts("");
	
	return flag;	
}

void hammingWeight(int array[],int flag) //function to find hamming weight of a binary string
{
	if(count==1)
		printf("Hamming weight for the first string = ");
	if(count==2)
		printf("Hamming weight for the second string = ");
	
	count=0;
	for(i=0;i<=flag;i++) //finding out the hamming weight
		if(array[i]==1)
			count++;
	printf("%d\n",count);
}

void hammingDistance(int array1[],int flag,int array2[]) //function to find hamming distance between two binary strings of same length
{
	count=0;
	for(i=0;i<=flag;i++) //calculating hamming weight
		if(array1[i]!=array2[i])
			count++;
	printf("Hamming distance between the two strings = %d\n",count);
}

void hexaDecimal(int array[],int flag) //function to convert from binary to hexadecimal
{
	int size=flag/4 + 1;
	int hexD[size]; //to store the hexadecimal string
	int value; //to store value of each element of the array hexD
	
	i=0;
	while(size!=0) //converting from binary to hexadecimal (by dividing binary strings into group of 4 elements)
	{
		if(i+3<=flag) //using the conversion method from binary to hexadecimal
			value = 8*array[i+3] + 4*array[i+2] + 2*array[i+1] + 1*array[i];
		else if(i+2<=flag)
			value = 4*array[i+2] + 2*array[i+1] + 1*array[i];
		else if(i+1<=flag)
			value = 2*array[i+1] + 1*array[i];
		else 
			value = 1*array[i];

		if(value<=9)
			hexD[size-1]=value;
		else
		{
			switch(value)
			{
				case 10: hexD[size-1]='A';
					 break;
				case 11: hexD[size-1]='B';
					 break;
				case 12: hexD[size-1]='C';
					 break;
				case 13: hexD[size-1]='D';
					 break;
				case 14: hexD[size-1]='E';
					 break;
				case 15: hexD[size-1]='F';
					 break;
				default: break;
			}
		}
	
		size--;
		i+=4;
	}
	
	if(count==1)
		printf("The HexaDecimal representation for the first string: "); //printing the hexadecimal equivalent
	if(count==2)
		printf("The HexaDecimal representation for the second string: ");
	
	i=0;
	while(i<(flag/4)+1)
	{
		if(hexD[i] <=9 && hexD[i] >= 0)
			printf("%d",hexD[i]);
		else
			printf("%c",hexD[i]);
		
		i++;
	}
	
	puts("");
}
