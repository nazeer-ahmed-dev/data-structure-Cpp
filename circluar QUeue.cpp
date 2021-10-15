#include<iostream>
using namespace std;
struct Queue
{
	int front;
	int rear;
	int size;
	int maxsize;
	int *Q;
	int couter;
};
void Initalize(Queue *q)
{
	
	q->maxsize=q->size;
	q->front=-1;
	q->rear=-1;
	q->couter=0;
	q->Q=new int[q->maxsize];
	//cin>>q->Q[0];
	//for(int i=0;i<q->size;i++)
	//{
	//	cout<<q->Q[i];
	//}
}
bool isfull(Queue *q)
{
	if((q->rear==q->size-1 && q->front==0) || (q->rear=q->front-1))
	return 1;
	else
	return 0;
}
bool isempty(Queue *q)
{
	if(q->rear==q->size-1 && q->front!=0)
	return 1;
	else
	return 0;
}
void enqueue(Queue *q,int number)
{
	if((q->rear==q->size-1 && q->front==0) || (q->rear==q->front-1))
	{
		cout<<"You can't insert because Queue is full"<<endl;
			
	}
	else
	{
		
		q->rear=(q->rear+1)%q->maxsize;
		q->couter++;
		q->Q[q->rear]=number;
	}
}
void display(Queue *p)
{
	for(int i=p->front;i<p->rear;i++)
	{
		cout<<p->Q[i]<<endl;
	}
}
int main()
{
	Queue obj;
	int number;
	char ch;
	cout<<"Enter size of array"<<endl;
	cin>>obj.size;
	Initalize(&obj);
	block:
	cout<<"Inert   (press 1)"<<endl;
	cout<<"delete  (press 2)"<<endl;
	cout<<"Display (press 3)"<<endl;
	cin>>ch;
	if(ch=='1')
	{
		cout<<"Enter the number ";
		cin>>number;
		enqueue(&obj , number);
		goto block;
	}
	else if (ch=='2')
	{
		
	}
	else if(ch=='3')
	{
		display(&obj);
		goto block;
	}
	else
	{
		cout<<"Wrong input "<<endl;
		goto block;
	}
}
