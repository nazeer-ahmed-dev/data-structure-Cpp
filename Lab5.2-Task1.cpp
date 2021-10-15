#include<iostream>
#include<string.h>
using namespace std;
class Stack
{
	public:
	int top;
	int size;
	char *pointer;
	
	Stack()
	{
		size = 50;
		top=-1;
		pointer = new char[size];
	}
	
	bool isEmpty()
	{
		if(top==-1)
		return true;
		else
		false;
	}
	
	bool isFull()
	{
		if(top==size-1)
		return true;
		else
		false;
	}
	void Push(char word)
	{
		if(!isFull())
		{
			top++;
			pointer[top] = word;
				
		}
	}
	void reversedisplay()
	{
		for(int i=top; i>=0; i--)
		{
			cout<<pointer[i]<<" ";
		}	
	}	
	
};

int main()
{
	Stack obj;	
	string name;
	cout<<"Enter name: ";
	getline(cin, name);
	
	for(int i=0; i<name.length(); i++)
	{
		obj.Push(name[i]);
	}
	
	obj.reversedisplay();
		cout<<endl;
	obj.display();

	return 0;
}
