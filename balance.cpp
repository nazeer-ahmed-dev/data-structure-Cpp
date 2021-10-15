#include<iostream>
using namespace std;
struct stack
{
	char *pointer;
	int top;
	
	void initialize(int size)
	{
		pointer = new char[size];
		top=-1;	
	}
	void push(char x)
	{
		top++;
		pointer[top]=x;
	}
	void pop()
	{
		top--;
	}
	void value()
	{
		if(top==-1)
		{
			cout<<"balanced"<<endl;	
		}
		else
		{
			cout<<"unblanced"<<endl;
		}
	}
	void balance(char x)
	{
		if(x=='[' || x=='{' || x=='(')
		{
			push(x);
		}
		else if(x==']' || x=='}' || x==')')
		{
			if(x==']' &&  pointer[top]=='[')
			{
				pop();
			}
			else if(x=='}' && pointer[top]=='{')
			{
				pop();
			}
			else if(x==')' && pointer[top]=='(')
			{
				pop();
			}
			else
			{
				push(x);
			}
		}
	}
};
int main()
{
	stack object;
	string bracket;
	cout<<"ENTER THE BRACKETS : ";
	cin>>bracket;
	object.initialize(bracket.length());
	for(int i=0;i<bracket.length();i++)
	{
	object.balance(bracket[i]);
	} 
	object.value();
}
