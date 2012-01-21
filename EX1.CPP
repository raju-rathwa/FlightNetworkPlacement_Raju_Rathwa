#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

int stack[10];
int pattern[10];
static int top = 0;
static int nextpush = 0;

void push(int digit)
{
if(stack[top-1] == 9)
{
cout<<"\n\n\tStack Full!";
return;
}
if(top == 0 || nextpush == digit) //excluding first push, pushing in order
{
stack[top++] = digit;
nextpush = digit+1;
cout<<"\n\n\tPush Succeeded";
return;
}
cout<<"\n\n\tInvalid Push! Push in order!";
}

int pop()
{
if(top == 0)
{
cout<<"\n\n\tStack Empty!";
return -1;
}
return  stack[--top];
}

void show_stack()
{
int i;
cout<<"\n\n\t\tCurrent Stack : \n\t";
for(i = top; i > 0; i--)
cout<<"  "<<stack[i-1];
if(top == 0)
cout<<"Empty!";
}

void menu()
{
cout<<"\n\n\t\t Select an Operation : ";
cout<<"\n\n\t   1. Push.";
cout<<"\n\t   2. Pop.";
cout<<"\n\t   3. Show.";
cout<<"\n\t   4. Check Pattern.";
cout<<"\n\t   5. Exit.";
cout<<"\n\n\tEnter Here : ";
}

int validate()
{
int i;
for(i = 0; i<=9; i++)
{
if(pattern[i]>9 || pattern[i]<0)
return 0;
}

int status[10];
for(i = 0; i<10; i++)
status[i] = 1;

for(i = 0; i<9; i++)
{
if(status[pattern[i]])
status[pattern[i]] = 0;
else
return 0;

if(pattern[i]>pattern[i+1])
{
if((pattern[i] - pattern[i+1]) != 1)
{
int j;
for(j = pattern[i]-1; j>pattern[i+1]; j--)
{
if(status[j])
return 0;
}
}
}
}

return 1;
}

int main()
{
int choice, digit;

do
{
menu();
cin>>choice;

switch(choice)
{
case 1: cout<<"\n\n\tEnter Digit : ";
	cin>>digit;
	push(digit);
	break;

case 2: int num = pop();
	if(num != -1)
	cout<<"\n\n\tPopped Digit : "<<num;
	break;

case 3: show_stack();
	break;
case 4: cout<<"Enter a pattern of 10 distinct digits (seperated by space) : ";
	int i;
	for(i = 0; i<=9; i++)
	cin>>pattern[i];
	if(validate())
	cout<<"\n\n\tValid Pattern!";
	else
	cout<<"\n\n\tInvalid Pattern!";
	break;
}
}
while(choice != 5);
getch();
return 0;
}