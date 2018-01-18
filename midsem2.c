//Siddharth Thakur, 1601CS46, Date-28/02/2017
//Polynomial Evaluator

#include <stdio.h> //including necessary header files
#include <math.h>

int main(){
	int a[100]={0}; //polynomial array
	int deg,coeff; //to store degree-coefficient pairs during input
	int i,j; //iteration variables
	float x,value; //stores value of x and vlaue of polynomial
	
	printf("\nEnter the number of terms: "); //taking inputs
	scanf("%d",&i);
	
	printf("Enter the degree, co-efficient pairs:\n");
	for(j=0;j<i;j++){ //storing the coefficients in the array treating its indices as representation of degree
		scanf("%d,%d",&deg,&coeff);
		a[deg]=coeff;
	}
	
	puts("");
	printf("Enter x = "); //inputting x
	scanf("%f",&x);
	
	value=0; //calculating a(x)
	for(i=0;i<100;i++)
		value+=a[i]*pow(x,i); //coefficient * x^(index)
	
	printf("\nThe value of evaluated polynomial is = %f\n\n",value);
			
	return 0;
}
