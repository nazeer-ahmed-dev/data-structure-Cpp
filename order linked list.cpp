#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
	int data;
	Node * link;
};
class List
{
	Node  *curr , *pre;
	public: 	
	Node * head;									/// for accessing everwhere
	List()		
	{
		head=NULL;
	}
	void Insert(int x)   								 	//insert NODES.
	{
		Node * NewNode= new Node;
		NewNode->data=x;
	//	NewNode->link=NULL;
		if(head==NULL) 								// at the begning
		{
			NewNode->link=head;
			head=NewNode;
		}	
		else if(x < head->data)
		{
			NewNode->link=head;
			head=NewNode;
		}
		else
		{
			curr=head;
			while(curr &&  x > curr->data )
			{		
				pre=curr;
				curr=curr->link;
			
			}	
			NewNode->link=pre->link;
			pre->link=NewNode;
			
		}
	}
	bool sortedOrNot()
	{
		Node *  temp=head;
		int x=(-32768);
		while(temp)
		{
			if(temp->data < x)
			{
				return false;
			}
			x=temp->data;
			temp=temp->link;
		}
		cout<<endl;
		return true;
	}	
	void removeDuplicate()
	{
		Node *temp = head;
		Node *pre = temp->link;
		while(temp)
		{
			
			if(pre->data != temp->data)
			{
				pre=temp;
				temp=temp->link;
			}
			else
			{
				pre->link=temp->link;
				delete temp;
				temp=temp->link;
			}
		}
		display();
		
	}
void display()
{
	Node *temp=head;
	cout<<"LIST IS : ";
	while(temp)
	{
		cout<<temp->data<" ";
		temp=temp->link;
	}
}
	
};
int main()
{
	List obj;
	int num,x;
	cout<<"How many number you want insert "<<endl;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"Enter the number ";
		cin>>x;
		obj.Insert(x);
	}
	obj.display();
	cout<<obj.sortedOrNot();
	obj.removeDuplicate();
}
