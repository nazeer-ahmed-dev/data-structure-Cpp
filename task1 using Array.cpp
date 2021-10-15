#include <iostream>
using namespace std;
class queueType
{
	int QFront,QRear,*Array,count,maxQueSize;
public:
	queueType(int queueSize)
	{
			QFront=0;
			count=0;
		if(queueSize<0)
		{
			cout<<"Size can not be negative by default size is 100"<<endl;
			maxQueSize=100;
			Array=new int[maxQueSize];
		}
		else
		{
			maxQueSize=queueSize;
			Array=new int[maxQueSize];	
		}
		QRear=maxQueSize-1;
	}
bool isEmptyQueue()
{
	return (count==0);
}
bool isFullQueue()
{
	return (count==maxQueSize);
}
void initializeQueue()
{
	QFront=0;
	QRear=maxQueSize-1;
	count=0;
}
int front()
{
	return Array[QFront];	
}
int back()
{
	return Array[QRear];
}
void addQueue(int queueElement)
{
	if(!isFullQueue())
	{
	QRear=(QRear+1)%maxQueSize;
	Array[QRear]=queueElement;
	
	count++;
	}
	else
	{
		cout<<"Queue is Full"<<endl;
	}
}
void deleteQueue() // Function with default parameters
{
	if(!isEmptyQueue())
	{
	QFront=(QFront+1)%maxQueSize;
	count--;
	}
	else
	{
		cout<<"Can not delete from Empty list"<<endl;
	}
}

queueType(queueType& otherQueue) // To create a Queue object that copies another queue
{
	//delete []Array;
	maxQueSize=otherQueue.maxQueSize;
	QFront=otherQueue.QFront;
	QRear=otherQueue.QRear;
	Array=new int[otherQueue.maxQueSize];
	for(int i=QFront;i<=QRear; i++)
	{
		Array[i]=otherQueue.Array[i];
	}
	
}
void printQueue()
{
	if(!isEmptyQueue())
	{
	for(int i=QFront; i!=(QRear+1)%maxQueSize; i=(i+1)%maxQueSize)
	{
		cout<<Array[i]<<" ";
	}
	}
	else
	cout<<"List is Empty"<<endl;
	cout<<endl;
}

~queueType()
{
	delete []Array;
}
};
int main()
{
	int size;
//	cout<<"Enter Size of Queue : ";
	//cin>>size;
queueType Q1(50);
Q1.addQueue(15);
Q1.addQueue(25);
Q1.addQueue(4);
Q1.addQueue(12);
Q1.addQueue(123);
Q1.addQueue(75);
Q1.addQueue(85);
Q1.addQueue(55);
//	cout<<Q1.front()<<endl; // should display 15
Q1.deleteQueue();
Q1.deleteQueue();
Q1.addQueue(55);
Q1.addQueue(55);
Q1.printQueue();// should display all the queue element in the order they are added except 15
//	queueType  Q2(Q1);
//	Q1.addQueue(1000);
//	Q1.addQueue(2000);
//	Q1.printQueue(); // Should display all the members of Q1 in the order they are inserted except 15 as it was deleted earlier
//	Q2.printQueue();
	// Should display all the members of Q2 i-e all the members of Q1 except for 1000 and 2000
	Q1.initializeQueue();
//	Q1.printQueue();
	//Should display a message "An empty Queue can't be displayed"
//	Q1.addQueue(35);
//	Q1.front();
//	Q1.addQueue(3);
//	Q1.printQueue();
//	Q1.~queueType();
//	Q1.printQueue();
	//Should display both 35 and 3

}

