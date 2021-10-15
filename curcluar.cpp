#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *link;
};
class List
{
	Node *head , *tail;
	public:
	List()
	{
		head=NULL;
		tail=NULL;
	}
	void insert(int value , int index)
	{
		Node * node = new Node;
		node->data=value;
		node->link=NULL;
		
		if(head==NULL)
		{
			head=node;
			tail=node;
			tail->link=head;
		}
		else if(index==0)
		{
			node->link=head;
			head=node;
			tail->link=head;
		}
	}	
	void display()
	{
		Node *temp=head;
		while(temp)
		{
			cout<<temp->data;
			temp=temp->link;
			if(temp==head)
			{
				break;
			}
		}
	}
};
int main()
{
	int value , index ,number;
	List obj;
	cout<<"How many number want to insert "<<endl;
	cin>>number;
	for(int i=0;i<number;i++)
	{
		cout<<"Enter the index : ";
		cin>>index;
		cout<<"Enter the number : ";
		cin>>value;
		obj.insert(value,index);
		obj.display();
		
		
	}
	
}
