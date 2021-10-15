#include<iostream>
using namespace std;
class Queue
{
	int maxQueueSize; 
	int count; 
	int queueFront; 
	int queueRear; 
	int *list; 

	public:
	bool isEmptyQueue()
	{
			if(count==0)
				return 1;
			else
				return 0;
			
	}
	bool isFullQueue()
	{
		if(count==maxQueueSize)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	void initializeQueue()
	{
		cout<<"Enter the size of List"<<endl;
		cin>>maxQueueSize;
		list = new int[maxQueueSize];
		queueFront=0;
		queueRear=maxQueueSize-1;
		count=0;	
	}
	int front()
	{
		if(queueFront==-1)
		{
			cout<<"list is empty"<<endl;
		}
		else
		cout<<"Front element is : "<<list[queueFront]<<endl;
	}
	int back()
	{
		cout<<"Last element is : "<<list[queueRear]<<endl;
	}
	void addQueue(int queueElement)
	{
		if(isFullQueue())
		{
			cout<<"List is full"<<endl;
		}
		else
		{
			queueRear = (queueRear + 1) % maxQueueSize; 
			count++;
			list[queueRear]=queueElement;
		}
	}
	void deleteQueue()
	{
		if(isEmptyQueue())
		{
			cout<<"LIst is empty"<<endl;
		}
		else
		{
			count--;
			queueFront = (queueFront + 1) % maxQueueSize;
		}
	}
	
	void printQueue()
	{
		for(int i=queueFront;i<=queueRear;i++)
		{
			cout<<list[i]<<" ";
		}
	}
	void totalvalue()
	{
		cout<<"Total element "<<count+1<<endl;
	}
	
};
int main()
{
	Queue Q1,Q2;
	Q1.initializeQueue();
	Q1.addQueue(15);
	Q1.addQueue(25);
	Q1.addQueue(4);
	Q1.addQueue(12);

	
	
	 Q1.printQueue();
	 
//	Q1.front(); // should display 15
	Q1.deleteQueue();
	Q1.deleteQueue();
	Q1.addQueue(4);
	Q1.addQueue(12);
	
	Q1.printQueue();// should display all the queue element in the order they are added except 15
	Q1.totalvalue();
/*	Q1.addQueue(1000);
	Q1.addQueue(2000);
	
	Q1.printQueue(); // Should display all the members of Q1 in the order they are inserted except 15 as it was deleted earlier
	Q2.printQueue();
	// Should display all the members of Q2 i-e all the members of Q1 except for 1000 and 2000
	Q1.initializeQueue();
	Q1.printQueue();
	//Should display a message "An empty Queue can't be displayed"
	Q1.addQueue(35);

	Q1.front();

	Q1.addQueue(3);

	Q1.printQueue();
	//Should display both 35 and 3
*/
}
