//Siddharth Thakur, 1601CS46, Date-18th April, 2017
//Creation, Manipulation and Analysis of Polynomials

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{ //stucture definition
	int powerx;
	int powery;
	int powerz;
	int coeff;
	struct _node *next;//points to next node
}NODE;
typedef NODE* NODEPTR;

NODEPTR polyFirst(int nx, int ny, int nz, int ncoeff, NODEPTR head) //function to create list
{
	if(head==NULL)
	{
		head=(NODEPTR)malloc(sizeof(NODE));
		head->powerx=nx;
		head->powery=ny;
		head->powerz=nz;
		head->coeff=ncoeff;
		head->next=NULL;
	}
	else
	{
		NODEPTR temp=(NODEPTR)malloc(sizeof(NODE));
		temp->powerx=nx;
		temp->powery=ny;
		temp->powerz=nz;
		temp->coeff=ncoeff;
		temp->next=head;
		head=temp;
	}
	
	return head;
}

int compare(NODEPTR node1,NODEPTR node2) //compare two nodes
{
	if(node2->powerx>node1->powerx)
		return 1;
	else if(node2->powerx==node1->powerx && node2->powery>node1->powery)
		return 1;
	else if(node2->powerx==node1->powerx && node2->powery==node1->powery && node2->powerz>node1->powerz)
		return 1;
	else
		return 0;
}

NODEPTR sortList(NODEPTR head) //sorting of list
{
	int flag=1;
	while(flag==1)
	{
		NODEPTR current=head->next;
		NODEPTR previous=head;
		NODEPTR temp=head;
		flag=0;
		while(current!=NULL)
		{
			int cmp=compare(previous,current);
			if(cmp==1)
			{
				if(previous==head)
				{
					previous->next=current->next;
					current->next=previous;
					head=current;
				}
				else{
				NODEPTR temp=(NODEPTR)malloc(sizeof(NODE));
					temp->next=current;
					previous->next=current->next;
					current->next=previous;
				}
				flag=1;
			}
			temp=previous;
			previous=current;
			current=current->next;
		}
	}
	return head;
}
				
void printList(NODEPTR head) //printing of list in order
{
	head=sortList(head);
	NODEPTR current=head;
	printf("\nThe Polynomial is: ");
	while(current!=NULL)
	{
		if(current->coeff!=0)
		{
			if(current->coeff>0)
				printf("+ %d",current->coeff);
			else
				printf("%d",current->coeff);
			if(current->powerx!=0)
				printf("x^(%d)",current->powerx);
			if(current->powery!=0)
				printf("y^(%d)",current->powery);
			if(current->powerz!=0)
				printf("z^(%d)",current->powerz);
			printf(" ");
		}
		current=current->next;
	}
	puts("");
}

int size(NODEPTR head) //size found
{
	int count=0;
	while(head!=NULL){
		head=head->next;
		count++;
	}
	return count;
}

	
NODEPTR addPoly(NODEPTR head1, NODEPTR head2)//adding polynomials
{
	NODEPTR current1=head1,current2=head2;
	while(current2!=NULL)
	{
		int flag=0;
		current1=head1;
		while(current1!=NULL)
		{
			if((current2->powerx==current1->powerx) && (current2->powery==current1->powery) && (current2->powerz==current1->powerz))
			{
					current1->coeff+=current2->coeff;
					flag=1;
					break;
			}
			current1=current1->next;
		}
		if(flag==0)
		{
			NODEPTR temp=(NODEPTR)malloc(sizeof(NODE));
			temp->powerx=current2->powerx;
			temp->powery=current2->powery;
			temp->powerz=current2->powerz;
			temp->coeff=current2->coeff;
			temp->next=head1;
			head1=temp;
		}
		current2=current2->next;
	}

	return head1;
}
				
int main(void) //main method
{
	NODEPTR head=NULL;
	NODEPTR head1=NULL,head2=NULL;
	int option=0;
	int nx,ny,nz,ncoeff;
	char ch='y';
	printf("Options: Create Polynomial (1), Display Polynomial (2), Add Polynomials(3), Exit (0)\n");
	printf("Enter option: "); 
	scanf("%d",&option);
	while(option!=0)
	{
		switch(option) //cases
		{
			case 1:
				while(ch!='n')
				{
					printf("Enter term: ");
					scanf("%d %d %d %d",&nx,&ny,&nz,&ncoeff);
					head=polyFirst(nx,ny,nz,ncoeff,head);
					printf("Again(y/n): ");
					scanf(" %c",&ch);
				}
				printf("\nEnter option: "); 
				scanf("%d",&option);
				break;
			
			case 2:
				printList(head);
				printf("\nEnter option: "); 
				scanf("%d",&option);
				break;			

			case 3:
				ch='y';
				puts("First Polynomial:");
				while(ch!='n')
				{
					printf("Enter term: ");
					scanf("%d %d %d %d",&nx,&ny,&nz,&ncoeff);
					head1=polyFirst(nx,ny,nz,ncoeff,head1);
					printf("Again(y/n): ");
					scanf(" %c",&ch);
				}
				printList(head1);

				ch='y';
				puts("\nSecond Polynomial:");
				head2=NULL;
				while(ch!='n')
				{
					printf("Enter term: ");
					scanf("%d %d %d %d",&nx,&ny,&nz,&ncoeff);
					head2=polyFirst(nx,ny,nz,ncoeff,head2);
					printf("Again(y/n): ");
					scanf(" %c",&ch);
				}
				printList(head2);
		
				puts("\nAfter adding:-");
				head1=addPoly(head1,head2);
				//head1=sortList(head);
				printList(head1);
				printf("\nEnter option: "); 
				scanf("%d",&option);
				break;
				
			default:
				puts("WRONG Choice!! TRY AGAIN!!");
				break;
		}
	}
	
	puts("\nEXIT");
	return 0;
}
				


		
	
 
