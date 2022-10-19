#include<iostream>
using namespace std;

struct node
{

int data;

struct node *next;
};

struct node *head ;
struct node *temp ;
struct node *temp1 ;



void create(int x)
{
struct node* newnode;
newnode = (struct node*) malloc(sizeof(struct node));
newnode->data=x;
newnode->next=NULL;

head= newnode;
temp=head;

// printf("data of new node: %d",newnode->data);
// cout<<"data of new node:"<<newnode->data;


}

void insert(int x)
{
struct node* nextnode;
nextnode = (struct node*) malloc(sizeof(struct node));
nextnode->data=x;
nextnode->next=NULL;
temp->next=nextnode;
temp=nextnode;

// printf("\ndata of next node: %d",nextnode->data);

}

void reverse()
{
    struct node* prev;//,temp2,curr;
    struct node* current;//,temp2,curr;
    struct node* next;//,temp2,curr;
    prev=head;
    current=head->next;
    next=head->next->next;
    while(current!=NULL)
    {
       next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }

    head=prev;
}

void display()
{
cout<<"the new list is :"<<endl;
temp1=head;
while(temp1!=NULL)
{
cout<<temp1->data<<endl;
temp1=temp1->next;
}

}

int main ()
{
int x=10;
create(x);
insert(20);
insert(30);

display();
display();
reverse();
display();



return 0;
}
