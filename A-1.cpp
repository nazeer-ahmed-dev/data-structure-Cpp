#include<iostream>
using namespace std;
class Teacher
{
    string email, gender, designation, qualification;
//    string employee_Id, name, email, gender, designation, qualification;
    public:
        string employee_Id,name;

    void getTeacherInput()
    {
        cout<<"write the name of the teacher"<<endl;
        getline(cin,name);
        cout<<"write the email of the teacher"<<endl;
        getline(cin,email);
        cout<<"write the id of the teacher "<<endl;
        getline(cin,employee_Id);
        cout<<"write the gender of the teacher "<<endl;
        getline(cin,gender);
        cout<<"write the designation of the teacher "<<endl;
        getline(cin,designation);
        cout<<"write the qualification of the teacher "<<endl;
        getline(cin,qualification);
    }
    void displayInfo()
    {
        cout<<"name :"<<name<<endl;
        cout<<"email :"<<email<<endl;
        cout<<"employee_Id :"<<employee_Id<<endl;
        cout<<"gender :"<<gender<<endl;
        cout<<"designation :"<<designation<<endl;
        cout<<"qualification :"<<qualification<<endl;
    }
    bool compareByName(string name_check)
    {
        if(name==name_check)
        {
            cout<<"name matched"<<endl;
            return true;
        }
        else
        {
            cout<<"name not matched"<<endl;
            return false;
        }

    }
    bool compareByID(string id_check)
    {
        if(id_check==employee_Id)
        {
            cout<<"ID matched"<<endl;
            return true;
        }
        else
        {
            cout<<"ID not matched"<<endl;
            return false;
        }
    }
    void ChangeDesignation()
    {
        cout<<"write the new designation of the employee"<<endl;
        string line;
        cin>>line;
        designation=line;
        cout<<"the designation is changed to "<<designation<<endl;
    }
    void ChangeQualification()
    {
        cout<<"write the new qualification of the employee "<<endl;
        string line;
        cin>>line;
        qualification = line;
        cout<<"the qualification is changed to "<<qualification<<endl;
    }
};
class Department
{

