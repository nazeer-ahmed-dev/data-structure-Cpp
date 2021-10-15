#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
class List
{
	Node *head;
	int count;
	public:
		List()
		{
			head = NULL;
			//count = 0;
		}
		void printList()
		{
			Node *temp = head;
			for(int i = 0; i<count; i++)
			{
				cout<<temp->data<<endl;
				temp = temp->next;
				
			}
			
			
		}
		
		void insert(int FData, int index)
		{
				Node *curr;
				Node *nN = new Node;
				nN->data = FData;
				nN->next=NULL;
				if(index == 0)
				{
					head = nN;
					
				}
				else
				{
					curr = head;
					for(int i = 1;i<index; i++)
					{
						curr = curr->next;
					}
					curr->next = nN;
				//	nN->next = curr->next;
				}
			//	count++;
			//	return true;
}
};



int main()
{
	List obj; 
	obj.insert(15,0);
	obj.insert(35,1);
	obj.insert(205,2);
	obj.printList();
	
	
	return 0;
}
