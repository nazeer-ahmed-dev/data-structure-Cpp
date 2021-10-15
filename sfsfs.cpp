#include<iostream>
using namespace std;
struct Queue
{
	int data=3;
	int front;
	int rear;
	int *pointer;
};
void initilize(Queue *p)
{
	cout<<p->data;
}
int main()
{
	Queue obj;
	initilize(&obj);
}
