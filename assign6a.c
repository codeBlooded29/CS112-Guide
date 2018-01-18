//Siddharth Thakur, 1601CS46, Date-15/02/2017
// Program to print all unique permutations

#include <stdio.h> //including necessary header files
#include <stdlib.h>
#include <string.h>

int comparison(const void*, const void*); //function for library function qsort()
int fact(int); //recursive function to find factorial
void swapping(char*, char*); //function two swap two characters a and b
int ceilSearch(char[], char, int, int); //Function to find the index of the smallest character which is greater than 'first' and is present in string[l....h]
void uniquePermutations(char[]); // Print all permutations of string in order

// main method
int main(void)
{
	int i,n;
	
	printf("Number of letters(upto 5): ");
	scanf("%d",&n);
	
	char letters[n];

	printf("Enter %d letters (space separated): ",n);
	for(i=0;i<n;i++)
		scanf(" %c",&letters[i]);
	
	printf("\nOutput:-\nThe possible words are: ");
    	uniquePermutations(letters);
	puts("");
    	return 0;
} 

//function for library function qsort()
int comparison(const void *a, const void * b)
{
    return (*(char *)a-*(char *)b);
}

int fact(int n) //recursive function to find factorial
{
	(n==0 || n==1)?1:(n*fact(n-1));
}
 
//function two swap two characters a and b
void swapping(char* a,char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
 
//Function to find the index of the smallest character
// which is greater than 'first' and is present in string

int ceilSearch(char string[], char first, int l, int h)
{
    int ceilIndex = l;
 
    //iterating through rest of the elements and find
    // the smallest character greater than 'first'
    for (int i = l+1; i <= h; i++)
        if (string[i] > first && string[i] < string[ceilIndex])
            ceilIndex = i;
 
    return ceilIndex;
}
 
// Print all permutations of string in sorted order
void uniquePermutations(char str[])
{
    int size = strlen(str); //size of string
 
    // Sortingin increasing order
    qsort(str, size, sizeof( str[0] ), comparison);
 
    // Print permutations one by one
    int flag = 1;
    while (flag==1)
    {
       	printf("%s, ",str);
 
        int i;
        for (i = size - 2; i >= 0; --i)
            if (str[i] < str[i+1])
                break;
 
        // If there is no such chracter, all are sorted in decreasing order,
        // means we just printed the last permutation and done.
        if (i == -1)
            flag = -1;
        else
        {
            //Ceil of  char1 in right of first character.
            // Ceil of a character is the smallest character greater than it
            int ceilIndex = ceilSearch(str, str[i], i + 1, size - 1);
 
            // Swapping first with second characters
            swapping(&str[i], &str[ceilIndex]);
 
            // Sort the string on right of char 1
            qsort(str + i + 1, size - i - 1, sizeof(str[0]), comparison);
        }
    }
}

