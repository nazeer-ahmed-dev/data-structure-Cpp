#include<iostream>
#include<string.h>
#include<string>
using namespace std;
struct stack
{
	int top, top1;
	char *pointer;
	string *pointer1;
	
	void initialize(int size)
	{
		pointer = new char[size];
		top=-1;
		
		pointer1 = new string[size];
		top1=-1;
	}	
	void push(char x)
	{
		top++;
		pointer[top]=x;
	}
	void push1(char x)
	{
	//	cout<<char(int(x));
		top1++;
		pointer1[top1]=char(int(x));
		cout<<pointer[top1]<<" ";
	}
	void pop()
	{
		top--;
	}
	void pop1()
	{
		top1--;
	}
	void infixtopostfix(char x)
	{
		if(int(x)>=48 && int(x)<=57)
		{
			push1(x);
		}
	/*	else if(x=='+' || x=='/' || x=='-' || x=='*')
		{
			if(top=-1)
			{
				push(x);
			}
			else if(pointer[top]=='+' && x=='-')
			{
				push1(pointer[top]);
				pop();
				push(x);
			
			}
			else if(pointer[top]=='-' && x=='+')
			{
				push1(pointer[top]);
				pop();
				push(x);
			}
			else
			{
				push1(pointer[top]);
				pop();
			}
			
		}*/
	}
	void display()
	{
		for(int i=0;i<=top1;i++)
		{
			cout<<pointer1[i]<<" ";
		}
	}
};
int main()
{	stack obj;
	string exp="1+2-8+3";
	obj.initialize(exp.length());
	for(int i=0;i<exp.length();i++)
	{
		obj.infixtopostfix(exp[i]);
	}
}
