#include<iostream>
using namespace std;
struct array
{
	int data;
	int *ponter;
	int count;
};
struct Node
{
	int sum;
	Node *next;
	Node *pre;
};
void comprees(string name ,int num)
{
	char array[num];
	for(int i=0;i<name.length();i++)
	{
		array[i]=name[i];
	}
	for(int i=0;i<num;i++)
	{
		cout<<array[i]<<" ";
	}
}
int main()
{
	string name;
	cout<<"Enter the Message"<<endl;
	cin>>name;
	comprees(name,name.length());
}
