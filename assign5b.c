// Siddharth Thakur, 1601CS46, Date-07/02/2017
// The Party and Guest's Seating Arrangement Problem 

#include <stdio.h> //including necessary header file

void sortArray(int[],int); //bubble sort function
void guestSearch(int[],int,int); //to locate guest's seat with given unique id
void printSeating(int[],int); //to print the seating arrangement
void dressColorAnalyser(int[],int); //to analyse the dress color of guests
void searchNprint(int[],int,int[],int); //to print seating positions of the guest with particular dress color

int male=0,female=0; //to count for no. of male and females
int i=0,j=0; //global iteration variables

int main() //main method
{
	int uId[15]={0}; //to store the unique id of the guests
	int index,c; //to store the last filled indices of arrays
	int id,newId; //to store the unique ids to be searched for or accommodated
	
	printf("Enter the unique ids of the guests (upto 15 integers separated by comma(press 0 to end)): ");
	i=0;
	do	//inputting unique ids
	{
		scanf("%d,",&c);
		if(c!=0 && i<15)
			uId[i]=c;
		else
			break;
		i++;
	}while(c!=0);
	
	index=i-1; 
	
	printf("Enter the id to be searched: ");
	scanf("%d",&id);
	
	sortArray(uId,index);
	
	printf("Enter the unique id of the new guest(except 0): ");
	scanf("%d",&newId);
	
	printf("\nOutput-\n");
	
	printf("\nThe seating arrangement is: \n"); //printing seating arrangement
	printSeating(uId,index);

	guestSearch(uId,index,id); //searching for particular guest
	
	printf("\nThere are %d males and %d females.\n",male,female); //displaying gender count
	
	printf("\nThe male guest id's are:- "); //displaying Ids genderwise
	for(i=0;i<=index;i++)
		if(uId[i]<0)
			printf("%d, ",uId[i]);
		
	printf("\nThe female guest ids are:- ");
	for(i=0;i<=index;i++)
		if(uId[i]>0)
			printf("%d, ",uId[i]);
	
	puts("");
	dressColorAnalyser(uId,index); //analysis of the dress color of the guests

	if(index<14) //checking accommodation of the new guest
	{
		printf("\nThe new seating arrangement is:-\n");
		uId[++index]=newId;
		sortArray(uId,index);
		printSeating(uId,index);
	}
	else
		puts("Sorry, No Accommodation Available!");
	puts("");		
}

void sortArray(int array[],int index) //bubble sort function
{	
	for(i=0;i<=index-1;i++)
	{
		for(j=i+1;j<=index;j++)
		{
			if(array[i]<array[j])
			{
				int temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
}
	
void printSeating(int array[],int index) //to print the seating arrangement
{
	for(i=0;i<=index;i++)
	{
		printf("%2d, ",array[i]);

		if(array[i]>0)
			female++;
		if(array[i]<0)
			male++;
	
		if((i+1)%5==0 && i!=0)
			puts("");
	}
	puts("");
}

void guestSearch(int array[],int index,int id) //to locate guest's seat with given unique id
{
	int flag=0;
	for(i=0;i<=index;i++)
	{
		if(array[i]==id)
		{
			printf("The guest with id %d is present in the party and is seated at: ",id);
			if(i/5<1)
				printf("Row 1 and %d position from left.",(i+1));
			else if(i/5>=1 && i/5<2)
				printf("Row 2 and %d position from left",(i+1-5));
			else
				printf("Row 3 and %d position from left",(i+1-10));
		flag=1;
		break;		
		}
	}
	if(flag!=1)
		printf("No guest is present with %d unique id.",id);
	puts("");
}

void dressColorAnalyser(int array[],int index) //to analyse the dress color of guests
{
	int redId[15]={0}; //to store the unique Ids of the guest with red color dress
	int blueId[15]={0}; //to store the unique Ids of the guest with blue color dress
	int red=-1,blue=-1; //to store the no. of guests with red or blue color dresses
	
	for(i=0;i<=index;i++)
	{
		if(array[i]<0)
		{
			if((-1*array[i])%2==0)
			{	
				red++;
				redId[i]=array[i];
			}
			else
			{	
				blue++;
				blueId[i]=array[i];
			}
			
		}
		else
		{
			if(array[i]%2==0)
			{				
				red++;
				redId[i]=array[i];
			}
			else
			{
				blue++;
				blueId[i]=array[i];
			}
		}
	}
	
	printf("\nThere are %d guests in red and %d guests in blue dress respectively.\n",(red+1),(blue+1));
	
	printf("\nThe seating positions of the guests in red dress are:- ");
	searchNprint(array,index,redId,red);
	printf("\nThe seating positions of the guests in blue dress are:- ");
	searchNprint(array,index,blueId,blue);
}

void searchNprint(int array[],int index,int colorId[],int color) //to print seating positions of the guest with particular dress color
{
	for(i=0;i<=index;i++)
	{
		for(j=0;j<=index;j++)
		{
			if(array[i]==colorId[j])
				printf("%d, ",(i+1));
		}
	}
	puts("");
}
