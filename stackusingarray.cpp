// stack operations using arrays 

#include <iostream>

using namespace std;

int stack[5];
int top=-1,Max=5;     

void push(int x)
{
    if(top>=(Max-1))
    {
        cout<<"stack overflow\n";
        
    }
    
    else
    {
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top<=-1)
    {
        cout<<"stack underflow\n";
    }
    
    else
    {
        top--;
    }
    
}

void display()
{
if(top==-1)
{
cout<<"stack underflow\n";
}
for(int i=0;i<=top;i++)
{
cout<<stack[i]<<endl;
}
}

int main()
{
    push(1);
push(2);
push(3);
push(4);
push(5);
display();

push(10);

    pop();
pop();
display();

    return 0;
}