    Teacher *TeachersInfo,*pointer_to_TeachersInfo;
    Teacher HOD;
    int MaxDeptSize,currSize;

public:
    //int static counter;
    string DepartmentName;
    Department()
    {
        /*
         cout<<"write the name of the department"<<endl;
         cin>>DepartmentName;
         cout<<"write the detail of HOD of the HOD"<<endl;
         HOD.getTeacherInput();
         cout<<"write the size of the department"<<endl;
         cin>>MaxDeptSize;
         TeachersInfo = new Teacher[MaxDeptSize];
         currSize =0;
        */
    }
     Department(string DepartmentName,int DeptSize)
     {
         this->DepartmentName = DepartmentName;
         MaxDeptSize = DeptSize;
         currSize =0;
         TeachersInfo = new Teacher[MaxDeptSize];
     }
     ~Department()
     {
         delete []TeachersInfo;
     }
     void ResetDepartment(int MaxDeptSize)
     {
         this->MaxDeptSize  = MaxDeptSize;
         delete []TeachersInfo;
         currSize = 0;
         pointer_to_TeachersInfo = new Teacher[MaxDeptSize];
         TeachersInfo = pointer_to_TeachersInfo;
        currSize = 0;
     }
     void TerminateEmployee(string id)
     {
         for(int i=0; i<currSize; i++)
         {
             Teacher obj = TeachersInfo[i];
             if((obj.employee_Id)==id)
             {
                 currSize--;
                 for(int j=i; j<MaxDeptSize-1; j++)
                 {
                    TeachersInfo[j]= TeachersInfo[j+1];
                 }
                 cout<<id<<" is terminated"<<endl;
             }
         }
     }
     void AddEmployee()
     {
         cout<<"you are adding the employee "<<currSize+1<<endl;
         if(currSize<MaxDeptSize)
         {
            Teacher obj;
            obj.getTeacherInput();
            TeachersInfo[currSize] = obj;
            currSize++;
         }
    }
     void searchEmpById(string id)
     {
         for(int i=0; i<currSize; i++)
         {
             Teacher obj = TeachersInfo[i];
            if(obj.employee_Id==id)
            {
                obj.displayInfo();
            }
         }
     }
     void searchEmpByName(string name_g)
     {
         for(int i=0; i<currSize; i++)
         {
             Teacher obj = TeachersInfo[i];
            if(obj.name==name_g)
            {
                obj.displayInfo();
            }
         }
     }
     void PromoteEmployee(string id)
     {
         for(int i=0; i<currSize; i++)
         {
             Teacher obj = TeachersInfo[i];
            if(obj.name==id)
            {
                TeachersInfo[i].ChangeDesignation();
            }
         }
     }
     void ChangeQualification(Teacher t)
     {
         for(int i=0; i<currSize; i++)
         {
             Teacher obj = TeachersInfo[i];
            if(obj.name==t.name)
            {
                TeachersInfo[i].ChangeQualification();
            }
         }
     }
     void display()
     {
         for(int i=0; i<currSize; i++)
         {
             TeachersInfo[i].displayInfo();
         }
     }
     void display_name_faculty()
     {
         for(int i=0; i<currSize; i++)
         {
             cout<<TeachersInfo[i].name<<endl;
         }
     }
     void set_Detail()
     {
         cout<<"write the name of the department"<<endl;
         cin>>DepartmentName;
         cout<<"write the detail of HOD of the HOD"<<endl;
         HOD.getTeacherInput();
         cout<<"write the size of the department"<<endl;
         cin>>MaxDeptSize;
         TeachersInfo = new Teacher[MaxDeptSize];
         currSize =0;
     }
};
//int Department::counter=0;
class University
{
    string UniName, location,VCName, RegistrarName;
    int maxDepartments, currUniSize;
    Department *UniDepartments,*pointer_to_UniDepartments;
public:
    int static counter;
    University(string UniName,int size_given)
    {
        this->UniName = UniName;
        this->maxDepartments = size_given;
        currUniSize = 0;
        UniDepartments = new Department[maxDepartments];
        cout<<"write the VC name"<<endl;
        cin>>VCName;
        cout<<"write the Location"<<endl;
        cin>>location;

    }
    ~University()
    {
        delete []UniDepartments;

    }
    void ResetUni(int size_given)
    {
        delete []UniDepartments;
        this->maxDepartments = size_given;
        pointer_to_UniDepartments = new Department[maxDepartments];
        currUniSize = 0;
        UniDepartments = pointer_to_UniDepartments;
        counter = 0;

    }
    void RemoveDept(string name_search)
    {
		for(int i=0; i<counter; i++)
		{
			if(UniDepartments[i].DepartmentName==name_search)
			{
				for(int j=i; j<maxDepartments-1; j++)
				{
					UniDepartments[j] = UniDepartments[j+1];
				}
				counter--;
			}
		}
    }
    void AddDept()
    {
        cout<<"you are adding department "<<counter+1<<endl;
        if(counter<maxDepartments)
        {

            Department obj;
            obj.set_Detail();
            UniDepartments[counter] = obj;
            counter++;
        }
    }
    void dispDeptFaculty()//Department obj)
    {
        for(int i=0; i<counter; i++)
        {
            UniDepartments[i].display_name_faculty();
        }
    }
    void set_department_detail()
    {
        for(int i=0; i<counter; i++)
        {
            UniDepartments[i].set_Detail();
        }
    }

};
int University::counter=0;
int main()
{
    
    Teacher obj;
    obj.getTeacherInput();
    obj.displayInfo();
    obj.ChangeQualification();
    obj.ChangeDesignation();
    cout<<obj.compareByName("ali");
    cout<<obj.compareByID("90");
    obj.displayInfo();
    
  Department d;

    
    Department("CS",6);
    d.AddEmployee();
    d.AddEmployee();
    d.AddEmployee();
    d.AddEmployee();

    d.searchEmpById("90");
    d.searchEmpByName("ali");
    d.TerminateEmployee("90");
    d.display();

    Department("CS",2);
    d.AddEmployee();
    d.ResetDepartment(3);
    d.AddEmployee();
    d.display();

}
