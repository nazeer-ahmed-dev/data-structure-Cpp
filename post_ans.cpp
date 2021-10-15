#include<iostream>
#include<sstream>
using namespace std;
struct post_Ans
{
	int top;
	int sum=0;
	char *pointer;
	
	void initilize(int x)
	{
		pointer = new char[x];
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
	void Ans(char x)
	{
		if(int(x)>48 && int(x)<=57)	
		{
			push(x);
		}	
		else if(x=='+')
		{
			
			sum=(pointer[top-1]+pointer[top])-96;
			pop();
			pop();
			push(sum);
		}
		else if(x=='*')
		{
			cout<<int(pointer[top-1]*pointer[top]);
			//top=top-2;
		//	push(sum);
		}
		
		
	}
	void display()
	{
		for(int i=0;i<=top;i++)
		{
			cout<<char(pointer[i])<<" ";
		}
	}
};
int main()
{
	post_Ans object;
	char x;
	string name="533+";
	object.initilize(name.length());
	for(int i=0;i<name.length();i++)
	{
		x=name[i];
		object.Ans(x);
	}
	object.display();
}
