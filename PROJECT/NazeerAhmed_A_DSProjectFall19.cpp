#include<iostream>
#include<iomanip>
using namespace std;
struct student_record
{
	string student_name;
	int age;
	int id;
	student_record *left_next;
	student_record *right_next;
};
class List1
{
	public:
		student_record *root1,*current1,*trail_curr;
	List1()
	{
		root1=NULL;	
	}	
	void student_recode(string name, int id1,int age)
	{
		student_record *NewNode1= new student_record;
		NewNode1->student_name=name;
		NewNode1->id=id1;
		NewNode1->age=age;
		NewNode1->left_next=NULL;
		NewNode1->right_next=NULL;
		if(root1==NULL)
		{
			root1=NewNode1;
		}
		else
		{
			current1 = root1;
			while(current1)
			{
				trail_curr=current1;
				if(current1->id==id1)
				{
				cout<<" The insert Item is already in the list-";
				cout<<" dupplicate are not allowed "
				<<"insert iteml"<<endl;
				return ;
				}
				else if(current1->id > id1)
				{
					current1=current1->left_next;
				}
				else
				{
					current1=current1->right_next;
				}
			}
			if(trail_curr->id > id1)
			{
				trail_curr->left_next=NewNode1;
				
			}
			else
			{
				trail_curr->right_next=NewNode1;
			}
		}
	}
	bool srchbyid(int s_id)
		{
			bool flag=false;
			student_record * curr;
			if(root1==NULL)
			{
				cout<<"NOt found"<<endl;
			}
			else
			{
				curr=root1;
				while(curr!=NULL && !flag)
				{				
					if(curr->id==s_id)
					{
						flag=true;
						if(flag)
						cout<<"NAME : "<<curr->student_name<<" "<<endl;
						cout<<"AGE  : "<<curr->age<<" "<<endl;
				
					}
					else if(curr->id > s_id)
					{
						curr=curr->left_next;
					}
					else
					{
						curr=curr->right_next;
					}
				}
			}
		
		}
	void InorderTraversal(student_record *&q)
	{

		if(q)
		{
			InorderTraversal(q->left_next);
			cout<<"---------------------------"<<endl;
			cout<<" > NAME  : "<<q->student_name<<endl;
			cout<<" > ID    : "<<q->id<<endl;
			cout<<" > AGE   : "<<q->age<<endl;
			cout<<"--------------------------"<<endl;
			InorderTraversal(q->right_next);
		}
	
	}
	void deleteFromNode(student_record *p)
	{
		student_record *current;
		student_record *trailcurrent;
		student_record *temp;
		
		if(p==NULL)
		{
			cout<<"ERROR : THE NODE TO BE DELETED IN NULL. "<<endl;
		}
		else if(p->left_next==NULL && p->right_next==NULL)
		{
			temp=p;
			p=temp->right_next;
			delete temp;
		}
		else if(p->left_next==NULL)
		{
			temp=p;
			p=temp->left_next;
			delete temp;
		}
		else if(p->right_next==NULL)
		{
			temp=p;
			p=temp->right_next;
			delete temp;
		}
		else
		{
			current=p->left_next;
			trailcurrent=NULL;
			while(current->right_next!=NULL)
			{
				trailcurrent=current;
				current=current->right_next;
			}
			p->id=current->id;
			if(trailcurrent==NULL)
			{
				p->left_next=current->left_next;
			}
			else
			{
				trailcurrent->right_next=current->left_next;
			}
			delete current;
		}
		
	}
	void deleteNode(int id2)
	{
		student_record *curr;
		student_record *t_curr;
		bool found =false;
		
		if(root1==NULL)
		{
			cout<<"CANNOT DELETE FORM THE EMPTY LIST "<<endl;
		}
		else
		{
			curr=root1;
			t_curr=root1;
			
			while(curr!=NULL && !found)
			{
				if(curr->id==id2)
				{
					found = true;		
				}	
				else
				{
					t_curr=curr;
					if(curr->id > id2)
					{
						curr=curr->left_next;
					}
					else
					{
						curr=curr->right_next;
					}
				}
				if(curr==NULL)
				{
					cout<<"The delete item is not in the tree "<<endl;
				}
				else if(found)
				{
					if(curr==root1)
					{
						deleteFromNode(root1);
					}
					else if(t_curr->id >id2)
					{
						deleteFromNode(t_curr->left_next);
					}
					else
					{
						deleteFromNode(t_curr->right_next);
					}
				}
			}	
		}
	}
	void destroyTree(student_record *&p)
	{
		if(p)
		{
			destroyTree(p->left_next);
			destroyTree(p->right_next);
			delete p;
			p=NULL;	
		}
			
	}
};
struct School
{
	string Room_name;
	School *Left_link;
	School *Right_link;
	List1 obj;
};
class List
{
	public:
		School *root;
		int count_Room;
		List()
		{
			root=NULL;
		}
		void Room_name(string Room_Name)
		{
			
			School *current;
			School *trail_current;
			School *NewNode = new School;
			NewNode->Room_name=Room_Name;
			NewNode->Left_link=NULL;
			NewNode->Right_link=NULL;
			if(root==NULL)
			{
				root=NewNode;
			}
			else
			{
				current=root;
				while(current)
				{
					trail_current=current;
					if(current->Room_name==Room_Name)
					{
						cout<<" The insert Item is already in the list-";
						cout<<" dupplicate are not allowed "
						<<"insert iteml"<<endl;
						return ;
					}
					else if(current->Room_name > Room_Name)
					{
						current=current->Left_link;
					}
					else
					{
						current=current->Right_link;
					}
				}
				if(trail_current->Room_name>Room_Name)
				{
					trail_current->Left_link=NewNode;
				}
				else
				{
					trail_current->Right_link=NewNode;
				}
			}
		}
	
