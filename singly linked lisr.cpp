#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
	int data;
	Node *link;	
};
class List
{
	Node *current;
	int counter;
	public:
		Node *head;
	List()
	{
		head=NULL;
		counter=0;
	}
	void Insert(int value , int index)
	{
		Node * newNode= new Node;
		newNode->data=value;
		newNode->link=NULL;
		if(index==0)
		{
			newNode->link=head;
			head=newNode;
		}
		else
		{
			current=head;
			for(int i=1;i<index;i++)
			{
				current=current->link;
			}
			newNode->link=current->link;
			current->link=newNode;
			//current=newNode;
		}
		counter++;
	}
	void display()
	{
		cout<<"List is :";
		Node *temp=head;
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->link;
		}
		cout<<endl;
	}
	void evenorodd()
	{
		
		int i=0,array[counter];
		Node *temp=head;
		
		while(temp)
		{
			if(temp->data %2==0)
			{
				array[i]=temp->data;
				i++;
			}
			temp=temp->link;
		}
		cout<<"EVEN : ";
		for(int k=0;k<i;k++)
		{
			cout<<array[k]<<" ";
		}
	
		
	}
	void odd()
	{
		Node *temp1=head;
		int j=0,array1[counter];
			while(temp1)
		{
			if(temp1->data %2!=0)
			{
				array1[j]=temp1->data;
				j++;
			}
			temp1=temp1->link;
		}
		cout<<"ODD : ";
		for(int k=0;k<j;k++)
		{
			cout<<array1[k]<<" ";
		}
		
	}
	void sumofallement()
	{
		Node * temp=head;
		int sum=0;
		while(temp)
		{
			sum+=temp->data;
			temp=temp->link;
		}
		cout<<"SUM : "<<sum<<endl;
	}
	void countingNode()
	{
		cout<<"TOTAL NODE :"<< counter<<endl;
	}
	void reverseDisplay(Node *temp)
	{
		
		if(temp)
		{
			reverseDisplay(temp->link);
			cout<<temp->data<<" ";
		}
	}
	void searching(int serch)
	{
		Node *temp2=head;
		for(int i=0;i<counter;i++)
		{
			if(temp2->data==serch)
			{
				cout<<"INDEX IS : "<<i;
				temp2=temp2->link;
			}
			else
			{
				temp2=temp2->link;
			}
		}
	}
	void Max(Node *temp)
	{
		cout<<endl;
		cout<<"Maximum :";
		int max=(-32768);
		while(temp)
		{
			if(temp->data>max)
			{
				max=temp->data;
				temp=temp->link;
			}	
		}
		cout<<max;
	}
	void middleelement(Node *temp)
	{
		for(int i=0;i<counter/2;i++)
		{
			temp=temp->link;
		}
		cout<<"Middle number: "<<temp->data;
	}
	void rotating()
	{
		int number;
		cout<<"Enter the nmumber"<<endl;
		cin>>number;
		Node * Temp=head,*pre=NULL,*Temp1=head;
		while(Temp)
		{
			Temp=Temp->link;
		}
		Temp->link=head;
		while(Temp1)
		{
			if(number==Temp1->data)
			{
				head=pre->link;
			}
			pre=Temp1;
			Temp1=Temp1->link;
		}
		
		display();
	}
};

int main()
{
	List obj;
	int x,y,index,value,number,serchnumber;
	cout<<"HOW MANY NODE YOU WANT TO CREATE"<<endl;
	cin>>number;
	for(int i=0;i<number;i++)
	{
		cout<<"Enter the index ";
		cin>>index;
		cout<<"Enter the value ";
		cin>>value;
		obj.Insert(value,index);			
	}
	obj.display();
//	cout<<"Reverse list :";
//	obj.reverseDisplay(obj.head);
//	cout<<endl;
	obj.countingNode();
	obj.sumofallement();
	obj.evenorodd();
	obj.odd();
	cout<<endl;
	cout<<"Enter the number which u want to search "<<endl;
	cin>>serchnumber;
	obj.searching(serchnumber);
	obj.Max(obj.head);
	cout<<endl;
	obj.middleelement(obj.head);
	obj.rotating();
}

  
