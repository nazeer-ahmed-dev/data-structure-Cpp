#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
	int data;
	Node *link;	
};
struct list
{
	Node *head , *curr;
	
	
	void insert()
	{
		Node *ptr=new Node;
	ptr->data=4;
	ptr->link=NULL;
		head=ptr;
		curr=head;
	}
	void display()
	{
		cout<<curr->data<<endl;
	//	cout<<ptr->data<<endl;
		cout<<head->data<<endl;
		cout<<curr->link<<endl;
		//cout<<ptr->link<<endl;
		cout<<head->link<<endl;
	}
};
int main()
{
	list obj;
	
	obj.insert();
	obj.display();
}
