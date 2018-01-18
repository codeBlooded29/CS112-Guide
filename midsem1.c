//Siddharth Thakur, 1601CS46, Date-28/02/2017
//Manipulation on Array of Integers

#include <stdio.h> //standard input output header file

int i,j; //global iteration variables

//method to print an array
void printArray(int a[],int size){
	printf("{ ");
	for(i=0;i<size;i++)
		printf("%d, ",a[i]);
	puts("}");
}

//main method
int main(){
	int n; //total number of elements
	printf("\nEnter n: "); //taking inputs
	scanf("%d",&n);
	int a[n],b[n]; //arrays a[] and b[]
	
	printf("Enter %d Elements: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[n-1-i]=a[i]; //storing in reverse order in array b[]
	}
	puts("");

	printf("Task (a):-\na[] = "); //output of task (a)
	printArray(a,n);
	printf("b[] = ");
	printArray(b,n);
	puts("");
	
	//sinking of negative elements in array b[] without changing order
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(b[j]<0 && b[j+1]>=0){
				int temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	
	printf("Task (b):-\nb[] = "); //output of task(b)
	printArray(b,n);
	puts("");

	return 0;
} 
	
	
