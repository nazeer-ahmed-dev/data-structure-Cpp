#include <iostream>
using namespace std;
class Teacher{
	private:
		string Name, email, qualification, gender;
		int employeeId,scale;
		int choice;
	public:
		getTeacherInput(){
			cout<<"Enter your ID"<<endl;
			cin>>employeeId;
			cout<<"Enter your Name"<<endl;
			cin.ignore();
			getline(cin,Name);
			cout<<"Enter your email"<<endl;
			cin>>email;
			cout<<"Enter your gender"<<endl;
			cin>>gender;
			cout<<"Enter your scale"<<endl;
			cin>>scale;
			cout<<"Enter your qualificaton"<<endl;
			cin>>qualification;
		}
		displayInfo(){
			cout<<"This is your Information"<<endl;
			cout<<"------------------------"<<endl;
			cout<<"ID: "<<employeeId<<endl;
			cout<<"Name: "<<Name<<endl;
			cout<<"Email: "<<email<<endl;
			cout<<"Gender: "<<gender<<endl;
			cout<<"scale: "<<scale<<endl;
			cout<<"Qualification: "<<qualification<<endl;
		}
		bool compareByName(string compName){
			if(compName==Name){
			 return true;
			}
			else
			return false;
		}
		bool compareById(int compId){

			if(compId==employeeId)
			 return true;
			 else
			 return false;
		}
		changeScale(){
			cout<<"Enter new Scale:"<<endl;
			cin>>scale;
			cout<<"you are promoted to new scale Scale:"<<endl;
		}
		changeQualification(){
			cout<<"Enter new Qualification:"<<endl;
			cin>>qualification;
			cout<<"your qualification is changed:"<<endl;
		}
};
class Department{
	private:
	string departmentName;
	Teacher *teacherInfo;
	Teacher HOD;
	int maxDeptSize,currSize;
	public:
		Department(){
		}
		Department(string deptName,int DeptSize){
			maxDeptSize=DeptSize;
			teacherInfo=new Teacher[maxDeptSize];
			currSize=0; 


		}
		void AddDept(string name,int maxSize){
			departmentName=name;
			maxDeptSize=maxSize;
			teacherInfo=new Teacher[maxSize];
			currSize=0; 
			cout<<"Enter number of current employees"<<endl;
			int num;
			cin>>num;
			for(int i=0; i<num; i++){
			cout<<"Enter information of employee "<<i+1<<endl;	
				AddEmployee();	
			}
		}
		bool findDept(string name){
			if(departmentName==name)
			return true;
			else
			return false;
		}
		
		void display(){
			for(int i=0; i<currSize; i++){
				teacherInfo[i].displayInfo();
			}
			
		}
		~Department(){
			delete []teacherInfo;
		}
		void ResetDepartment(){
			delete []teacherInfo;
			currSize=0;
			cout<<"Department is reset to 0"<<endl;
		} 
		void AddEmployee()
		{
				if(currSize<maxDeptSize)	{
			
			teacherInfo[currSize].getTeacherInput();
			currSize++;
			}
		
		}
		void searchEmpById(int id){
		int i;
			cout<<currSize;
			for(i=0; i<=currSize; i++){
			bool flag=teacherInfo[i].compareById(id);
			if(flag==true)
				teacherInfo[i].displayInfo();
				break;
			}
			if(i==currSize)
			cout<<"Not found"<<endl;
		}
		void searchEmpByName(string name){

			int i;
			for(i=0; i<currSize; i++){
			bool flag=teacherInfo[i].compareByName(name);
			if(flag==true){
			teacherInfo[i].displayInfo();
			break;
			}
		}
		if(i==currSize)
			cout<<"Not found"<<endl;
	}
		void terminateEmployee(int id){
			
			int i;
			for(i=0; i<currSize; i++){
			bool flag=teacherInfo[i].compareById(id);
			if(flag==true){
				if(i==(currSize-1)){
				teacherInfo[i]=teacherInfo[i];
				cout<<"Employee is removed"<<endl;
			}
			else
			for(int j=i; j<currSize; j++){
				teacherInfo[j]=teacherInfo[j+1];
				cout<<"Employee is removed"<<endl;
		}
		}
			}
			currSize--;	
				
		}
		void PromoteEmployee(int id){
			int i;
			
			for(i=0; i<currSize; i++){
			bool flag=teacherInfo[i].compareById(id);
			if(flag==true){
				teacherInfo[i].changeScale();
				break;
			}
			}
		} 
		void ChangeQualification(int id){
			
			int i;
			for(i=0; i<currSize; i++){
			bool flag=teacherInfo[i].compareById(id);
			if(flag==true){
				teacherInfo[i].changeQualification();
				break;
			}
		}
	}
	string get_name()
	{
		return departmentName;
	}
};
class University{
	private:
		string uniName,location,VCName,RegistrarName;
		int currUniSize,maxDepartments;
		Department *UniDepartments;
	public:
		University(string name,int maxDept){
			uniName=name;
			UniDepartments = new Department[maxDept];
		}
		void mResetUni(){
			currUniSize=0;
			delete []UniDepartments;
			cout<<"Enter max Departments of University"<<endl;
			cin>>maxDepartments;
			UniDepartments = new Department[maxDepartments];
		}
		
		void AddDept(){
			string deptName;
			int size;
			cin>>deptName;
			cout<<"Enter max size of employee in dept:"<<endl;
			cin>>size;
			UniDepartments[currUniSize].AddDept(deptName,size);
			currUniSize++;
		}
		
