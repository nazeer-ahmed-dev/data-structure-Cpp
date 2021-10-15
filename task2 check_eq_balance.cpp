#include <iostream>
using namespace std;
struct Balance
{
	int maxSize,stackTop;
	char *Array;
	Balance(string str)
	{
		maxSize=str.length();
		stackTop=0;
		Array=new char[maxSize];
	 } 
	void push(char str)
	{
	 	Array[stackTop++] = str;
	}
	void pop()
	{
		stackTop--;	
	}
	bool is_balance()
	{
		return(stackTop==0);
	}
};
int main()
{
	cout<<"Enter Equation"<<endl;
	string eq;
	getline(cin,eq);
	Balance obj(eq);
	for(int i=0; i<eq.length(); i++)
	{
	if(eq[i]=='('||eq[i]=='{'||eq[i]=='[')
		{
			obj.push(eq[i]);
		}
	else if(eq[i]==')'||eq[i]=='}'||eq[i]==']')
		{
			if(obj.Array[obj.stackTop-1]=='(')
		{
			if(eq[i]==')')
			obj.pop();
			else
			break;
		}
		else if(obj.Array[obj.stackTop-1]=='{')
		{
			if(eq[i]=='}')
			obj.pop();
			else
			break;
		}
		else if(obj.Array[obj.stackTop-1]=='[')
		{
			if(eq[i]==']')
			obj.pop();
			else
			break;
		}	
		}
	}
	bool flag=obj.is_balance();	
	if(flag)
	cout<<"Equation is balanced "<<endl;
	else
	cout<<"Equation is not balanced "<<endl;

}
