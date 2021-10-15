#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
	Node *pre;
};
class List
{
	Node *head , *tail;
	int counter;
	public:
	List()
	{
		head=NULL;
		tail=NULL;
		counter=0;
	}
	void insert(int index , int number)
	{
		Node *NewNode=new Node;
		Node *curr;
		NewNode->data=number;
		if(index>counter || index <0)
		{
			cout<<"Not matched "<<endl;
		}
		else
		{
			if(index==0)
			{
				NewNode->next=head;
				NewNode->pre=head;
				head=NewNode;
			}
			else
			{
				curr=head;
				for(int i=1;i<index;i++)
				{
					curr=curr->next;
				}
				NewNode->next=curr->next;
					
				curr->next=NewNode;
				NewNode->pre=curr;
				curr->pre=NewNode;
				tail=NewNode;
			}
			
			counter++;
		}
	}
	void display()
	{
		cout<<"List is :";
		Node *temp=head;
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	void display1()
	{
		cout<<"List is :";
		Node *temp=tail;
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
	int num,number,index;
	List obj;
	cout<<"HOW NUMBERS YOU WANT  TO INSERT :"<<endl;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"Enter the index: ";
		cin>>index;
		cout<<"Enter the number :";
		cin>>number;
		cout<<endl;
		obj.insert(index,number);
		
	}
		obj.display();
		obj.display1();
	
}
