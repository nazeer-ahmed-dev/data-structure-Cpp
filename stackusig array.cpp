// stack using linked list
#include<iostream>
using namespace std;
struct stack
{
	int data;
	stack *next;
};
struct List
{

	stack *Head,*curr,*tail;
//	public:
	List()
	{
		Head=NULL;
	}
	void push(int x)
	{
		stack *Node = new stack;
		Node->data=x;
		Node->next=NULL;
		if(Head==NULL)
		{
			Head=Node;
			tail=Node;
		}
		else
		{
			curr=Head;
			while(curr->next)
			{
				curr=curr->next;
			}
			Node->next=curr->next;
			curr->next=Node;
			tail=Node;
		}
	}
	 void display(stack *temp)
	{
		if(temp!=NULL)
	
		{
			display(temp->next);
			cout<<temp->data<<" ";	
			
			
		}
		//cout<<endl;
		
		
	}
	void pop()
	{

		stack *temp2=Head,*pre;
		if(temp2>next==NULL)
		{
			cout<<"list is empty"<<endl;
		}
		else
		{
			while(temp2->next)
			{
				pre=temp2;
				temp2=temp2->next;
		
			}
			delete pre->next;
			pre->next=NULL;
		}
	}
	void display1(stack *temp5)
	{
			if(temp5!=NULL)
	
		{
			display(temp5->next);
			cout<<temp5->data<<" ";	
			
			
		}
	}
	void peek()
	{
		
	}
};
int main()
{
	int num,index;
	char ch;
	List obj;
	block :
	cout<<"INSERT  (PRESS 1)"<<endl;
	cout<<"DELETE  (PRESS 2)"<<endl;
	cout<<"PEEK    (PRESS 3)"<<endl;
	cin>>ch;
	if(ch=='1')
	{
		cout<<"Enter the element "<<endl;
		cin>>num;
		obj.push(num);
		cout<<endl;
		obj.display(obj.Head);
		cout<<endl;
		
		goto block;
	}
	else if(ch=='2')
	{
		obj.pop();
	cout<<endl;
		obj.display1(obj.Head);
		cout<<endl;
		goto block;
	}
	else if(ch=='3')
	{
		cout<<"Enter the index"<<endl;
		obj.peek();
		goto block;
	}
	else
	{
		cout<<"Wrong input "<<endl;
		goto block;
	}
	
}
