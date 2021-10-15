#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class Teacher
{	
	string Name, email, designation, qualification,gender;
	double emplyeedID;
	public:
	void getTeacherInput() 
	{
			cout<<"    GET INFOMATION  "<<endl;
		cout<<"ENTER THE NAME          : ";
		getline(cin,Name);
		cout<<endl;
		cout<<"ENTER THE EMPLOYEED ID  : ";
		cin>>emplyeedID;
		cout<<endl;
		cin.ignore();
		cout<<"ENTER THE GENDER        : ";
		cin>>gender;
		cout<<endl;
		cin.ignore();
		cout<<"ENTER THE EMAIL         : ";
		getline(cin,email);
		cout<<endl;
		cout<<"ENTER THE DESIGNATION   : ";
		getline(cin,designation);
		cout<<endl;	
		cout<<"ENTER THE QUALIFICATION : ";
		getline(cin,qualification);
	}
	void dispayInfo()
	{
		cout<<endl;
			cout<<"       DISPLAY INFORMATION"<<endl;
		cout<<"   |  NAME          : "<<Name<<endl;
		cout<<"   |  ID            : "<<emplyeedID<<endl;
		cout<<"   |  EMAIL         : "<<email<<endl;
		cout<<"   |  GENDER        : "<<gender<<endl;
		cout<<"   |  DESIGNATION   : "<<designation<<" "<<&designation<<endl;
		cout<<"   |  QUALIFICATION : "<<qualification<<" "<<&qualification<<endl;
	}
	void compareByName(string compName)
	{
		if(compName==Name)
		cout<<"YOUR ARE REGISTRED !"<<endl;
		else
		cout<<"NOT REGISTERED !"<<endl;
	
	}
	void compareByID(double compID)
	{
		if(emplyeedID==compID)
		cout<<"YOUR ARE REGISTERED !"<<endl;
		else
		cout<<"NOT REGISTERED !"<<endl;
		cout<<endl;
		
	}
	void ChangeDesignation(string changeDesignation)
	{
		designation=changeDesignation;
		cout<<&designation;
		cout<<&changeDesignation;
	}
	void ChangeQualification(string changeQualification)
	{
		qualification=changeQualification;
	}
};
class Department
{	
	string DepartmentName;
	Teacher *TeacherInfo ,obj;
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
		currSize=0;
		
	}
	~Department()
	{
		delete TeacherInfo[];
		cout<<"Array deleted : "<<endl;
	}
	void ResetDepartment()
	{
		delete ptr[];
		currsize=0;
		TeacherInfo=new Teacher[maxDepSize];
	}
	void TerminateEmployee()
	{
		obj.compareByID();
	}
	
	
	
	
};
class University
{
	
};
int main()
{	
	int compID;
	string compName,changeDesignation,changeQualification;
	Teacher object;
//	object.getTeacherInput();
	/////////////////////////////////////////////
//	object.dispayInfo();
	////////////////////////////////////////////
	cout<<endl;
	cout<<"ENTER THE NAME FOR COMPARISION : ";
	getline(cin,compName);
//	object.compareByName(compName);
	////////////////////////////////////////////
	cout<<endl;
	cout<<"ENTER THE ID : ";
	cin>>compID;
   // object.compareByID(compID);
    /////////////////////////////////////////////
	cin.ignore();
	cout<<"ENTER THE NEW DESIGNATION :";
	getline(cin,changeDesignation);
	cout<<endl;
   //object.ChangeDesignation(changeDesignation);
   ////////////////////////////////////////////////////
	cout<<"ENTER THE NEW QUALIFICATION :";
	getline(cin,changeQualification);
	//object.ChangeQualification(changeQualification);
	//////////////////////////////////////////////////////////
	cout<<endl;
	cout<<"         NEW INFORMATION : "<<endl;
	//object.dispayInfo();
	//////////////////////////////////////////////////////
	string depname;
	int depsize;
	cout<<"ENTER THE DEPARTMENT NAME : ";
	cin>>depname;
	cout<<"ENTER THE DEPARTMENT SIZE : ";
	cin>>depsize;
	Department(depname,depsize);
	Department obj;
	obj.ResetDepartment();
	
}
