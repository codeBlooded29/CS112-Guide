//Siddharth Thakur, 1601CS46, Date - 7th March,2017
//Matrix Analysis

#include <stdio.h>
#include <stdlib.h> //including required header files
#include <math.h>
#define EPSILON 0.01 //floating point least count for comparison

int determinant(int **p,int rows,int columns) //recursive function to find determinant of a matrix
{
	int i=0,j=0; //iteration variables
	if(rows==2 && columns==2) //base case
		return (**p * *(*(p+1)+1) - *(*(p+1)) * *(*p+1));
	else 
	{
		int detM=0; //to store determinant of the matrix

		for(j=0;j<columns;j++)
		{
			int k,l;

			int **minorM; //minor matrix of an element of our matrix
			minorM=(int**)calloc(rows-1,sizeof(int*)); //dynamic space allocation
			for(k=0;k<columns;k++)
				minorM[k]=(int*)calloc(columns-1,sizeof(int));
				
			int r=1,c=0;
			for(k=0;k<rows-1;k++) //creation of the minor matrix
			{
				c=0;
				for(l=0;l<columns-1;l++)
				{
					if(c!=j && c<columns && r<rows)
					{
						minorM[k][l]=*(*(p+c)+r);
						c++;
					}
					else
					{
						c++;
						if(c<columns && r<rows)
						{
							minorM[k][l]=*(*(p+c)+r);
							c++;
						}
					}							
				}
				r++;
			}
		
			int minor=determinant(minorM,rows-1,columns-1); //calculation of minor through recursion
			int cofactor=pow(-1,j) * minor; //cofactor calculation
			detM+=*(*(p+j)) * cofactor; //determinant calculation
		}
		return detM;
	}
}

int gcd(int x,int y) //function to find gcd of two numbers
{
	return ((x%y==0)?y:(gcd(y,x%y)));
}		

int main(void) //main method
{
	int rows,columns; //to store the number of rows and columns respectively
	int i,j; //iteration varibles
	int k,l;
	printf("Enter the size of the matrix (m*n) (space separated) = "); //taking inuts
	scanf("%d %d",&rows,&columns);
	
	int **matrix; //dynamically creating the matrix
	matrix=(int**)calloc(rows,sizeof(int*));
	for(i=0;i<rows;i++)
		matrix[i]=(int*)calloc(columns,sizeof(int));
	
	puts("");
	for(i=0;i<rows;i++) //taking input of elements of the matrix
	{
		printf("Enter the elements of row %d (space separated) = ",i+1);
		for(j=0;j<columns;j++)
			scanf("%d",&matrix[i][j]);
	}
	
	if(rows==columns) //if matrix is a square one
	{
		int adjM[rows][columns]; //adjoint matrix
		int detM=0; //to store determinant
		
		int maxMinor=0; //to store the value of maximum minor
		int lr=0,lc=0; //to store the index of element having maximum minor

		for(i=0;i<rows;i++)
		{
			for(j=0;j<columns;j++)
			{
				int k,l;

				int **minorM; //minor matrix
				minorM=(int**)calloc(rows-1,sizeof(int*));
				for(k=0;k<rows;k++)
					minorM[k]=(int*)calloc(columns-1,sizeof(int));
				 
				int r=0,c=0; //creating minor matrix 
				for(k=0;k<rows-1;k++)
				{
					c=0;
					for(l=0;l<columns-1;l++)
					{
						if(r!=i && r<rows)
						{
							if(c!=j && c<columns)
							{
								minorM[k][l]=matrix[r][c];
								c++;
							}
							else
							{
								c++;
								if(c<columns)
								{
									minorM[k][l]=matrix[r][c];
									c++;
								}
							}
						}
						else
						{
							r++;
							if(c!=j && c<columns && r<rows)
							{
								minorM[k][l]=matrix[r][c];
								c++;
							}
							else
							{
								c++;
								if(c<columns && r<rows)
								{
									minorM[k][l]=matrix[r][c];
									c++;
								}
							}
						}
							                						
					}
					r++;
				}
			
				int minor=determinant(minorM,rows-1,columns-1); //calculating minor through recursion
				if(maxMinor<=minor) //determining maximum minor
				{
					maxMinor=minor;
					lr=i+1;
					lc=j+1;
				}
		
				int cofactor=pow(-1,i+j)*minor; //calculating cofactor

				if(i==0)
					detM+=matrix[i][j]*cofactor;
				adjM[j][i]=cofactor;
			}
		}
	
		if(detM!=0) //invertible case
		{
			printf("\nThe entered matrix is invertible. ");
			printf("\nThe inverse matrix is:- \n"); //printing inverse matrix
			int numerator,denominator,flag;
			for(i=0;i<rows;i++)
			{
				for(j=0;j<columns;j++)
				{
					int hcf=1;
					if((adjM[i][j]>0 && detM>0) || (adjM[i][j]<0 && detM<0))
					{
						numerator=adjM[i][j];
						denominator=detM;
						hcf=gcd(numerator,denominator);
						numerator/=hcf;
						denominator/=hcf;
						if(denominator!=1)
							printf("%10d/%d",numerator,denominator);
						else
							printf("%10d",numerator);
						continue;
					}

					if(adjM[i][j]<0 && detM>0)
					{
						numerator=-1*adjM[i][j];
						denominator=detM;
						hcf=gcd(numerator,denominator);
						numerator/=hcf;
						denominator/=hcf;
						if(denominator!=1)
							printf("%10d/%d",-1*numerator,denominator);
						else
							printf("%10d",-1*numerator);
						continue;
					}
				
					if(adjM[i][j]>0 && detM<0)
					{
						numerator=adjM[i][j];
						denominator=-1*detM;
						hcf=gcd(numerator,denominator);
						numerator/=hcf;
						denominator/=hcf;
						if(denominator!=1)
							printf("%10d/%d",-1*numerator,denominator);
						else
							printf("%10d",-1*numerator);
						continue;
					}
					
					if(adjM[i][j]==0)
						printf("%10c",'0');
				}
				puts("");
			}
							
			printf("\nThe entered matrix is a square matrix.\n");
			printf("The position of the element with highest minor is: i = %d, j = %d\n\n",lr,lc);
		}
		else //non invertible case (determinant = 0)
		{
			puts("The entered matrix is non-invertible.");
			printf("The entered matrix is a square matrix.\n");
			printf("The position of the element with highest minor is: i = %d, j = %d\n\n",lr,lc);
		}
	}
	else //non-square matrix (rectangular case)
		puts("\nThe matrix entered isn't a square matrix so no analysis possible!\n");
	
	return 0; //end main
}

	

		
				
		
			
		
