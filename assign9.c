// Siddharth Thakur, 1601CS46, Date- 21st March 2016
//Linked List Creation & Sorting

#include <stdio.h> //including necessary header files
#include <stdlib.h>

typedef struct _node //our structure
{
	char roll[10]; //roll no.
	int ht; //height
	int wt; //weight
	struct _node *nextht; //linking heightWise
	struct _node *nextwt; //linking heightWise
} node;

typedef node *list; //pointer to node type
list headHt; //pointer to Head in heightWise sorting (descending order)
list headWt; //pointer to Head in weightWise sorting (descending order)

void sort_ht(list L); //BUBBLE SORT function to sort the linked list HeightWise (descending order)
void sort_wt(list L); //BUBBLE SORT function to sort the linked list WeightWise (descending order)
void printNameList(list L, int option); //function to print the linked list sorted eitherways (descending order)

int main(void) //main method
{
	
	list head=malloc(sizeof(node)); //head to the linked list
	int i; //iteration variable
	int n; //number of nodes
	
	printf("Number of Nodes : "); //taking inputs
	scanf("%d",&n);
	puts("Input (ROLL HEIGHT WEIGHT): \n");
	scanf("%s",head->roll);
	scanf(" %d",&head->ht);
	scanf(" %d",&head->wt);
	head->nextht=NULL;
	head->nextwt=NULL;
	
	list current=NULL;
	list previous=head;
		
	for(i=1;i<=n-1;i++) //iterative inputting
	{
		current=malloc(sizeof(node));
		previous->nextht=current;
		previous->nextwt=current;
		scanf("%s",current->roll);
		scanf(" %d",&current->ht);
		scanf(" %d",&current->wt);
		current->nextht=NULL;
		current->nextwt=NULL;
		previous=current;
		current=NULL;
	}

	int option=1; //option for sorting eitherways (descending order)
	while(option==1 || option==2)
	{
		printf("\nEnter Sorting Option : 1 for HeightWise OR 2 for WeightWise OR 3 to Quit :-> ");
		scanf("%d",&option);
		if(option==1 || option==2)
			printNameList(head,option);
		else
			break;
	}
	
	return 0; //end main
}

void sort_ht(list L) //BUBBLE SORT function to sort the linked list HeightWise (descending order)
{
	list current=L; //pointer to current node
	list previous=L; //pointer to previous node
	list lPtr=NULL; //pointer to last sorted positioned node
	int flag; //flag
	
	do //BUBBLE SORT implementation through swapping of nodes (by pointer adjustment)
	{
		flag=0;
		current=L;
		while(current->nextht!=lPtr)
		{
			if(current->ht < current->nextht->ht) //pointer adjustments for 3 different cases
			{
				if(current==L) 
				{
					list temp=current->nextht;
					current->nextht=temp->nextht;
					temp->nextht=current;
					L=temp;
					current=L;
				}
				
				else if(current->nextht->nextht==NULL)
				{
					list temp=current;
					previous->nextht=current->nextht;
					current->nextht->nextht=temp;
					temp->nextht=NULL;
					current=previous->nextht;
				}
				
				else
				{
					list temp=current;
					previous->nextht=current->nextht;
					temp->nextht=current->nextht->nextht;
					previous->nextht->nextht=temp;
					current=previous->nextht;
				}
				
				flag=1;
			}
			previous=current;
			current=current->nextht;
		}
	}while(flag==1); //if flag remains 0 means that our linked list is sorted
	
	headHt=L;
}

void sort_wt(list L) //BUBBLE SORT function to sort the linked list WeightWise (descending order)
{
	list current=L; //pointer to current node
	list previous=L; //pointer to previous node
	list lPtr=NULL; //pointer to last sorted positioned node
	int flag; //flag
	
	do //BUBBLE SORT implementation through swapping of nodes (by pointer adjustment)
	{
		flag=0;
		current=L;
		while(current->nextwt!=lPtr)
		{
			if(current->wt < current->nextwt->wt) //pointer adjustments for 3 different cases
			{
				if(current==L)
				{
					list temp=current->nextwt;
					current->nextwt=temp->nextwt;
					temp->nextwt=current;
					L=temp;
					current=L;
				}
				
				else if(current->nextwt->nextwt==NULL)
				{
					list temp=current;
					previous->nextwt=current->nextwt;
					current->nextwt->nextwt=temp;
					temp->nextwt=NULL;
					current=previous->nextwt;
				}
				
				else
				{
					list temp=current;
					previous->nextwt=current->nextwt;
					temp->nextwt=current->nextwt->nextwt;
					previous->nextwt->nextwt=temp;
					current=previous->nextwt;
				}
				
				flag=1;
			}

			previous=current;
			current=current->nextwt;
		}
	}while(flag==1); //if flag remains 0 means that our linked list is sorted
	
	headWt=L;
}
	
void printNameList(list L, int option) //function to print the linked list sorted eitherways (descending order)
{
	list current=L;
	if(option == 1)
	{
		sort_ht(L); //sorting the linked list HeightWise (descending order)
		current=headHt;
		printf("Sort (Descending Order) using height: "); //printing sorted linked list
		while(current!=NULL)
		{
			printf(" <%s> ",current->roll);
			current=current->nextht;
		}
	}
	
	if(option == 2)
	{
		sort_wt(L); //sorting the linked list WeightWise (descending order)
		current=headWt;
		printf("Sort (Descending Order) using weight: "); //printing sorted linked list
		while(current!=NULL)
		{
			printf(" <%s> ",current->roll);
			current=current->nextwt;
		}
	}
	
	puts("\n");
}
			
	
	
	
	
	
	
	
	
	
	
	
	
	
