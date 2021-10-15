// paranthesis matching
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
struct stack
{
	int top;
	int size;
	int counter;
	char *pointer;
};
void initlze(stack *p,int size1)
{
	p->pointer=new char[size1+1];
	p->counter=-1;
}
void function(char array[] , stack *p)
{
	p->counter++;
	if(array[p->counter]=='[' || '{' || '(')
	{
		char s=array[p->counter];
		push(&p,s);
	}
	else if(array[p->counter]==']' || '}' || ')')
	{
		pop(&p);	
	}
	else if(p->top==-1)
	{
		cout<<"balance"<<endl;
	 } 
}
void push(stack *p,char s)
{
	p->top++;
	p->pointer[p->top]=s;
}
void pop()
{
	p->top--;
}
int main()
{
	stack obj;
	string  n = "{((a+b)*(c-d))}";
	int s=n.length();
	char array[s+1];
	//strcpy(array,n.c_str());
	//for(int i=0;i<s;i++)
	//{
	//	cout<<array[i]<<" ";
	//}
	initlze(&obj,s);
	function(array , &obj);
}
