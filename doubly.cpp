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
		cout<<"LIST IS : ";
		Node *temp=tail;
		while(temp)
		{
			cout<<temp->data;
			temp=temp->previous;
		}
		cout<<endl;

	}
	void deleteNode(int number)
	{
	
		Node *temp= head ,*pre=NULL;
		while(temp && temp->data != number) 
		{
			pre=temp;
			temp=temp->next;
		}
		if(temp)
		{
			if(pre)
			{
				pre->next=temp->next;
				temp->next->previous=pre;
				delete temp;
			}
		}
		display();
	}
	

};
int main()
{
	List obj;
	int n,  number , num;
	cout<<"how many numbers you wnat "<<endl;
	cin>>number;
	
	for(int i=0;i<number;i++)
	{
		cout<<"Enter the number"<<endl;
		cin>>num;
		obj.insert(num);
	}
	obj.display();
	obj.display1();
	cout<<"ENTE THE NUMBER WANT TO DELETE "<<endl;
	cin>>n;
	obj.deleteNode(n);
}
