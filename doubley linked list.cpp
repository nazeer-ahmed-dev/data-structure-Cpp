#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
	int data;
	Node* pre;
	Node* next;
};
class List
{
	int counter;
	Node *head ,*tail,*current;
	public:
	List()
	{
		head=NULL;
		tail=NULL;
		counter=0;
	}
	void Insert(int num , int index)
	{
		Node * temp=new Node;
		temp->data=num;
		temp->pre=NULL;
		temp->next=NULL;
		if(index<0 && index>counter)
		{
			cout<<"YOU ENTERED WORNG INDEX !"<<endl;
		}
		else
		{
			if(index==0)
			{
				head=temp;
				tail=temp;
			}
			else
			{
				current=head;
				for(int i=0;i<index;i++)
				{
					current=current->next;
				}
				current=temp;
				temp->pre=tail;
				tail=temp;
			}
			counter++;
		}
	}
	void display()
	{
		Node *temp=head;
		cout<<"List is : ";
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	void displayrev()
	{
		Node *temp=tail;
		cout<<"List is : ";
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
	int num, index,numb;
	List object;
	cout<<"HOw many number you want insert :";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<endl;
		cout<<"INSERT THE VALUE "<<i<<" : ";
		cin>>numb;
		cout<<"INSERT THE INDEX "<<i<<" : ";
		cin>>index;
		object.Insert(numb,index);
		cout<<endl;
		object.display();
		cout<<endl;
		object.displayrev();
	}
}
