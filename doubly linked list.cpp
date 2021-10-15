//doubly linked list
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node * next;
	Node * pre;
};
class List
{
	Node * head , *tail , *curr ,*pre1;
	public :
		List()
		{
			head=NULL;
			tail=NULL;
			
		}
		void Insert(int num , int index)
		{
			Node * newNode =new Node;
			newNode->data=num;
			newNode->pre=NULL;
			curr=head;
			if(index==0 && head==NULL)
			{ 	
				if(head==NULL)
				{
					newNode->next=head;
					head=newNode;
					tail=newNode;		
				}
				else
				{
					newNode->next=head;
					head->pre=newNode;
					head=newNode;
				}
				
			}
			else
			{
				curr=head;
				for(int i=1;i<=index;i++)
				{
					pre1=curr;
					curr=curr->next;
				}
				cout<<curr->data;
				cout<<pre1->data;
				
				newNode->next=curr->next;
				curr->pre=newNode;
				newNode->pre=pre1->next;
				pre1->next=newNode;	
				
			}
		}
	void display()
	{
		Node * temp=head;
		cout<<"Forward ";
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
		void display1()
	{
		Node * temp=tail;
		cout<<"reverse ";
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->pre;
		}
		cout<<endl;
	}
};
int main()
{
	List obj;
	int n, numb , index;
	cout<<"how many number "<<endl;
	cin>>n;
	for(int i=0;i<n; i++)
	{
		cout<<"Enter the number ";
		cin>>numb;
		cout<<"Enter the index ";
		cin>>index;
		obj.Insert(numb , index);
	}
	obj.display();
	obj.display1();	
}
