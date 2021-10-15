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
			count = 0;
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
		
		
		bool insert(int FData, int index)
		{
			Node *curr;
			if(index>count||index<0)
			{
				cout<<"Index exceeds, max index should be "<<count<<endl;
				return false;
			}
			else
			{
				Node *nN = new Node;
				nN->data = FData;
				if(index == 0)
				{
					nN->next = head;
					head = nN;
					
				}
				else
				{
					curr = head;
					for(int i = 1;i<index; i++)
					{
						curr = curr->next;
					}
					nN->next = curr->next;
					curr->next = nN;
				}
				count++;
				return true;
			}
			
		}
};



int main()
{
	List obj; 
	obj.insert(15,0);
	obj.insert(35,1);
	obj.insert(25,3);
	obj.insert(55,0);
	obj.insert(305,3);
	obj.insert(205,2);
	obj.insert(5,4);
	obj.insert(-5,-2);
	obj.printList();
	
	
	return 0;
}
