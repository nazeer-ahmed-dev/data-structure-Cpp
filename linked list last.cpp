#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
	int data;
	Node * next;
};
class List
{
 	Node *head;
 	public:
 	List()
 	{
 		head=NULL;
		//curr=NULL;	
	}
 	void insert(int x , int index)
 	{
 		Node * curr;
 		Node * NewNode = new Node;
		 NewNode->data=x;
		 NewNode->next=NULL;
		 if(index==0)
		 {
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
			curr->next=curr;
			
		 }
		 	
	}
	void display()
	{
		cout<<"List :";
		Node * temp=head;
		while(temp)
		{
			cout<<temp->data;
			temp=temp->next;
		}
		cout<<endl;
	}
};
int main()
{
	List  obj;
	int num, index,number;
	cout<<"how many number you want to insert :";
	cin>>number;
	for(int i=0;i<number;i++)
	{
		cout<<"Enter the number:";
		cin>>num;
		cout<<"Enter the index:";
		cin>>index;
		obj.insert(num,index);
		obj.display();
	}
}
