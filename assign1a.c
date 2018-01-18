//Siddharth Thakur, 1601CS46
//BMI Index

#include <stdio.h>
int main() //main method
{
	int w; //to store weight
	float h,bmi; //to store height and BMI

	//taking inputs

	printf("Please enter your weight(kg) and height(m) ( separated by comma) : ");
	scanf("%d,%f",&w,&h);

	bmi = w/(h*h); //BMI calculation

	//displaying result
	if (bmi<18.5)
		printf("Your BMI : %.1f and you are underweight.\n",bmi);
	else if (bmi<=24.9)
		printf("Your BMI : %.1f and your are normal.\n",bmi);
	else if (bmi<=29.9)
		printf("Your BMI : %.1f and you are overweight.\n",bmi);
	else
		printf("Your BMI : %.1f and you are obese.\n",bmi);
	return 0;
}
