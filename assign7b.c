//Siddharth Thakur, 1601CS46, Date-7th March, 2017
//Lexicographic Sorting of Words
 
#include <stdio.h>
#include <stdlib.h> //including the necessary header files
#include <string.h>

int main(void) //main method
{
	int i,j; //iteration variables
	int n; //number of words in input
	char word[50]={'\0'};// temporarily stores the input word

	puts("\nInput:-"); //taking inputs
	scanf("%d",&n);
	char *words[n]; //array of pointers to store the input words
	for(i=0;i<n;i++)
	{
		scanf("%s",word);
		words[i]=calloc(strlen(word)+1,sizeof(char));
		strcpy(words[i],word);
		
	}
	
	for(i=0;i<n;i++) //sorting in lexicographically order
	{
		for(j=0;j<n-1;j++)
		{

			if(strcasecmp(words[j],words[j+1])>=0) //comparing the words
			{
				strcpy(word,words[j]); //swapping for lexicographic order
				words[j]=calloc((strlen(words[j+1])+1),sizeof(char));
				strcpy(words[j],words[j+1]);
				words[j+1]=calloc((strlen(word)+1),sizeof(char));
				strcpy(words[j+1],word);
			}
		}
	}
	
	puts("\nOutput:-"); //printing in lexicographic order
	for(i=0;i<n;i++)
		printf("%s\n",words[i]);
	return 0;
}
				


