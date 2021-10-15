#include<iostream>
using namespace std;
struct array
{
	int size;
	int top;
	int *Pointer;
};
void initialize(array *p)
{
	p->Pointer=new int[p->size];
	p->top=-1;
}
void push(array *p,int num)
{
	if(p->top==p->size-1)
	{
		cout<<"STack overflow"<<endl;
	}
	else
	{
		p->top++;
		p->Pointer[p->top]=num;
	}
}
void pop(array *p)
{
	
}
void display(array *p)
{
	for(int i=0;i<=p->top;i++)
	{
		cout<<p->Pointer[i]<<" ";	
	}	
	cout<<endl;
}
int main()
{
	array obj;
	char ch1;
	int num;
	cout<<"Enter the size : ";
	cin>>obj.size;
	initialize(&obj);
	block:
	cout<<"Insert (press 1)"<<endl;
	cout<<"delete (press 2)"<<endl;
	cout<<"search (press 3)"<<endl;
	cin>>ch1;
	if(ch1='1')
	{
		cout<<"Enter the element "<<endl;
		cin>>num;
		push(&obj,num);
		display(&obj);
		goto block;
	}
	else if(ch1=='2')
	{
		
	}
	else if(ch1=='3')
	{
		
	}
	else
	{
		goto block;
	}
}
