#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;
class Teacher
{	
	string Name, email,  qualification,gender,designation;
	int emplyeedID;
	
	
	public:
	////////////////////////////////////////////////////////////////////	
		void getTeacherInput() 
		{
			cout<<endl;
			cout<<setw(20)<<"       --------------------------------------"<<endl;
			cout<<setw(20)<<"       >. ENTER THE INFORMATION OF EMPLOYEEs "<<endl;
			cout<<setw(20)<<"       --------------------------------------"<<endl;
			cout<<"ENTER THE NAME          : ";
			cin>>Name;
			cout<<"ENTER THE EMPLOYEED ID  : ";
			cin>>emplyeedID;
			cout<<"ENTER THE GENDER        : ";
			cin>>gender;
			cout<<"ENTER THE EMAIL         : ";
			cin>>email;
			cout<<"ENTER THE DESIGNATION   : ";
			cin>>designation;
			cout<<"ENTER THE QUALIFICATION : ";
			cin>>qualification;
		}
	////////////////////////////////////////////////////////////////////
		
	////////////////////////////////////////////////////////////////////	
		void dispayInfo()
		{
				cout<<endl;
			cout<<"-------------------------------"<<endl;
			cout<<"      > DISPLAY INFORMATION"<<endl;
			cout<<"   |  NAME          : "<<Name<<endl;
			cout<<"   |  ID            : "<<emplyeedID<<endl;
			cout<<"   |  EMAIL         : "<<email<<endl;
			cout<<"   |  GENDER        : "<<gender<<endl;
			cout<<"   |  DESIGNATION   : "<<designation<<endl;
			cout<<"   |  QUALIFICATION : "<<qualification<<endl;
			cout<<"-------------------------------"<<endl;
		}
	////////////////////////////////////////////////////////////////////
		
	////////////////////////////////////////////////////////////////////	
		int compareByName(string compName)
		{
		
		
			cout<<endl;
			if(compName==Name)
			return true;
		}
	////////////////////////////////////////////////////////////////////
		
	////////////////////////////////////////////////////////////////////	
		int compareByID(int id1)
		{
			if(emplyeedID==id1)
			return true;
		//	{
		//	cout<<endl;
		//	cout<<"ID IS MATCHING "<<endl;
		//	}
		//	else
		//	{
		//		cout<<"NOt matching:"<<endl;
		///	}
    	} 
    ////////////////////////////////////////////////////////////////////	
    	
	////////////////////////////////////////////////////////////////////	
		void ChangeDesignation()
		{
			string changeDesignation;
			cout<<endl;
			cout<<"ENTER THE NEW DESIGNATION :";
			cin>>changeDesignation;
			designation=changeDesignation;
			cout<<"DESIGNATION CHANGED ! "<<endl;
			
		}
	////////////////////////////////////////////////////////////////////
		
	////////////////////////////////////////////////////////////////////	
		void ChangeQualification()
		{
			string changeQualification;
			cout<<endl;
			cout<<"ENTER THE NEW QUALIFICATION :";
			cin>>changeQualification;
			qualification=changeQualification;
			cout<<"QUALIFICATION CHANGED !"<<endl;
		}
	////////////////////////////////////////////////////////////////////	
		
	//`///////////////////////////////////////////////////////////////////	
		void check()
		{
			char ch1;
			cout<<endl;
			cout<<"YOU WANT TO CHECK DATA ENTER Y FOR YES N FOR NO ";
			cin>>ch1;
			if(ch1=='y' || ch1=='Y')
			dispayInfo();
		}
	////////////////////////////////////////////////////////////////////	
};

class Department
{
	string DepartmentName,name;
	int depsize;
	Teacher *TeacherInfo ,emplyeedID,obj, *ptr;
	Teacher HOD();
	int maxDepSize,currSize;
	
	public:
	////////////////////////////////////////////////////////////////////	
		Department()
		{
			
		}
	////////////////////////////////////////////////////////////////////	
	
	////////////////////////////////////////////////////////////////////
		Department(string DeptName, int DeptSize)
		{
			
			DepartmentName=DeptName;
			maxDepSize=DeptSize;
			
			TeacherInfo=new Teacher[maxDepSize];
			currSize=0;
			//cout<<maxDepSize;
		}
	////////////////////////////////////////////////////////////////////
		
	////////////////////////////////////////////////////////////////////	
		~Department()
		{
			delete [] TeacherInfo;
		}
		
	////////////////////////////////////////////////////////////////////	
	/*	void checking()
		{
			obj.dispayInfo();	
		}
		
		void ResetDepartment(int DeptSize)
		{
			cout<<DeptSize;
			delete []TeacherInfo;
			currSize=0;
			cout<<DeptSize;
			maxDepSize=DeptSize;
			cout<<maxDepSize;
			ptr=new Teacher[maxDepSize];
			
		}
		*/
		
