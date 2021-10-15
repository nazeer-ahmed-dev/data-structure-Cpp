#include<iostream>
using namespace std;
struct Queue
{
	int size;
	int front=0;
	int Rear;	
	int *QueueArray;
};
class List
{
	int *Array;
	int rear ,front;
	int num;
	public:
	void addQueue(int value)
	{
		Array=new int [value];
		rear=-1;
		do
		{
			rear++;
			cout<<"enter the value";
			cin>>num;
			Array[rear]=num;
			
		}
		while(rear!=value-1);
	}
	
	void deleteQueue()
	{
		string y1;
		char y;
		block:
		cout<<"Enter y for delete number :";
		cin>>y;
		if(y=='y'||y=='Y')
		{
			front++;
		}
		cout<<"Want to delete again the write yes: ";
		cin>>y1;
		if(y1=="yes"|| y1=="Yes"|| y1=="YES")
		{
			goto block;
		}
	}
	void display()
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<Array[i];
		}
	}
};

int main()
{
	List obj;
	int size;
	cout<<"Enter the size of Array :";
	cin>>size;
	//object.QueueArray = new int[object.size];
	obj.addQueue(size);
	obj.deleteQueue();
	obj.display();
}
