#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
class List
{
	Node * head;
	int counter;
	public:
	List()
	{
		head=NULL;
		counter=0;
	}
	void insert(int x , int index)
	{
		Node * newnode=new Node;
		Node * curr;
	
		
		if(index<0 || index>counter)
		{
			cout<<"Index not matched"<<endl;
		}
		else
		{
			newnode->data=x;
			newnode->next=NULL;		
			if(index==0)
			{
				//newnode->next=head;
				head=newnode;
			}
			else
			{
				curr=head;
				for(int i=1;i<index;i++)
				{
					curr=curr->next;
				}
				newnode->next=curr->next;
				curr->next=newnode;
			}
			counter ++;
		}
	}
	
	void display ()
	{
		cout<<"list is :";
		Node *temp=head;
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	void deleteNode(int serchNode)
	{
		Node * curr=head ,*q,*previous;
		while(curr && curr->data!=serchNode)
		{
			previous=curr;
			curr=curr->next;		
		}		
		if(curr)
		{
			if(previous)
			{
				previous->next=curr->next;
				delete curr;
			}
			else
			{
				head=curr->next;
				delete curr;
			}
		}
		else
		{
			cout<<"not found"<<endl;
		}
				/*/cout<<temp->data;
				q=temp1;
				previous->next=temp1->next;
				delete q;
				cout<<"h";
				temp1=temp1->next;
				//break;*/
				/*previous=temp1;*/
			
	}
};
int main()
{
	int num1,num,index;
	List obj;
	cout<<"How many numbers you want to insert :";
	cin>>num1;
	for(int i=0;i<num1;i++)
	{
		cout<<"Enter the number : ";
		cin>>num;
		cout<<endl;
		cout<<"Enter the index  : ";
		cin>>index;
		obj.insert(num,index);
		obj.display();
	}
	int number1;
	cout<<"ENter the value which you wnat to delete :";
	cin>>number1;
	
	obj.deleteNode(number1);
	obj.display();
}

