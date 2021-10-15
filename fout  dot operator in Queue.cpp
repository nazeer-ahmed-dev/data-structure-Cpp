#include<iostream>
using namespace std;
class Queue
{
	private:
	int size , rear , front , *Q;
	public:
	Queue(int x)
	{
		size=x;
		front=rear=-1;
		Q = new int[x];
	}
	void eQueue(int x);
	void dQueue();
	void display();
};
void Queue::eQueue(int x)
{
	if(rear==size-1)
	{
		cout<<"List is full "<<endl;
	}	
	else
	{
		rear++;
		Q[rear]=x;
	}
}
void Queue::display()
{
	for(int i=front+1;i<=rear;i++)
	{
		cout<<Q[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	
	int size,number;
	cout<<"Enter the size of Array : "<<endl;
	cin>>size;
	Queue obj(size);
	block:
	cout<<"Enter the number :"<<endl;
	cin>>number;
	obj.eQueue(number);
	cout<<"Want to insert again press Y or y :";
	char ch1;
	cin>>ch1;
	if(ch1=='y' || ch1=='Y')
	goto block;
	obj.display();
	
	
}

