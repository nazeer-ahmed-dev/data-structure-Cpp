#include<iostream>
using namespace std;
class List
{
	int top;
	int size;
	int *pointer;	
	int c=0;
	public:
	void initilaize(int size1)
	{	
		size=size1;
		pointer= new int [size];
		top=-1;
	}
	void Push(int num)
	{
		if(top==size-1)
		{
			cout<<"Stack overflow "<<endl;
		}
		else
		{
			top++;
			pointer[top]=num;
			c++;
		}
	}

	void display()
	{
		for(int i=0;i<=top;i++)
		{
			cout<<pointer[i]<<" ";
		}
		cout<<endl;
	}
	List operator==(List obj3)
	{
		for(int i=0;i<c;i++)
		{
			if(pointer[i]==obj3.pointer[i])
			{
			}
		}
		return true;
	}
};

int main()
{
	List obj,obj3;
	int x;char ch;
	obj.initilaize(4);
	block:
	cout<<"Enter the mumber "<<endl;
	cin>>x;
	obj.Push(x);
	cout<<"Enter y to inert again "<<endl;
	cin>>ch;
	if(ch=='y')
	{
		goto block;
	}
	obj.display();
	
	obj3.initilaize(3);
	block2:
	cout<<"Enter the mumber "<<endl;
	cin>>x;
	obj3.Push(x);	cout<<"Enter y to inert again "<<endl;
	cin>>ch;
	if(ch=='y')
	{
		goto block2;
	}
	obj3.display();
	
	if(obj==obj3)
	{
		cout<<"yes";
	}
}

