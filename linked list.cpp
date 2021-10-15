#include<iostream>
using namespace std;
struct LinkedList
	{
	int data;
	LinkedList *next;
};
class list
{
	LinkedList *head ,*curr;
	int counter;
	public:
	list ()
	{
		counter=0;
		head=NULL;
	}
	void insert(int element)
	{
		LinkedList *NewNode = new LinkedList;
		NewNode->data=element;
		NewNode->next=NULL;
		if(head==NULL)
		{
			head=NewNode;
			counter++;
		}
		else
		{
			curr=head;
			while(curr->next)
			{
				curr=curr->next;	
			}
			curr->next=NewNode;
			counter++;
		}
	}
	void display()
	{
		LinkedList *temp=head;
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
/*	bool search(int number)
	{
		bool flag=false;
		LinkedList *temp=head;
		while(temp && !flag)
		{
			if(temp->data==number)
			{
				flag=true;
			}
			temp=temp->next;
		}
		if(flag==true)
		{
			cout<<"found succefully"<<endl;
		}
		else
		{
			cout<<"not available "<<endl;
		}
	}
	void countelement(int num)
	{
		cout<<"TOTAL ELEMENT : "<<counter;
	}
	/*void deleteAnyNode(int num)
	{
		LinkedList *temp=head,*pre;
		if(temp->next==NULL)
		{
			delete head;
			head=NULL;
		}
		else
		{
			while(temp && num!=temp->data)
			{
				pre=temp;
				temp=temp->next;
				
			}
			if(temp)
			{
				if(pre)
				{
					pre->next=temp->next;
					delete temp;
				}
			}
		}
	}*/
	void destroy()
	{
		LinkedList *temp=head;
		while(temp)
		{
			temp=temp->next->next;
			delete head;
			head=temp;
		}
	}
};
int main()
{
	list object;
	object.insert(2);
	object.insert(4);
	object.insert(66);
	object.insert(45);
	object.display();
//	cout<<endl;
//	object.search(6);
//	object.countelement();
	cout<<endl;
	///object.deleteAnyNode(66);
	object.display();
	object.destroy();
	object.display();
}
