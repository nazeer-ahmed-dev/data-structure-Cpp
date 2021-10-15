#include <iostream>
using namespace std;
struct postFix
{
	int maxSize, stackTop;
	char *list;
	postFix(string str)
	{
		maxSize=str.length();
		stackTop=0;
		list=new char[maxSize];
	}
	void pushOP(char ch)
	{
		list[stackTop]=ch;
		stackTop++;
	}
	void pushNum(char ch)
	{
		list[stackTop]=ch;
		stackTop++;
	}
	void popOp()
	{
		stackTop--;
	}
	void popNum()
	{
		stackTop--;
	}
	char back()
	{
		return list[stackTop-1];
	}
	void display()
	{
		for(int i=0; i<stackTop; i++)
		{
			cout<<list[i];
		}
	}
};
int main()
{

	string exp;
	cout<<"Enter expression"<<endl;
	cin>>exp;
	postFix obj1(exp);
	postFix obj2(exp);
	for(int i=0; i<exp.length(); i++)
	{
	if(exp[i]>=48 && exp[i]<=57)
	{
		obj1.pushNum(exp[i]);
	}	
	else if(exp[i]=='*' || exp[i]=='+' || exp[i]=='-' || exp[i]=='/')
	{
		if(exp[i]=='*' && ((exp[i]+4)<obj2.back()))
		{
			cout<<"if"<<endl;
			while((obj2.back())>(exp[i]+4))
			{
			obj1.pushNum(obj2.back());
			obj2.stackTop--;
			}
			obj2.pushOP(exp[i]);
		}
		else if(obj2.back()=='*' && (obj2.back()+4)>exp[i])
		{
			while(true)
			{
			if(obj2.back()=='*' && obj2.back()+4>exp[i])
			{
			obj1.pushNum(obj2.back());
			obj2.stackTop--;
			}
			else if(obj2.back()>exp[i])
			{
			obj1.pushNum(obj2.back());
			obj2.stackTop--;	
			}
			else
			break;
		}
			obj2.pushOP(exp[i]);
		}
		else if(exp[i]!='*' && (obj2.back()>exp[i]))
		{
			while(obj2.back()>exp[i])
			{
			obj1.pushNum(obj2.back());
			obj2.stackTop--;
			}
			obj2.pushOP(exp[i]);	
		}
		else if(exp[i]!='*' && exp[i]<obj2.back())
		{
			while(obj2.back()>exp[i])
			{
			obj1.pushNum(obj2.back());
			obj2.stackTop--;
			}
			obj2.pushOP(exp[i]);
		}
		else
		{
		obj2.pushOP(exp[i]);	
		}
	}
	if(i==exp.length()-1)
	{
		while(obj2.stackTop!=0)
		{
		obj1.pushNum(obj2.back());
		obj2.stackTop--;
		}
	}
}
obj1.display();
}
