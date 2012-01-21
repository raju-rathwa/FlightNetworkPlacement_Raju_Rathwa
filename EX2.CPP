#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct linked_list
{
int value;
struct linked_list *link;
};

typedef struct linked_list cqueue;

cqueue* insert(int data, cqueue *head)
{
cqueue *temp = head->link, *newnode = NULL;
while(temp->link != head->link)
{
temp = temp->link;
}

newnode = (cqueue*)malloc(sizeof(cqueue));
newnode->value = data;
if(head == NULL)
{
newnode->link = newnode;
return newnode;
}
else if(temp == head)
{
newnode->link = newnode;
head->link = newnode;
return head;
}
newnode->link = temp->link;
temp->link = newnode;

return head;
}

cqueue* delete_data(int data, cqueue *head)
{
cqueue *temp = head->link->link, *prev = head->link;
while(temp->value != data)
{
prev = temp;
temp = temp->link;
}
if(temp == head->link)
{
head->link = temp->link;
}

prev->link = temp->link;

return head;
}

void traverse(cqueue *head)
{
cqueue *temp = head->link;
while(temp->link!=head->link)
{
cout<<"\n  Data : "<<temp->value;
temp = temp->link;
}
cout<<"\n  Data : "<<temp->value;
}

int get_winner(int n, cqueue *head)
{
cqueue *temp = head->link;
int j =1;
while(head->link->link != head->link)
{
int i;
for(i = 2; i<=n; i++)
{
temp = temp->link;
}
head = delete_data(temp->value,head);
cout<<"\n\n\n\tRound : "<<j++<<endl;
cout<<"\n  Deleted Position : "<<temp->value<<endl;
temp = temp->link;
cout<<"\n  Next Start at Position : "<<temp->value<<endl;
traverse(head);
getch();
}
return head->link->value;
}


int main()
{
int m = 0, n = 0;
cqueue *head = insert(0,NULL);

cout<<"\n\t\tEnter M : ";
cin>>m;
cout<<"\n\t\tEnter N : ";
cin>>n;
int c;
for(c = 1; c<=m; c++)
{
head = insert(c,head);
}
cout<<"\n\n\tOriginal Sequence : \n";
traverse(head);
cout<<"\n\n\t  Winner For M : "<<m<<" & N : "<<n<<" is : Position : "<<get_winner(n,head);
getch();
return 0;
}