		void RemoveDept(string name){
			for(int i=0; i<currUniSize; i++){
				if(UniDepartments[i].findDept(name)==true)
				{
						if(i==(currUniSize-1))
						UniDepartments[i]=UniDepartments[i];
						else
					for(int j=i; j<currUniSize; j++){
						UniDepartments[j]=UniDepartments[j+1];
					}
					currUniSize--;
			cout<<"Department Removed"<<endl;
				}
			}
		} 
		void displayFaculty(string name)
		{
			for(int i=0; i<currUniSize; i++)
			{
				if(UniDepartments[i].get_name()==name)
				{
					UniDepartments[i].display();
				}
			}
		}
	void sempById(int id){
		for(int i=0; i<currUniSize; i++)
		UniDepartments[i].searchEmpById(id);
	}
	void sEmpByName(string name){
		for(int i=0; i<currUniSize; i++)
		UniDepartments[i].searchEmpByName(name);
		
	}
	void promoteEmp(int id){
		for(int i=0; i<currUniSize; i++)
	UniDepartments[i].PromoteEmployee(id);
}
	void ChangeQual(int id){
		for(int i=0; i<currUniSize; i++)
	UniDepartments[i].ChangeQualification(id);
}
	void terminateEmp(int id){
		for(int i=0; i<currUniSize; i++)
	UniDepartments[i].terminateEmployee(id);
}

};
int main(){
	Teacher obj1;
	int choice,deptnum;
	bool Message;
		string uname;
		cout<<"Enter name of university:"<<endl;
		cin>>uname;
		cout<<"Enter number of departents"<<endl;
		cin>>deptnum;
		University uni(uname,deptnum);
		
		uni.mResetUni();
		
		string name;
		int emp;
		cout<<"Enter name of Department:"<<endl;
		cin>>name;
		cout<<"Enter number of max employee in Dept:"<<endl;
		cin>>emp;
		Department obj2(name,emp);
		Department obj4;
		obj2.ResetDepartment(); 

	for(int i=0; i<deptnum; i++){
		cout<<"Enter Name of Department "<<i+1<<endl;
		uni.AddDept();
	}
		
	cout<<"Enter Id to show employee:"<<endl;
	int id;
	cin>>id;
	uni.sempById(id);
		cout<<"Enter Name to search Employee:"<<endl;
		string Empname;
		cin.ignore();
		getline(cin,Empname);
	uni.sEmpByName(Empname);
	
	cout<<"Enter your Id for promotion:"<<endl;
		int empId;
	cin>>empId;
	uni.promoteEmp(empId);
	
	cout<<"Enter id for changing Qualification:"<<endl;
	cin>>empId;
	
	uni.ChangeQual(empId); 
	cout<<"Enter ID to remove Employee:"<<endl;
	cin>>empId;
	uni.terminateEmp(empId);
	
	cout<<"Enter Name to search Employee:"<<endl;
	cin.ignore();
	getline(cin,Empname);
	uni.sEmpByName(Empname);
	cout<<"Enter dept name to remove"<<endl;
	string dept;
	cin>>dept;
	uni.RemoveDept(dept);
	
		string dep;
	for(int i=0; i<deptnum; i++){
	cout<<"Enter name of department to show faculty info:"<<endl;
	cin>>dep;
	uni.displayFaculty(dep);
}
//	Message=uni.dispDeptFaculty();
//	if(Message==true)
//	obj2.display();
//	else
//	cout<<"Not found"<<endl;
//	

//
//	Message=uni.dispDeptFaculty();
//	if(Message==true)
//	obj2.display();
//	else
//	cout<<"Not found"<<endl;
//		
//	Message=uni.dispDeptFaculty();
//	if(Message==true)
//	obj2.display();
//	else
//	cout<<"Not found"<<endl;
	



/*	obj1.getTeacherInput();
	obj1.displayInfo();
	cout<<"Enter Name for checking your Registration:"<<endl;
	cin.ignore();
	getline(cin,name);
	Message=obj1.compareByName(name);
	
	if(Message==true)
	cout<<"You are registered"<<endl;
	else
	cout<<"Not found"<<endl;
	cout<<"Enter your ID for checking your registration:"<<endl;	
	int id;
	cin>>id;
	Message=obj1.compareById(id);
	if(Message==true)
	cout<<"You are registered"<<endl;
	else
	cout<<"Not found"<<endl;
	cout<<"Change designation"<<endl;
		obj1.changeDesignation();
	cout<<"Change Qualification"<<endl;	
		obj1.changeQualification();
		string name;
		int st;
		cout<<"Enter name of Department:"<<endl;
		cin>>name;
		cout<<"Enter number of max students in Dept:"<<endl;
		cin>>st;
	Department obj2(name,st);
	Department *array=new Department[10];
	
	obj2.AddEmployee();
	obj2.AddEmployee();
//	obj2.searchEmpById();
//	obj2.searchEmpByName();
//	obj2.terminateEmployee();
//	obj2.PromoteEmployee();
//	obj2.ChangeQualification(); 
//	obj2.searchEmpByName();
//	obj2.ResetDepartment(); 
	
	University obj3;
	obj3.AddDept();
	cout<<"Enter dept name to remove"<<endl;
	string dept;
	cin>>dept;
	obj3.RemoveDept(dept);
	obj3.dispDeptFaculty();
	obj3.mResetUni();
	*/
}
