#include<iostream>
using namespace std;
struct Queue
{
    int c;
    int size;
    int rear;
    int front;
    int *Q;
};	
void initialize(Queue *p , int size)
{
    p->rear=p->front=-1;
	 p->Q= new int[size];
	 p->c=0;
}
void enQueue(Queue *q , int x)
{
	//int counter;
	if(q->rear==q->size-1)
	{
		q->rear=(q->rear+1)%q->size;
		cout<<"arrray is full: "<<endl;
	}
	else
	{
		q->c++;
		q->rear++;
		q->Q[q->rear]=x;
		//counter++;
	}
}
void display(Queue *s ,int size)
{
	cout<<"List is :";
	for(int i=s->front+1;i<=s->rear;i++)
	{
		cout<<s->Q[i]<<" ";
	}
	cout<<endl;
}
void dQueue(Queue *p )
{
	if(p->rear==p->front)
	{
		cout<<"List is empty :"<<endl;
		
	}
	else
	{
		p->c--;
		p->front=(p->front+1)%p->size;
	}
	
}
void display1(Queue *s ,int size)
{
	cout<<"List is :";
	for(int i=s->front+1;i<=s->rear;i++)
	{
		cout<<s->Q[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int num;
	char ch1;
	Queue obj;
	cout<<"ENTER THE SIZE OF ARRAY :";
	cin>>obj.size;
	cout<<endl;
  	initialize(&obj ,obj.size);
  	block:
	cout<<"INSERT  (PREES 1)"<<endl;
	cout<<"DELETE  (PREES 2)"<<endl;
	cout<<"DISPLAY (PREES 3)"<<endl;
	cin>>ch1;
	if(ch1=='1')
	{
	cout<<"ENTER THE VALUE :";
  	cin>>num;
  	cout<<endl;
  	enQueue(&obj , num);
  	goto block;
	}
	else if(ch1=='2')
	{
		dQueue(&obj);
		goto block;	
	}
	else if(ch1=='3')
	{
		display(&obj,obj.size);
		goto block;
	}
	else
	{
		cout<<"YOU ENTERED WRONG NUMBER PLZ ENTER AGAIN :"<<endl;
		goto block;
	}

  
}
