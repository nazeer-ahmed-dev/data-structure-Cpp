#include<iostream>
using namespace std;
struct BST
{
		int data;
		BST* left_link;
		BST* right_link;		
};
class List
{
	public:
	BST *root,*copyroot;
	int count;
	
	List()
	{
		root=NULL;
		count=0;
		
	}
	bool Isempty()
	{
		if(root==NULL)
			return 1;
		else
			return 0;
	}
	void Insert(int element)
	{
		BST *current;      //pointer to traversa the node
		BST *Trialcurrent; //pointer behind current
		BST *newNode;	  //pointer to the create NOde
		
		newNode=new BST;
		newNode->data=element;
		newNode->left_link=NULL;
		newNode->right_link=NULL;
		
		if(root==NULL)
		{
			root = newNode;
			count++;
		}
		else
		{
			current=root;
			while(current)
			{
				Trialcurrent=current;
				
				if(current->data==element)
				{
					cout<<" The insert Item is already in the list-";
					cout<<" dupplicate are not allowed "
						<<"insert iteml"<<endl;
				}
				else if( current->data > element)
				{
					current=current->left_link;
				}
				else
				{
					current=current->right_link;
				}
				
			}
			if(Trialcurrent->data > element)
			{
				Trialcurrent->left_link= newNode;
				count++;
			}
			else
			{
				Trialcurrent->right_link=newNode;
				count++;
			}
		}
	}
	bool Search(int value)
	{	bool flag=false;
		BST * curr;
		if(root==NULL)
		{
			cout<<"There is no element is tree"<<endl;
		}
		else
		{
			curr=root;
			while(curr!=NULL & !flag)
			{
					
				if(curr->data==value)
				{
					cout<<"done";
					flag=true;	
				}
				else if(curr->data > value)
				{
					curr=curr->left_link;
				}
				else
				{
					curr=curr->right_link;
				}
			}
			
		}
		return flag;
	}
	void InorderTraversal(BST *&p)
	{
		if(p)
		{
			InorderTraversal(p->left_link);
			cout<<p->data<<" ";
			InorderTraversal(p->right_link);
		}
	}
	void PreorderTraversal(BST *&p)
	{
		if(p!=NULL)
		{
			cout<<p->data<<" ";
			PreorderTraversal(p->left_link);
			PreorderTraversal(p->right_link);
		}
	}
	void PostorderTraversal(BST *&p)
	{
		if(p!=NULL)
		{
			PostorderTraversal(p->left_link);
			PostorderTraversal(p->right_link);
			cout<<p->data<<" ";
		}
			
	}
	void copy(BST *p , BST *&q )
	{
		if(p==NULL)
		{
			q=NULL;
		}
		else
		{
			q = new BST;
			q->data=p->data;
			copy(p->left_link,q->left_link);
			copy(p->right_link,q->right_link);
		}
	}
	int treeHight()
	{
		
	}
	int treeNodecount()
	{
		cout<<"TOTAL NODES "<<count<<endl;
	}
	int treeLeavescount()
	{
		
	}
	void deleteNode(BST *p)
	{
		BST *curr1;
		BST *Tcurr1;
		BST *temp;
		if(p==NULL)
		{
			cout<<"EROR! There is not element in BST "<<endl;
		}
		else if(p->left_link==NULL && p->right_link==NULL)
		{
			temp=p;
			p=NULL;
			delete temp;
		}
		else if(p->left_link==NULL)
		{
			temp=p;
			p=temp->right_link;
			delete temp;
		}
		else if (p->right_link==NULL)
		{
			temp=p;
			p=temp->left_link;
			delete temp;
		}
		else
		{
			curr1=p->left_link;
			Tcurr1=NULL;
			while(curr1->right_link!=NULL)
			{
				Tcurr1=curr1;
				curr1=curr1->right_link;
				
			}
			p->data=curr1->data;
			if(Tcurr1==NULL)
			{
				p->left_link=curr1->left_link;
				
			}
			else
			{
				Tcurr1->right_link=curr1->left_link;
			}
		}
	}
	void deleleNoes(int value)
	{
		BST *curent;
		BST *Tcurent;
		bool flag=false;
		if(root==NULL)
		{
			cout<<"have not element "<<endl;	
		}	
		else
		{
			curent=root;
			Tcurent=root;
			while(curent!=NULL && !flag)
			{
				if(curent->data==value)
				{
					flag=true;
				}
				else 
				{
					Tcurent=curent;
					if(curent->data > value)
					{
						curent=curent->left_link;	
					}
					else
					{
						curent=curent->right_link;
					}
						
				}
			}
			if(curent==NULL)
			{	
					cout<<"cant delte"<<endl;
			}
			else if(flag)
			{
				if(curent==root)
				{
					deleteNode(root);
				}
				else if(Tcurent->data > value)
				{
					deleteNode(Tcurent->left_link);
				}
				else
				{
					deleteNode(Tcurent->right_link);
				}
			}
		}
	}
	void destroyTree(BST *&p)
	{
		if(p)
		{
			destroyTree(p->left_link);
			destroyTree(p->right_link);
			delete p;
			p=NULL;	
		}
			
	}
};
int main()
{
	List object;
	BST obj;
	int number;
	object.Insert(60);
	object.Insert(50);
	object.Insert(30);
	object.Insert(53);
	object.Insert(57);
	object.Insert(35);
	object.Insert(32);
	object.Insert(40);
	object.Insert(48);
	object.Insert(45);
	object.Insert(70);
	object.Insert(80);
	object.Insert(75);
	object.Insert(77);
	object.treeNodecount();
	cout<<"INORDER-LIST   : ";
	object.InorderTraversal(object.root);
	cout<<endl;
	cout<<"PREORDER-LIST  : ";
	object.PreorderTraversal(object.root);
	cout<<endl;
	cout<<"POSTORDER-LIST : ";
//	object.destroyTree(object.root);
	object.PostorderTraversal(object.root);
//	cout<<"Enter the element want to search ";
//	cin>>number;
//	object.Search(object.root,number);
//	object.destroyTree(object.root);
	//object.copy(object.root,object.copyroot);
	//cout<<"hello";
	//object.InorderTraversal(object.copyroot);
	cout<<endl;
	//cout<<"Enter the element want to search "<<endl;
//	int num;
//	cin>>num;
//	object.Search(num);
//	object.deleteNode(object.root);
	cout<<"Enter the numbe want to delete "<<endl;
	int num;
	cin>>num;
	object.deleleNoes(num);
		cout<<"INORDER-LIST   : ";
	object.InorderTraversal(object.root);
	cout<<endl;
}


