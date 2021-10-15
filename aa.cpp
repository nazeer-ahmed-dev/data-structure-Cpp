#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
	int data;
	Node *link;	
};
class List
{
	Node *current;
	int counter;
	public:
		Node *head;
	List()
	{
		head=NULL;
		counter=0;
	}
	void Insert(int value , int index)
	{
		Node * newNode= new Node;
		newNode->data=value;
		newNode->link=NULL;
		if(index==0)
		{
			newNode->link=head;
			head=newNode;
		}
		else
		{
			current=head;
			
			
			for(int i=1;i<index;i++)
			{
				current=current->link;
			}
			newNode->link=current->link;
			current->link=newNode;
			//current=newNode;
			newNode=current->link;
		}
		counter++;
	}
	void display()
	{
		cout<<"List is :";
		Node *temp=head;
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->link;
		}
		cout<<endl;
	}
	void shallowcopy()
	{
		Node * temp= head;
		temp=temp->link;
		*temp=*head;
	}
};
int main()
{
	List obj;
	int x,y,index,value,number,serchnumber;
	cout<<"HOW MANY NODE YOU WANT TO CREATE"<<endl;
	cin>>number;
	for(int i=0;i<number;i++)
	{
		cout<<"Enter the index ";
		cin>>index;
		cout<<"Enter the value ";
		cin>>value;
		obj.Insert(value,index);			
	}
	obj.display();
}
