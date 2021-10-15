#include<iostream>
using namespace std;
struct stack
{
	char *pointer;
	int top;
	
	void initialize(int size)
	{
		pointer= new char [size];
		top=-1;
	}
	void push(char x)
	{
		top++;
		pointer[top]=x;
	}
	void pop()
	{
		cout<<pointer[top];
		top--;
		
	}
};
int main()
{
	stack object;
	string name;
	cout<<"Enter the name "<<endl;
	cin>>name;	
//	cout<<name.length();
	object.initialize(name.length());
	for(int i=0;i<name.length();i++)
	{
		object.push(name[i]);		
		
	}
		for(int i=0;i<name.length();i++)
	{
		object.pop();		
		
	}
}
