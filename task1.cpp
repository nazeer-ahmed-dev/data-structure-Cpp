#include<iostream>
using namespace std;
struct stack
{
	int top;
	int size;
	int *pointer;	
};
struct stack1
{
	int top1;
	int size1;
	int *pointer1;
};
void initilaize(stack *p)
{
	p->pointer= new int [p->size];
	p->top=-1;
}
void Push(stack *p,int num)
{
	if(p->top==p->size-1)
	{
		cout<<"Stack overflow "<<endl;
	}
	else
	{
		p->top++;
		p->pointer[p->top]=num;
	}
}
void pop(stack *p)
{
	if(p->top==-1)
	{
		cout<<"STACk underflow"<<endl;
	}
	else
	{
		p->top--;

	}
	
	
}
void display(stack *p)
{
	for(int i=0;i<=p->top;i++)
	{
		cout<<p->pointer[i]<<" ";
	}
	cout<<endl;
}
void copyStack(stack *p,stack1 *q)
{
	
	q->size1=p->size;
	q->top1=p->top;
	
	q->pointer1= new int[q->size1];
	
	for(int i=0;i<=p->top;i++)
	{
			q->pointer1[i]=p->pointer[i];
	}
	delete []p->pointer;
}
void display1(stack1 *p)
{
	for(int i=0;i<=p->top1;i++)
	{
		cout<<p->pointer1[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	stack1 obj1;
	stack obj;
	int num;
	cout<<"Enter the size of element "<<endl;
	cin>>obj.size;
	initilaize(&obj);
	block:
	cout<<"Insert (1)"<<endl;
	cout<<"delete (2)"<<endl;
	cout<<"copy stack (3)"<<endl;
	char ch;
	cin>>ch;
	if(ch=='1')
	{
		cout<<"Enter the number "<<endl;
		cin>>num;
		Push(&obj,num);
		display(&obj);
		goto block;
	}
	else if(ch=='2')
	{
		pop(&obj);
		display(&obj);
		goto block;
	}
	else if(ch=='3')
	{
		copyStack(&obj,&obj1);
		display1(&obj1);
		display(&obj);
		goto block;
	}
	else
	{
		goto block;
	}
}
