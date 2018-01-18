//Siddharth Thakur, 1601CS46, Date-28/03/2017
//Realization and Analysis of Very Large Integers through Circular Doubly Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //including necessary header files
#include <math.h>

typedef struct node //structure definition
{
	long data;
	struct node* next; //double linking
	struct node* prev;
}Node;

typedef Node* NodePtr; //pointer to Node definition

NodePtr createList(char num[]) //function to create circular list
{
	NodePtr head=(NodePtr)malloc(sizeof(Node));
	char* ptr;
	int i=0,j,c,l=strlen(num)-1;
	if(l>=5)
		c=5;
	else
		c=(l-1)%5+1;
	NodePtr current=NULL,previous=head;
	char snum[6]={'\0'}; //to store bunch of five digits
	
	if(l%5==0)
		head->data=l/5;
	else
		head->data=l/5+1;
	if(num[0]=='-')
		head->data*=-1;

	for(i=l;i>=1;i--) //creation of doubly linked list (circular)
	{
		c--;
		snum[c]=num[i];

		if(c==0 || i==1)
		{
			current=(NodePtr)malloc(sizeof(Node));		
			current->data=strtol(snum,&ptr,10);
			previous->next=current;
			current->prev=previous;
			current->next=NULL;
			previous=current;
			current=NULL;
			if(i>5)
				c=5;
			else
				c=(i-1)%5;
			for(j=0;j<6;j++)
				snum[j]='\0';
		}
	}
	previous->next=head;
	head->prev=previous;
	return head;
}

int compare(NodePtr head1, NodePtr head2) //function to compare the two Big Integers
{
	int i;
	if(head1->data>0 || head2->data>0) //comparison on basis of length
	{
		if(head1->data>head2->data)
			return 1;
		if(head1->data<head2->data)
			return 2;
	}

	if(head1->data<0 && head2->data<0)
	{
		if(head1->data<head2->data)
			return 1;
		if(head1->data>head2->data)
			return 2;
	}

	if(head1->data==head2->data)
	{
		int n=abs(head1->data);
		NodePtr current1=head1;
		NodePtr current2=head2;
		for(i=1;i<=n;i++) //comparison on basis of digits
		{
			current1=current1->prev;
			current2=current2->prev;
			if(head1->data>0)
			{
				if(current1->data>current2->data)
					return 1;
				else if(current1->data<current2->data)
					return 2;
				else
					continue;
			}
			else
			{
				if(current1->data<current2->data)
					return 1;
				else if(current1->data>current2->data)
					return 2;
				else
					continue;
			}
		}
	}
	return 0;
}

void add(NodePtr head1, NodePtr head2) //function to add two positive Big Integers
{
	short carry=0;
	int n;
	NodePtr current1=head1;
	NodePtr previous1=head1;
	NodePtr current2=head2;
	for(n=abs(head2->data);n>=1;n--) //nodewise addition
	{
		current1=current1->next;
		current2=current2->next;
		long int temp=(current1->data+current2->data+carry)%100000; //carry concept used
		if((current1->data+current2->data+carry)>99999)
			carry=1;
		else
			carry=0;
		current1->data=temp;
		if(n==1 && (head1->data==head2->data))
			current1->data+=carry*100000;
	}
	for(n=abs(head1->data)-abs(head2->data);n>=1;n--)
	{
		current1=current1->next;
		long int temp=(current1->data+carry)%100000;
		if((current1->data+carry)>99999)
			carry=1;
		else
			carry=0;
		current1->data=temp;
	}
}

