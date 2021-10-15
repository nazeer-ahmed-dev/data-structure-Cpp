#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *left;
	Node *right;
};
class List
{
	Node *head , *temp;
	public:
	List()
	{
		head=NULL;
	}
	void insert(int x)
	{
		Node *NewNode = new Node;
		NewNode->data=x;
		NewNode->left=NULL;
		NewNode->right=NULL;
		if(head==NULL)
		{
			head=NewNode;
			temp=NewNode;
		}
		else
		{
			if( x < temp->data)
			{
				temp->right=NewNode;
				temp=temp->right;
			}
			else
			{
				temp->left=NewNode;	
				temp=temp->left;
			}
			
		}
	}
};
int main()
{
	List obj;
	obj.insert(12);
	obj.insert(22);
	obj.insert(2);
	obj.insert(54);
	obj.insert(52);
	obj.insert(51);
	obj.insert(55);
	
}
