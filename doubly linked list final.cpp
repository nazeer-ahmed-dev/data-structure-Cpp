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
	Node *head , *tail;
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
		else
		{
	
			
		}
	}
};
int main()
{
	List obj;
	int number , num;
	cout<<"how many numbers you wnat "<<endl;
	cin>>number;
	
	for(int i=0;i<number;i++)
	{
		cout<<"Enter the number"<<endl;
		cin>>num;
		obj.insert(num);
	}
}
