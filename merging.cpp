#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node * previous;
	Node * next;
};
class List
{
	Node *head , *tail , * current ,* pre;
	Node *head1 , *tail1 , * current1 ,* pre1;
	public:
	List()
	{
		head=NULL;
		tail=NULL;
	}
	void insert ( int value)
	{
		Node * newNode = new Node;
		newNode->data=value;
		newNode->next=NULL;
		newNode->previous=NULL;
		if(head==NULL)
		{
			head=newNode;
			tail=newNode;
		}
		else if(value < head->data)
		{
			newNode->next=head;
			head->previous=newNode;
			head=newNode;
		}
		else if(value > tail->data)
		{
			newNode->next=NULL;
			newNode->previous=tail;
			tail->next=newNode;
			tail=newNode;
		}
		else
		{
	
			current = head;
			while(current && value > current->data)
			{
				pre = current;
				current= current->next;
			}
			newNode->next=pre->next;
			current->previous=newNode;
			pre->next=newNode;
			newNode->previous=pre;
		}
	}
	void insert1( int x)
	{
		Node * newNode1 = new Node;
		newNode1->data=x;
		newNode1->next=NULL;
		newNode1->previous=NULL;
		if(head1==NULL)
		{
			head1=newNode1;
			tail1=newNode1;
		}
		else if(x < head1->data)
		{
			newNode1->next=head1;
			head1->previous=newNode1;
			head1=newNode1;
		}
		else if(x > tail1->data)
		{
			newNode1->next=NULL;
			newNode1->previous=tail1;
			tail1->next=newNode1;
			tail1=newNode1;
		}
		else
		{
	
			current1 = head1;
			while(current1 && x > current1->data)
			{
				pre1 = current1;
				current1= current1->next;
			}
			newNode1->next=pre1->next;
			current1->previous=newNode1;
			pre1->next=newNode1;
			newNode1->previous=pre1;
		}
	}
		void display()
	{
		cout<<"list is :";
		Node *temp=head;
		while (temp)
		{
			cout<<temp->data;
			temp=temp->next;
			
		}
		cout<<endl;
	}
	void display1()
	{
		cout<<"list is :";
		Node *temp=head1;
		while (temp)
		{
			cout<<temp->data;
			temp=temp->next;
			
		}
		cout<<endl;
	}
};
int main()
{
	List obj;
	int  num ,num1,x ,x1;
	cout<<"How many number you want insert "<<endl;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"Enter the number ";
		cin>>x;
		obj.insert(x);
	}
	cout<<"How many number you want insert "<<endl;
	cin>>num1;
	for(int i=0;i<num1;i++)
	{
		cout<<"Enter the number ";
		cin>>x1;
		obj.insert1(x1);
	}
	obj.display();
	obj.display1();
}