	////////////////////////////////////////////////////////////////////
	
	////////////////////////////////////////////////////////////////////	
		void AddEmployee()
		{
			
		//	cout<<endl;
			cout<<setw(20)<<"       --------------------------"<<endl;
			cout<<setw(20)<<"       >. ADD DEPARTMENT       : "<<endl;
			cout<<setw(20)<<"       --------------------------"<<endl;
			cout<<"ENTER THE NAME OF DEPARTMENT:>";
			cin>>name;
			cout<<"ENTER THE SIZE OF EMPLOYEE:>";
			cin>>depsize;
			maxDepSize=depsize;
			TeacherInfo=new Teacher[maxDepSize];
			
			for(int l=0;l<maxDepSize;l++)
			{
				TeacherInfo[l].getTeacherInput();
				currSize++;
			}
			
		}
		int show(string name1)
		{
			if(name==name1)
			return true;
		}
		void showEmp()
		{
			for(int l=0;l<maxDepSize;l++)
			{
				TeacherInfo[l].dispayInfo();
			}	
		}
	////////////////////////////////////////////////////////////////////
		
	////////////////////////////////////////////////////////////////////	
		void TerminateEmployee(int id2)
		{
			for(int i=0;i<currSize;i++)
			{
				if(TeacherInfo[i].compareByID(id2)==true)
					{
						cout<<i<<endl;
					  	for(int j=i;j<currSize;j++)
						{
							cout<<"done :"<<endl;
							cout<<j;
							TeacherInfo[j]=TeacherInfo[j+1];
								
						}
					}
			}
			
			for(int l=0;l<currSize;l++)
			{
				TeacherInfo[l].dispayInfo();
			}
				
		}
	////////////////////////////////////////////////////////////////////	
		
	////////////////////////////////////////////////////////////////////	
		void searchEmpById(int searchID)
		{
			for(int i=0;i<maxDepSize;i++)
			{
				if(TeacherInfo[i].compareByID(searchID)==true)
				{
				
						TeacherInfo[i].dispayInfo();
					
				}		
	   		}
		}	
	////////////////////////////////////////////////////////////////////
		
	////////////////////////////////////////////////////////////////////	 
		 void searchEmpByName(string searchName)
	 	{
			
			for(int i=0;i<maxDepSize;i++)
			{
				if(TeacherInfo[i].compareByName(searchName)==true)
				{
					TeacherInfo[i].dispayInfo();
				}		
	   		}
	 	} 
	////////////////////////////////////////////////////////////////////	
	
	////////////////////////////////////////////////////////////////////	  
		void PromoteEmployee(int id4)
	   {
	  
	  		for(int i=0;i<maxDepSize;i++)
			{
				if(TeacherInfo[i].compareByID(id4)==true)
				{
						obj.ChangeDesignation();
						//	obj.dispayInfo();
					}
		   		} 
		}
	////////////////////////////////////////////////////////////////////
		
	////////////////////////////////////////////////////////////////////	
		void changeQualification1()
		{
		   	obj.ChangeQualification();
		}
	////////////////////////////////////////////////////////////////////	   
		   
};
class University
{
	string UniName, location, VCName, RegistrarName;
	Department *UniDepartments,*ptr;
	int  maxDepartments, currUniSize;
	
	public:
		University()
		{
			
		}
		
		University(string university_name,int max_size)
		{
			UniName=university_name;
			maxDepartments=max_size;
			UniDepartments=new Department[maxDepartments];
			currUniSize=0;
		}
		
		
		~University()
		{
			delete []UniDepartments;
		}
		
		void RestUni()
		{
			delete []UniDepartments;
			currUniSize=0;
			ptr=new Department[maxDepartments];
			cout<<"DEPARTMENT IS REST :"<<endl;
	
		}
		
		void RemoveDept()
		{
			
		}
		
		void AddDept(int max_size)
		{
	
			
			maxDepartments=max_size;
			UniDepartments=new Department[maxDepartments];
			
			for(int l=0;l<maxDepartments;l++)
			{
				UniDepartments[l].AddEmployee();
				currUniSize++;
			}
			cout<<"DATa IS STORED :"<<endl;
		}
		
