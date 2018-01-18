// Siddharth Thakur, 1601CS46, Date-07/02/2017
// Anwesha Pronite & Science College Student's Problem

#include <stdio.h> //including necessary header file

int main() //main method
{
	int count=0; //general counting variable
	int i=0,j=0,flag=0; //for iteration and raising flags
	int n; //stores the no. of sudents

	printf("Enter the number of students participated: "); //inputting values
	scanf("%d",&n);
	
	int studHeight[n]; //VLA for storing the heights
	int robeColor[n]; //VLA for storing the color of the robes

	printf("Enter their heights (in the same line separated by space): "); //inputting heights
	for(i=0;i<n;i++)
		scanf("%d",&studHeight[i]);
	
	printf("Enter the color of robes denoted by integers (in the same line separated by space): "); //inputting robe colors
	for(i=0;i<n;i++)
		scanf("%d",&robeColor[i]);

	for(i=0;i<n;i++) //calculating the no. of students who can see the stage
	{
		flag=0;
		for(j=i-1;j>=0;j--)
			if(studHeight[i]<studHeight[j])
				flag=1;
		if(flag==0)
			count++;
	}
	
	printf("\nThe Output- \n");
	printf("No. of students can see the stage: %d\n",count);
	
	flag=0;
	for(i=0;i<n;i++) //determining the party type
	{
		for(j=i-1;j>=0;j--)
		{
			if(robeColor[i]==robeColor[j])
			{	
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
	}
	
	if(flag==1)
		printf("It is a BOYS party.\n"); //displaying the results
	else
		printf("It is a GIRLS party.\n");
	
	return 0;
}
