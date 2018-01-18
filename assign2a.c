//Siddharth Thakur, 1601CS46, Date-17/01/2017
//Triangle Detector (Quite Sensitive Code. Can handle wide variety of inputs.)

#include <stdio.h> //including required header files
#include <math.h>
#include <stdlib.h>
#define PI 3.1415
#define EPSILON 0.0001

int main(void) //main method
{
	double x1,x2,x3,y1,y2,y3; //to store the mentioned quantities
	double side1,side2,side3;
	double angle1,angle2,angle3;
	double area,s;
	
	printf("Enter the points (x & y coordinates separated by comma):\nPoint1: "); //taking inputs
	scanf("%lf,%lf",&x1,&y1);
	printf("Point2: ");
	scanf("%lf,%lf",&x2,&y2);
	printf("Point3: ");
	scanf("%lf,%lf",&x3,&y3);
	puts("");

	if(fabs((y2-y1)/(x2-(x1+EPSILON))-(y3-y1)/(x3-(x1+EPSILON)))<=EPSILON) //checking collinearity
	{
		puts("Points are COLLINEAR!");
		return 0;
	}
	
	side1=sqrt((y3-y2)*(y3-y2)+(x3-x2)*(x3-x2)); //claculating sides
	side2=sqrt((y3-y1)*(y3-y1)+(x3-x1)*(x3-x1));
	side3=sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));

	s=(side1+side2+side3)/2; //computing area by Heron Formula
	area=sqrt(s*(s-side1)*(s-side2)*(s-side3));
	
	angle1=acos((pow(side2,2)+pow(side3,2)-pow(side1,2))/(2*side2*side3)); //finding out the interior angles by Cosine Law
	angle2=acos((pow(side3,2)+pow(side1,2)-pow(side2,2))/(2*side1*side3));
	angle3=acos((pow(side2,2)+pow(side1,2)-pow(side3,2))/(2*side1*side2));
	
	//Determining the type of triangle

	if(angle1<PI/2.0 && angle2<PI/2.0 && angle3<PI/2.0)
		printf("The points are non-collinear. The formed triangle is an %s triangle with area = %.2lf","acute angled",area);
	else if(fabs(angle1-PI/2.0)<=EPSILON || fabs(angle2-PI/2.0)<=EPSILON || fabs(angle3-PI/2.0)<=EPSILON)
		printf("The points are non-collinear. The formed triangle is a %s triangle with area = %.2lf","right angled",area);
	else 
		printf("The points are non-collinear. The formed triangle is an %s triangle with area = %.2lf","obtuse angled",area);
	puts("");

	if(side1==side2 || side1==side3 || side2==side3)
		puts("The triangle is also  isosceles.");
	else if(side1!=side2 && side1!=side3 && side2!=side3)
		puts("The triangle is also scalene.");
	else
		puts("The triangle is also equilateral.");
	puts("");
	return 0;
} 	