		bool Search(string  clas_name)
		{
			bool flag=false;
			string s_name;
			int s_age,s_id;
			School * curr;
			if(root==NULL)
			{
				cout<<"There is no element is tree"<<endl;
			}
			else
			{
				curr=root;
				while(curr!=NULL & !flag)
				{				
					if(curr->Room_name==clas_name)
					{
						flag=true;
						if(flag)
						{
							cout<<"ENTER THE STUDENT NAME       : ";
							cin>>s_name;
							cout<<"ENTER THE ID OF THE STUDENT  : ";
							cin>>s_id;
							cout<<"ENTER THE AGE OF THE STUDENT : ";
							cin>>s_age;
							
							curr->obj.student_recode(s_name,s_id,s_age);
						}
				
					}
					else if(curr->Room_name > clas_name)
					{
						curr=curr->Left_link;
					}
					else
					{
						curr=curr->Right_link;
					}
				}
			}
		
		}
		bool srchbyclassname(string clsname)
		{
			bool flag=false;
			School * curr1;
			if(root==NULL)
			{
				cout<<"There is no element is tree"<<endl;
			}
			else
			{
				curr1=root;
				while(curr1!=NULL && !flag)
				{				
					if(curr1->Room_name==clsname)
					{
						flag=true;
						if(flag)
						{
							cout<<"> "<<clsname<<endl;
							curr1->obj.InorderTraversal(curr1->obj.root1);
						}
				
					}
					else if(curr1->Room_name > clsname)
					{
						curr1=curr1->Left_link;
					}
					else
					{
						curr1=curr1->Right_link;
					}
				}
			}
			
		}
		void InorderTraversal(School *&p)
		{
			if(p)
			{
				InorderTraversal(p->Left_link);
				cout<<p->Room_name<<" ";
				cout<<endl;
				p->obj.InorderTraversal(p->obj.root1);
				cout<<endl;
				InorderTraversal(p->Right_link);
			}
			
		}
		void srchbyid(int srch_id,string name1)
		{
			bool flag=false;
			School * curr1;
			if(root==NULL)
			{
				cout<<"There is no element is tree"<<endl;
			}
			else
			{
				curr1=root;
				while(curr1!=NULL && !flag)
				{				
					if(curr1->Room_name==name1)
					{
						flag=true;
						if(flag)
						{
							curr1->obj.srchbyid(srch_id);
						}
				
					}
					else if(curr1->Room_name > name1)
					{
						curr1=curr1->Left_link;
					}
					else
					{
						curr1=curr1->Right_link;
					}
				}
			}
		}
		void DeleteByid(int id , string name2)
		{
			bool flag=false;
			School *curr1;
			if(root==NULL)
			{
				cout<<"There is no element is tree"<<endl;
			}
			else
			{
				curr1=root;
				while(curr1!=NULL && !flag)
				{				
					if(curr1->Room_name==name2)
					{
						flag=true;
						if(flag)
						{
							curr1->obj.deleteNode(id);
							cout<<"DELETE SUCCSEFULLY"<<endl;
						}
				
					}
					else if(curr1->Room_name > name2)
					{
						curr1=curr1->Left_link;
					}
					else
					{
						curr1=curr1->Right_link;
					}
				}
			}
		}
	/*	void DeleteClass(School *p)
	{
		School *current;
		School *trailcurrent;
		School *temp;
		
		if(p==NULL)
		{
			cout<<"ERROR : THE NODE TO BE DELETED IN NULL. "<<endl;
		}
		else if(p->Left_link==NULL && p->Right_link)
		{
			temp=p;
			p=temp->Right_link;
			delete temp;
		}
		else if(p->Left_link==NULL)
		{
			temp=p;
			p=temp->Left_link;
			delete temp;
		}
		else if(p->Right_link==NULL)
		{
			temp=p;
			p=temp->Right_link;
			delete temp;
		}
		else
		{
			current=p->Left_link;
			trailcurrent=NULL;
			while(current->Right_link!=NULL)
			{
				trailcurrent=current;
				current=current->Right_link;
			}
			p->Room_name=current->Room_name;
			if(trailcurrent==NULL)
			{
				p->Left_link=current->Left_link;
			}
			else
			{
				trailcurrent->Right_link=current->Left_link;
			}
			delete current;
		}
		
	}
	void deleteNode(string class_name)
	{
		School *curr;
		School *t_curr;
		bool found =false;
		
		if(root==NULL)
		{
			cout<<"CANNOT DELETE FORM THE EMPTY LIST "<<endl;
		}
		else
		{
			curr=root;
			t_curr=root;
			
			while(curr!=NULL && !found)
			{
				if(curr->Room_name==class_name)
				{
					found = true;
					if(found)
					{
						curr->obj.destroyTree(curr->obj.root1);	
						cout<<"DELETE SUCCUFULLY !"
						<<endl;	
					}		
				}	
				else
				{
					t_curr=curr;
					if(curr->Room_name > class_name)
					{
						curr=curr->Left_link;
					}
					else
					{
						curr=curr->Right_link;
					}
				}
				if(curr==NULL)
				{
					cout<<"The delete item is not in the tree "<<endl;
				}
				else if(found)
				{
					if(curr==root)
					{
						DeleteClass(root);
					}
					else if(t_curr->Room_name >class_name)
					{
						DeleteClass(t_curr->Left_link);
					}
					else
					{
						DeleteClass(t_curr->Right_link);
					}
				}
			}	
		}
	}*/
};
int main()
{	
	List object;
	List1 object1;
		char ch1 ,ch;
		string class_name,clas__name,n;
		int srch_id;
	string classname;

	object.Room_name("CS");
		object.Room_name("MATH");
	object.Room_name("SE");
	object.Room_name("BBA");
	object.Room_name("AF");
	object.Room_name("BE.D");	
	
	
	cout<<setw(55)<<"  -----------------------------------------"<<endl;
	cout<<setw(50)<<" >UNIVERSITY MANAGMENT SYSTEM" <<endl;
	cout<<setw(55)<<"  -----------------------------------------"<<endl;
	block:
	cout<<" > ADD STUDENT                    (1)"<<endl;
	cout<<" > VIEW STUDENT BY ID             (2)"<<endl;
	cout<<" > VEIW ALL STUDENT BY CLASS NAME (3)"<<endl;
	cout<<" > DELETE STUDENT                 (4)"<<endl;
	cout<<" > DISPLAY ALL CLASS DATA         (5)"<<endl;
	cout<<endl;
	cout<<"PRESS : ";
	cin>>ch1;
	if(ch1=='1')
	{
	
		cout<<"> MATH"<<endl;
		cout<<"> CS"<<endl;
		cout<<"> SE"<<endl;
		cout<<"> BBA"<<endl;
		cout<<"> AF"<<endl;cout<<"> BE.D"<<endl;
			cout<<"SELECT DEPARTMENT "<<endl;
		cin>>classname;
		object.Search(classname);
		cout<<endl;
		cout<<"      > DATA ADDED SUCCESFULLY ! "<<endl;
		cout<<"Press y for go back : ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
		system("cls");
		cout<<endl;
		goto block;
		
	}
	else if (ch1=='2')
	{
		cout<<"ENTER THE CLASS NAME :";
		cin>>clas__name;
		cout<<"ENTER THE STUDENT ID : ";
		cin>>srch_id;
		object.srchbyid(srch_id,clas__name);
		cout<<"Press y for go back : ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
		system("cls");
		cout<<endl;
		goto block;
	}
	else if (ch1=='3')
	{
		cout<<"ENTER THE CLASS NAME ";
		cin>>class_name;	
		object.srchbyclassname(class_name);
		cout<<"Press y for go back : ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
		system("cls");
		cout<<endl;
		goto block;
	}
	else if(ch1=='4')
	{
		cout<<"ENTER THE CLASS NAME :";
		cin>>clas__name;
		cout<<"ENTER THE STUDENT ID : ";
		cin>>srch_id;
		object.DeleteByid(srch_id,clas__name);
		cout<<"Press y for go back : ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
		system("cls");
		cout<<endl;
		goto block;
	}
	else if(ch1=='5')
	{
		object.InorderTraversal(object.root);
		cout<<"Press y for go back : ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
		system("cls");
		cout<<endl;
		goto block;
	}
	else
	{
		cout<<"You entered wrong number : "<<endl;
			cout<<"Press y for go back : ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
		system("cls");
		cout<<endl;
		goto block;
	}
	
	
	
}

