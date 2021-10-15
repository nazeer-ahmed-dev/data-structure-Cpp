#include <iostream>
using namespace std;
struct stack
{
	int maxSize,stackTop;
	char *Array;
	stack(int size)
	{
		if(size>0)
		{
			maxSize=size;
			Array=new char[maxSize];
			stackTop=0;
		}
		else
		{
			cout<<"Size is not valid so default size is 20"<<endl;
			maxSize=20;
			Array=new char[maxSize];
			stackTop=0;
		}
	}	
	void push(char ch)
	{
		if(!isFullStack())
		{
			Array[stackTop]=ch;
			stackTop++;
		}
	}	
	bool isFullStack()
	{
		return(stackTop==maxSize);
	}
	void display()
	{
		cout<<"your name in reverse order: "<<endl;
		for(int i=stackTop-1; i>=0; i--)
		{
			cout<<Array[i];
		}
	}
	
};
int main()
{
	int size;
	string name;
	up:
	cout<<"Enter size of stack"<<endl;
	cin>>size;
	stack obj(size);
	cin.ignore();
	cout<<"Enter your name: ";
	getline(cin,name);
	for(int i=0; i<name.length(); i++)
	{
		
		obj.push(name[i]);
		if(obj.isFullStack())
		{
			cout<<"Stack is full! your name size exceeds the size of stack"<<endl;
			goto up;
		}
	
	}
	obj.display();
}