void difference(NodePtr head1, NodePtr head2) //function to find difference between two positive Big Integers
{
	short carry=0;
	int n;
	NodePtr current1=head1;
	NodePtr previous1=head1;
	NodePtr current2=head2;
	for(n=abs(head2->data);n>=1;n--) //nodewise difference
	{
		current1=current1->next;
		current2=current2->next;
		long int temp=current1->data-current2->data-carry; //borrow concept used
		if(temp<0)
		{
			temp=100000+temp;
			carry=1;
		}
		else
			carry=0;
		current1->data=temp;
	}
	for(n=abs(head1->data)-abs(head2->data);n>=1;n--)
	{
		current1=current1->next;
		long int temp=current1->data-carry;
		if(temp<0)
		{
			temp=100000+temp;
			carry=1;
		}
		else
			carry=0;
		current1->data=temp;
	}
}

void displayList(NodePtr head) //function to display the List
{
	int i;
	NodePtr temp=head->prev;
	if(head->data<0)
		putchar('-');
	else
		putchar('+');
	for(i=1;i<=abs(head->data);i++)
	{
		printf("%ld ",temp->data);
		temp=temp->prev;
	}
	puts("");
}
		
int main(void) //main method
{
	puts("On Assumption of Valid Inputs!");
	printf("Comparison (c) or Addition (a) or Subtraction (s) or Exit (x): ");
	char ch; 
	scanf(" %c",&ch); //choice input
	while(ch=='a'||ch=='s'||ch=='c'||ch!='x')
	{
		printf("Enter +ve number preceded by '+' sign and -ve number preceded by '-' sign.\n");
		char num1[100]={'\0'};
		char num2[100]={'\0'};
		scanf("%s",num1); //input of Big Integers
		scanf("%s",num2);
		NodePtr head1=createList(num1); //creation of list
		NodePtr head2=createList(num2);

		switch(ch) //choice matching
		{
			case 'c':	if(compare(head1,head2)==1) //comparison 
							puts("First Number is Bigger!");
						else if(compare(head1,head2)==2)
							puts("Second Number is Bigger!");
						else
							puts("Both are Equal!");
				    	break;

			case 'a':	printf("Sum is: "); //addition
						if((head1->data>0 && head2->data>0) || (head1->data<0 && head2->data<0))
						{
							if(abs(head1->data)>abs(head2->data))
							{
								add(head1,head2);
								displayList(head1);
							}
							else
							{
								add(head2,head1);
								displayList(head2);
							}
						}
						else //sign consideration
						{
							if(compare(head1,head2)==1)
							{
								if(abs(head1->data)<abs(head2->data))
								{
									difference(head2,head1);
									displayList(head2);
								}
								else
								{
									difference(head1,head2);
									displayList(head1);
								}
							}
							else if(compare(head1,head2)==2)
							{
								if(abs(head2->data)<abs(head2->data))
								{
									difference(head1,head2);
									displayList(head1);
								}
								else
								{
									difference(head2,head1);
									displayList(head2);
								}
							}
							else
								puts("0");
						}
				  	  	break;

			case 's':	head2->data=-1*head2->data; //subtraction
						if((head1->data>0 && head2->data>0) || (head1->data<0 && head2->data<0))
						{
							printf("Result: ");
							if(abs(head1->data)>abs(head2->data))
							{
								add(head1,head2);
								displayList(head1);
							}
							else
							{
								add(head2,head1);
								displayList(head2);
							}
						}
						else //sign consideration
						{
							printf("Result: ");
							if(compare(head1,head2)==1)
							{
								if(abs(head1->data)<abs(head2->data))
								{
									difference(head2,head1);
									displayList(head2);
								}
								else
								{
									difference(head1,head2);
									displayList(head1);
								}
							}
							else if(compare(head1,head2)==2)
							{
								if(abs(head2->data)<abs(head1->data))
								{
									difference(head1,head2);
									displayList(head1);
								}
								else
								{
									difference(head2,head1);
									displayList(head2);
								}
							}
							else
								puts("0");
						}
				  	  	break;

			default: 	puts("WRONG CHOICE!! Try Again."); //default
				 		break;
		}
		
		puts("");
		printf("Comparison (c) or Addition (a) or Subtraction (s) or Exit (x): ");
		scanf(" %c",&ch);
	}

	return 0;
} //end main
	
