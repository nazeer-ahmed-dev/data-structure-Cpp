#include<iostream>
using namespace std;
struct Node
{
	
	Node()
	{
		cout<<"called"<<endl;
	}
	Node(int num)
	{
		cout<<"h";	
	}
	Node(int num, int nu1m)
	{
		cout<<"h";	
	}
	~Node()
	{
		cout<<"destroy";
	}
};
int main()
{
	Node(2);
	Node *ptr=new Node(2,2);
	delete ptr;
}
