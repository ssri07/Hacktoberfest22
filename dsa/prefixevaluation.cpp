// stack operations using arrays 

#include <iostream>
#include<string>
#include<cmath>

using namespace std;

#define m 10

string stack;
int top=-1;     

void push(char x)
{
    if(top>=(m-1))
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

void reverseStr()
{
    int n = stack.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(stack[i], stack[n - i - 1]);
}

void display()
{
    
if(top==-1)
{
cout<<"stack underflow\n";
}
else{
    cout<<"result is: ";
   for(int i=top;i>=0;i--)
    {
     cout<<int(stack[i])<<endl;
    }
}

}

void prefix_evaluation ()
{
     int l=stack.length();

   for(int i=0;i<l;i++)
    {
        if(stack[i]>=49&&stack[i]<=57)
        {
            push(int(stack[i])-'0');
           // cout<<(int(stack[i]));
        }

        else{
            int sol;
            switch (stack[i])
            {
                case '*':
                  stack[top-1]=(int(stack[top]))*(int(stack[top-1]));
                  top--;
                  break;

                  case '+':
                  stack[top-1]=(int(stack[top]))+(int(stack[top-1]));
                  top--;
                  break;

                  case '/':
                  stack[top-1]=(int(stack[top]))/(int(stack[top-1]));
                  top--;
                  break;

                  case '-':
                  stack[top-1]=(int(stack[top]))-(int(stack[top-1]));
                  top--;
                  break;

                  case '%':
                  stack[top-1]=(int(stack[top]))%(int(stack[top-1]));
                  top--;
                  break;

                  case '^':
                  stack[top-1]=pow((int(stack[top-1])),(int(stack[top])));
                  top--;
                  break;

                  default :
                  cout<<"invalid";
                 
            }
        }
    }
}

int main()
{
    cout<<"enter the expression\n";
       cin>>stack;
       reverseStr ();
    prefix_evaluation ();
    display();
  

    return 0;
}





