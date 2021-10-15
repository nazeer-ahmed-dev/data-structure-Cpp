#include<iostream>
using namespace std;
struct stack
{
	int top;
	char *pointer;
	
	void initialize(int x)
	{
		pointer = new char[x];
		top=-1;
	}
	void push(char numb)
	{
		top++;
		pointer[top]=numb;
	}
	void pop()
	{
		top--;
	}
	void balanced(char x)
	{
		if(x=='(' || x=='{' || x=='[')
		{
			push(x);
		}
		else if(x==')' || x=='}' || x==']')
		{
			if(pointer[top]=='(' && x==')')
			{
				pop();
			}
			else if(pointer[top]=='{' && x=='}')
			{
				pop();
			}
			else if(pointer[top]=='[' && x==']')
			{
				pop();
			}
			else 
			{
				push(x);
			}
		}
		
	
	}
	int bal()
	{
		if(top==-1)
		{
			cout<<"balanced"<<endl;
		}
		else
		{
			cout<<"not balced";
		}
	}
};
int main()
{
	stack obj;
	char a;
	string name="([)]";
	obj.initialize(name.length());
	for(int j=0;j<name.length();j++)
	{
		a=name[j];	
		obj.balanced(a);
	}
	obj.bal();
	
	
}
