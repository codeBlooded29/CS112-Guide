//Siddharth Thakur, 1601CS46, Date- 4th April,2017
//Creation & Printing of Binary Search Tree

#include <stdio.h>
#include <stdlib.h>
#define LARGE 999999

typedef struct _node{ 
  int data; 
  struct _node *leftChild;    //points to left child 
  struct _node *rightChild;   //points to right child 
  struct _node *parent;     //points to parent 
}NODE; 
typedef NODE* NODEPTR;

int Svalue=LARGE; //to store the minimum leaf value in minimum level
int Mvalue=-999999; //to store the maximum leaf value in maximum level

void createBST(int data,NODEPTR* treePtr,NODEPTR parentPtr) //function to create BinarySearchTree(BST)
{
	// if tree is empty
	if (*treePtr == NULL)
	{
		*treePtr = malloc(sizeof(NODE));
		// if memory was allocated, then assign data
		if (*treePtr != NULL ) {
			(*treePtr)->data = data;
			(*treePtr)->leftChild = NULL;
			(*treePtr)->rightChild = NULL;
			(*treePtr)->parent = parentPtr;
		}
	} 
	else { // tree is not empty
		// data to insert is less than or equal to data in current node
		if (data<=(*treePtr)->data)
			createBST(data,&((*treePtr)->leftChild),*treePtr);
		// data to insert is greater than data in current node
		else
			createBST(data,&((*treePtr)->rightChild),*treePtr);
	}
}

void printParent(NODEPTR root) //recursive function to print Nodewise Parents in PreOrder Traversal
{
	if(root!=NULL) //not a leaf node
	{
		if(root->parent==NULL) //root node
			printf("%d%15s\n",root->data,"No Parent");
		else
			printf("%d%10d\n",root->data,root->parent->data); //non-root nodes

			printParent(root->leftChild); //recursive call
			printParent(root->rightChild);
	}
	else
		return;
}
	
void compareGivenLevel(NODEPTR root,int level) //compare values of nodes on a particular level
{
	if (root == NULL)
        return;
	if (level == 1) //current level
	{
		if(root->leftChild==NULL && root->rightChild==NULL)
		{
			if(Svalue>root->data)
				Svalue=root->data; //smallest value
			if(Mvalue<root->data)
				Mvalue=root->data; //largest value
		}
	}	
	else if (level > 1) //recursive call
	{
    	compareGivenLevel(root->leftChild, level-1);
    	compareGivenLevel(root->rightChild, level-1);
	}
}

int levelOrderTrav(NODEPTR root) //recursive function to travel in LevelOrder
{
	int value=0,c=0; //flag
	int level=0; //level flag
	int h = height(root); //stores height of the tree
	int i; //for iteration
	for (i=1; i<=h; i++)
	{   	
		compareGivenLevel(root, i);
		if(Svalue!=LARGE && c==0) //checking for minimum level containing a leaf node
		{
			level=i;
			value=Svalue;
			c++;
		}
	}
	Svalue=value;

	return level;
}

int height(NODEPTR node) //recursive function to find height of a given tree
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->leftChild);
        int rheight = height(node->rightChild);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

int main() //main method
{
	NODEPTR rootPtr=NULL; //pointer to root node
	int n,i,data;

	printf("Input:- \nn (n>=1): "); //taking inputs
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&data);
		createBST(data,&rootPtr,rootPtr);
	}

	puts("Output:-\n"); //displaying output
	printf("%s%10s\n\n","Node:-","Parent:-");
	printParent(rootPtr);

	int level=levelOrderTrav(rootPtr); //max-min analysis
	printf("\nSmallest leaf from minimum level: element %d level %d.\n",Svalue,level-1);
	printf("Largest leaf from maximum level: element %d level %d.\n\n",Mvalue,height(rootPtr)-1);

	return 0;
} //end main
	