		void showdata(string depname)
		{
			string deptname;
			deptname=depname;
			for(int j=0;j<currUniSize;j++)
			{
				if(UniDepartments[j].show(deptname)==true)
				{
					for(int l=j;l<currUniSize;l++)
					{
						cout<<" ----------------------------------------"<<endl;
						cout<<" >.   FACULTY MEMBER OF "<<deptname<<" DEPARTMENT :"<<endl;
						cout<<" -----------------------------------------"<<endl;
						UniDepartments[l].showEmp();
					}
				}
			}
			
		}
};
int main()
{
	
	University object3;
	string university_name,searchName;
	int max_size,size,searchID,id4;
	char ch1,ch4,ch6,ch7,ch8,ch9;
	cout<<endl;
	cout<<setw(55)<<" -----------------------------------"<<endl;
	cout<<setw(55)<<" >. UNIVERSITY MANAGMENT SYSTEM : "<<endl;
	cout<<setw(55)<<" -----------------------------------"<<endl;
	block:
	cout<<"  |   UNIVERSITY    (PRESS - 1) |"<<endl;
	cout<<"  |   DEPARTMENT    (PRESS - 2) |"<<endl;
	cout<<"  |   TEACHER       (PRESS - 3) |"<<endl;
	cin>>ch1;
	switch(ch1)
	{

		case '1':
		{
			block1:
			cout<<"  |   UNIVERSITY        (PRESS - 1) |"<<endl;
			cout<<"  |   ADD DEPARTMENT    (PRESS - 2) |"<<endl;
			cout<<"  |   RESET UNI         (PRESS - 3) |"<<endl;
			cout<<"  |   DEP:FACULTY       (PRESS - 4) |"<<endl;
			cout<<endl;
			cin>>ch9;
			if(ch9=='1')
			{
				cout<<"ENTER THE NAME OF UNIVERISTY:>    ";
				cin>>university_name;
				cout<<"ENTER THE SIZE OF DEPARTMENT:>    ";
				cin>>max_size;
				University(university_name,max_size);
				cout<<endl;
				//object3.AddDept(max_size);
				cout<<"ENTER Y TO GO BACK AND X FOR GO TO MAIN MENU"<<endl;
				char ch11;
				cin>>ch11;
				if(ch11=='y' || ch11=='Y')
				{
					goto block1;	
				}
				else
				{
					goto block;	
				}
			}
			
			else if(ch9=='2')
			{
				cout<<endl;
				cout<<"ENTER THE SIZE OF DEPARTMENT:>    ";
				cin>>max_size;
				object3.AddDept(max_size);	
				cout<<"ENTER Y TO GO BACK AND X FOR GO TO MAIN MENU"<<endl;
				char ch12;
				cin>>ch12;
				if(ch12=='y' || ch12=='Y')
				{
					goto block1;	
				}
				else
				{
					goto block;	
				}
			}
			else if(ch9=='3')
			{
				object3.RestUni();
				
				char ch13;
				cout<<"ENTER Y TO GO BACK AND X FOR GO TO MAIN MENU"<<endl;
				cin>>ch13;
				if(ch13=='y' || ch13=='Y')
				{
					goto block1;	
				}
				else
				{
					goto block;	
				}
			}
			
			else if(ch9=='4')
			{
				string depname;
				cout<<"ENTER THE NAME OF DEPARTMENT :";
				cin>>depname;
				object3.showdata(depname);
			}
			else
			{
				cout<<"ERROR "<<endl;
				goto block1;
			}
			
			goto block;
		}
		case '2':
		{
			block3:
			cout<<"  |   ADD EMPLOYEE           (PRESS - 1) |"<<endl;
			cout<<"  |   SEARCHBYNAME           (PRESS - 2) |"<<endl;
			cout<<"  |   SEARCHBYID             (PRESS - 3) |"<<endl;
			cout<<"  |   TERMINATEEMPLLOYEE     (PRESS - 4) |"<<endl;
			cout<<"  |   PROMOTEEMPLOYEE        (PRESS - 5) |"<<endl;
			cout<<"  |   CHAGNEQUALIFICATION    (PRESS - 6) |"<<endl;
			cout<<endl;
			cin>>ch4;
			Department object1;
			if(ch4=='1')
			{
				object1.AddEmployee();
				char ch11;
				cout<<"ENTER Y TO GO BACK AND X FOR GO TO MAIN MENU"<<endl;
				cin>>ch11;
				if(ch11=='y' || ch11=='Y')
				{
					goto block3;	
				}
				else
				{
					goto block;	
				}	
			}
			
			else if(ch4=='2')
			{
				cout<<"ENTER THE NAME TO SEARCH THE DATA :>";
				cin>>searchName;
				object1.searchEmpByName(searchName);
				cout<<endl;	
				char ch11;
				cout<<"ENTER Y TO GO BACK AND X FOR GO TO MAIN MENU"<<endl;
				cin>>ch11;
				if(ch11=='y' || ch11=='Y')
				{
					goto block3;	
				}
				else
				{
					goto block;	
				}
			}
			else if(ch4=='3')
			{
				cout<<"ENTER THE ID TO SEARCH THE DATA :>";
				cin>>searchID;
				object1.searchEmpById(searchID);
				char ch11;
				cout<<"ENTER Y TO GO BACK AND X FOR GO TO MAIN MENU"<<endl;
				cin>>ch11;
				if(ch11=='y' || ch11=='Y')
				{
					goto block3;	
				}
				else
				{
					goto block;	
				}
			
			}
			else if(ch4=='4')
			{
				int id4;
				cout<<"ENTER THE ID :>";
				cin>>id4;
				object1.TerminateEmployee(id4);
				char ch11;
				cout<<"ENTER Y TO GO BACK AND X FOR GO TO MAIN MENU"<<endl;
				cin>>ch11;
				if(ch11=='y' || ch11=='Y')
				{
					goto block3;	
				}
				else
				{
					goto block;	
				}
			}
			else if(ch4=='5')
			{
			cout<<"ENTER THE ID :> ";
			cin>>id4;
			object1.PromoteEmployee(id4);
			cout<<endl;
			
			char ch11;
			cout<<"ENTER Y TO GO BACK AND X FOR GO TO MAIN MENU"<<endl;
				cin>>ch11;
			
				if(ch11=='y' || ch11=='Y')
				{
					goto block3;	
				}
				else
				{
					goto block;	
				}
	
			}
			else if(ch4=='6')
			{
				object1.changeQualification1();
				char ch11;
				cout<<"ENTER Y TO GO BACK AND X FOR GO TO MAIN MENU"<<endl;
				cin>>ch11;
				if(ch11=='y' || ch11=='Y')
				{
					goto block3;	
				}
				else
				{
					goto block;	
				}
				
			}
		}
		case '3':
		{
			block4:
			cout<<"  |   GET-INFORMATION        (PRESS - 1) |"<<endl;
			cout<<"  |   DISPLAYINFORMATION     (PRESS - 2) |"<<endl;
			char ch22;
			cin>>ch22;
			Teacher object2;
			if(ch22=='1')
			{
				object2.getTeacherInput();
				char ch11;
				cout<<"ENTER Y TO GO BACK AND X FOR GO TO MAIN MENU"<<endl;
				cin>>ch11;
				if(ch11=='y' || ch11=='Y')
				{
					goto block4;	
				}
				else
				{
					goto block;	
				}
			
			}
			else if(ch22=='2')
			{
			
				object2.dispayInfo();
				char ch11;
				cout<<"ENTER Y TO GO BACK AND X FOR GO TO MAIN MENU"<<endl;
				cin>>ch11;
				if(ch11=='y' || ch11=='Y')
				{
					goto block4;	
				}
				else
				{
					goto block;	
				}
			}
				
			}
			
		}

	}
	
	
	/*
	
	
	////////////////////////////////////
		Teacher object;
	//	object.getTeacherInput();
	//	object.dispayInfo();
	//	object.compareByName();
		
	//	int id1;
	//	cout<<endl;
	//	cout<<"ENTER THE ID ";
	//	cin>>id1;
	//	object.compareByID(id1);
		
	//	object.ChangeDesignation();
	//	object.ChangeQualification();
	//	object.check();
	
	////////////////////////////////////
	
	////////////////////////////////////
		
	/*	
		string DeptName;
		int DeptSize;
		cout<<"ENTER THE DEPARTMENT NAME :";
		cin>>DeptName;
		cout<<endl;
		cout<<"ENTER  THE DEPARTMENT SIZE :";
		cin>>DeptSize;
		Department(DeptName,DeptSize);
	
		//object1.checking();
		
	//	int againsize;
	//	cout<<"ENTER THE MAX DEPARTMENT SIZE :";
	//	cin>>DeptSize;
	//	object1.ResetDepartment(DeptSize);
			
		object1.AddEmployee(DeptSize);
		
		//int id2;
		//cout<<"ENTER THE ID :";
		//cin>>id2;
		
		//object1.TerminateEmployee(id2);
		int searchID;
		cout<<"ENTER THE ID FOR SEARCHING :";
		cin>>searchID;
		object1.searchEmpById(searchID);
			
			string searchName;
			cout<<"ENTER NAME FOR SEARCHING : ";
			cin>>searchName;
		object1.searchEmpByName(searchName);
		
		cout<<"ENTER THE ID FOR PROMOTHION :";
		int id4;
		cin>>id4;
		object1.PromoteEmployee(id4);
		
		object1.changeQualification1();
		
	/////////////////////////////////////////////	
	
	University object3;
	string university_name;
	int max_size;
	cout<<"ENTER THE UNIVERSITY NAME :";
	cin>>university_name;
	cout<<"ENTER THE SIZE : ";
	cin>>max_size;
	University(university_name,max_size);
	
	int size;
	cout<<"Enter the size of dept ";
	cin>>size;
	object3.AddDept(size);
	
	*/
	


