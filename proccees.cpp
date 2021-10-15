#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class Teacher
{	
	string Name, email,  qualification,gender;
	double emplyeedID , designation;
	public:
	void getTeacherInput() 
	{
			cout<<"    GET INFOMATION  "<<endl;
		cout<<"ENTER THE NAME          : ";
		cin>>Name;
		cout<<endl;
		cout<<"ENTER THE EMPLOYEED ID  : ";
		cin>>emplyeedID;
		cout<<endl;
		cout<<"ENTER THE GENDER        : ";
		cin>>gender;
		cout<<endl;
		cout<<"ENTER THE EMAIL         : ";
		cin>>email;
		cout<<endl;
		cout<<"ENTER THE DESIGNATION   : ";
		cin>>designation;
		cout<<endl;	
		cout<<"ENTER THE QUALIFICATION : ";
		cin>>qualification;
	}
	void dispayInfo()
	{
		cout<<endl;
			cout<<"       DISPLAY INFORMATION"<<endl;
		cout<<"   |  NAME          : "<<Name<<endl;
		cout<<"   |  ID            : "<<emplyeedID<<endl;
		cout<<"   |  EMAIL         : "<<email<<endl;
		cout<<"   |  GENDER        : "<<gender<<endl;
		cout<<"   |  DESIGNATION   : "<<designation<<endl;
		cout<<"   |  QUALIFICATION : "<<qualification<<endl;
	}
	int compareByID(int id)
	{
		if(emplyeedID==id)
		cout<<"hi";
		
		{return true;}	
    } 
};
class Department
{	
	string DepartmentName;
	Teacher *TeacherInfo ,obj3;
	Teacher HOD();
	int maxDepSize,currSize;
	public:
		Department()
	{
	}
	Department(string depname, int depsize)
	{
		DepartmentName=depname;
		maxDepSize=depsize;
			TeacherInfo=new Teacher[maxDepSize];
			for(int i=0;i<maxDepSize;i++)
			{
					TeacherInfo[i].getTeacherInput();
			}
		
		//	delete []TeacherInfo;
	}
	
//	~Department()
//	{
//				cout<<"ARRAY IS DELETED"<<endl;
//	}
//	void RestDepartment()
//	{
//		delete []TeacherInfo;
//		currSize=0;
//		TeacherInfo=new Teacher[maxDepSize];
//	}
	void addemply()
	{
		
	}
	void TerminateEmployee(int id)
	{
		cout<<"hi";
		for(int k=0;k<10; k++){
			cout<<"hi";
		TeacherInfo[k].compareByID(id);
		{
			for(int j=k;j<currSize;j++)
			{
				TeacherInfo[j]=TeacherInfo[j+1];
				cout<<"Do you want to check "<<endl;
				int ch1;
				cin>>ch1;
				if(ch1=='1')
				{
					obj3.dispayInfo();
				}
			}
			
		}}
	}
	
};
int main()
{
	string Departmentname;
	int sizeofdepartment,id;
	Department obj;
	Teacher obj1;
	cout<<"ENTER THE DEPARTMENT NAME :";
	cin>>Departmentname;
	cout<<"Enter the size of Department: ";
	cin>>sizeofdepartment;
	Department(Departmentname,sizeofdepartment);
	Department();
//	obj.RestDepartment();
	
	cout<<"Enter the ID";
	cin>>id;
	obj.TerminateEmployee(id);
	
	
	
}
