//Siddharth Thakur, 1601CS46, Date-11th April 2017
//Creation of Binary Tree from given Inorder & Postorder Sequences
//NOTE:- Input Sequences should be without spaces.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node //node structure
{
	char data;
	struct node* left;
	struct node* right;
}NODE;
typedef NODE* NODEPTR;

int search(char string[],char ch) //function to search index of character
{
	int i=0;
	for(i=0;i<strlen(string);i++)
	{
		if(string[i]==ch)
			return i;
	}
	return -1;
}

void buildTree(char inOrder[],char postOrder[],NODEPTR* root) //recursive function to create binary tree outof given sequences
{
	if(strlen(inOrder)==0 || strlen(postOrder)==0)//base case
		return;
	else if(*root==NULL)
	{
		*root=(NODEPTR)malloc(sizeof(NODE)); //node creation
		(*root)->data=postOrder[strlen(postOrder)-1];
		(*root)->left=NULL;
		(*root)->right=NULL;

		int index=search(inOrder,(*root)->data);
		if(index==-1){
			printf("Tree Not Possible\n");
			return;
		}

		char subInOrderLeft[100]={'\0'}; //subarray to store left subtree
		strncpy(subInOrderLeft,inOrder,index);

		int i=index+1,j=0;
		char subInOrderRight[100]={'\0'}; //subarray to store right subtree
		while(inOrder[i]!='\0')
		{
			subInOrderRight[j]=inOrder[i];
			i++;
			j++;
		}

		char subPostOrderLeft[100]={'\0'};
		int max=-1;
		for(i=0;i<strlen(subInOrderLeft);i++) //postOrder subarray creation 
		{
			index=search(postOrder,subInOrderLeft[i]);
			if(max<index)
				max=index;
		}
		strncpy(subPostOrderLeft,postOrder,max+1);

		char subPostOrderRight[100]={'\0'};
		i=max+1;
		j=0;
		while(postOrder[i]!=(*root)->data)
		{
			subPostOrderRight[j]=postOrder[i];
			i++;
			j++;
		}
		buildTree(subInOrderLeft,subPostOrderLeft,&((*root)->left)); //recursive function call to build left subtree
		buildTree(subInOrderRight,subPostOrderRight,&((*root)->right));//recursive function call to build right subtree
	}
	return; //end buildTree
}
		
void preOrderTrav(NODEPTR root,FILE* ptr) //recursive function to print preOrder traversal in a file
{
	if(root!=NULL)
	{
		printf("%c--",root->data);
		fprintf(ptr,"%c ",root->data);
		preOrderTrav(root->left,ptr);
		preOrderTrav(root->right,ptr);
	}
}

int main(void) //main method
{
	NODEPTR root=NULL;
	char inOrder[100]={'\0'}; //array to store inOrder sequence
	char postOrder[100]={'\0'}; //array to store postOrder sequence

	FILE* ptr; //pointer to FILE type
	ptr=fopen("ipseq.txt","r"); //opening the input file
	fscanf(ptr,"%s\n%s",inOrder,postOrder); //input sequences should be without spaces

	buildTree(inOrder,postOrder,&root); //call of function buildTree

	ptr=fopen("1601CS46.txt","w"); //opening output storage file
	fprintf(ptr,"%s","Pre-order sequence: ");
	printf("Pre-order sequence: ");
	preOrderTrav(root,ptr); //call for preOrder traversal of tree
	puts("");

	return 0; //end main
}
	

