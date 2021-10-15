#include <iostream>
using namespace  std;
template <class Type>
struct Node
{
	Type data;
	Node <Type>*next;
};
template <class Type>
class queueType
{
public:
	Node <Type>*head;
	queueType()
	{
		head=0;
	}
	Node <Type>*cur;
	
	void addQueue(const Type& queueElement)
	{
		Node <Type>*nN=new Node<Type>;
		nN->data=queueElement;
		if(!head)
		{
			nN->next=head;
			head=nN;
			cur=head;
		}
		else
		{
			nN->next=cur->next;
			cur->next=nN;
			cur=nN;
		}
	}
	void deleteQueue()
	{
		Node <Type>*temp=head;
		head=head->next;
		delete temp;
	}
	bool isEmptyQueue()
	{
		return (head);
	}
//bool isFullQueue();
	void initializeQueue()
	{
		Node <Type>*cur;
		while(head)
		{
			cur=head;
			head=head->next;
			delete cur;
		}
	}
	Type front()
	{
		return head->data;
	}
	Type back()
	{
		Node <Type>*cur=head;
		Node <Type>*prev;
		while(cur)
		{
			prev=cur;
			cur=cur->next;
		}
		return prev->data;
	}
	queueType(const queueType<Type>& otherQueue)
	{
		if(this!=&otherQueue)
		{
			if(otherQueue.head)
			{
				head=new Node<Type>;
				head->data=otherQueue.head->data;
				head->next=0;
				Node <Type> *cur1=otherQueue.head->next;
				Node <Type> *cur2=head;
				while(cur1)
				{
					Node <Type> *nN=new Node<Type>;
					nN->data=cur1->data;
					nN->next=cur1->next;
					cur2->next=nN;
					cur2=nN;
					cur1=cur1->next;
				}
			}
		}
	}
	void printQueue()
	{
		Node <Type> *cur=head;
		while(cur)
		{
			cout<<cur->data<<" ";
			cur=cur->next;
		}
		cout<<endl;
	}
// To create a Queue object that copies another queue
};
int main()
{
queueType <int>Q1;
Q1.addQueue(15);
Q1.addQueue(25);
Q1.addQueue(4);
Q1.addQueue(12);
Q1.addQueue(123);
Q1.addQueue(75);
Q1.addQueue(85);
Q1.addQueue(55);
	cout<<Q1.front()<<endl; // should display 15
Q1.deleteQueue();
Q1.printQueue();// should display all the queue element in the order they are added except 15
	queueType  <int>Q2(Q1);
	Q1.addQueue(1000);
	Q1.addQueue(2000);
	Q1.printQueue(); // Should display all the members of Q1 in the order they are inserted except 15 as it was deleted earlier
	Q2.printQueue();
	// Should display all the members of Q2 i-e all the members of Q1 except for 1000 and 2000
//	Q1.initializeQueue();
	Q1.printQueue();
	//Should display a message "An empty Queue can't be displayed"
	Q1.addQueue(35);
	Q1.front();
	Q1.addQueue(3);
	Q1.printQueue();
//	Q1.~queueType();
	Q1.printQueue();
}

