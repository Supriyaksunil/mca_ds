#include<stdio.h>
int top=-1,s[5],i,item,choice;
void push(int item)
{
	if(top>=5)
	{
	printf("Stack is full\n");

	}
	else{
		s[top]=item;
		top=top+1;
	}
}
void pop()
{
if(top<=-1)
{
printf("statck is empty\n");

 }else{
 item=s[top];
 top=top-1;
 }
 }
 int main()
 {
 while(1)
 {
 printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
 printf("Enter your choice:");
 scanf("%d",&choice);
 if(choice==4){
 break;
 }
 if(choice==1){
 	printf("Enter the elements\n");
 	scanf("%d",&item);
 	push(item);
 }
 if(choice==2)
 {
 printf("pop Element\n");
 pop();

 }
 if(choice==3)
 {
 printf("Display\n");
 for(i=top-1;i>=-1;i--)
 {
 printf("%d\n",s[i]);
 }
 }
}
 return 0;
 }

