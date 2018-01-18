//Siddharth Thakur, 1601CS46
//Encrytion & Decryption

#include <stdio.h>
int main() //Main method
{
	int num,th,h,t,o,temp;  //to store thousand's, hundrend's, ten's and one's digit
	num=0;

	printf("Enter the four digit number to be encrypted: ");

	scanf("%d",&num); // extracting digits
	o=num%10;
	num=num-o;
	num=num/10;
	t=num%10;
	num=num-t;
	num=num/10;
	h=num%10;
	num=num-h;
	num=num/10;
	th=num%10;

        //encryption
	temp=t;
	t=(th+7)%10;
	th=(temp+7)%10;

	temp=o;
	o=(h+7)%10;
	h=(temp+7)%10;

	printf("The encrypted number: %d%d%d%d\n",th,h,t,o);

	printf("Enter the four digit number to be decrypted: ");
	scanf("%d",&num);

	o=num%10; //extracting digits
	num-=o;
	num=num/10;
	t=num%10;
	num=num-t;
	num=num/10;
	h=num%10;
	num=num-h;
	num=num/10;
	th=num%10;

        //decryption
	temp=t;
	if(th==7 ||th==8 || th==9)
        	t=th-7;
	else
		t=th+3;
	if(temp==7||temp==8||temp==9)
		th=temp-7;
	else
		th=temp+3;

	temp=o;
	if(h==7||h==8||h==9)
		o=h-7;
	else
		o=h+3;
	if(temp==7||temp==8||temp==9)
		h=temp-7;
	else
		h=temp+3;

	printf("The decrypted number: %d%d%d%d\n",th,h,t,o);
	return 0;
}
