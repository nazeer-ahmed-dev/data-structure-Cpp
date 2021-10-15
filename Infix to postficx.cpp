#include<iostream>
using namespace std;
struct stack
{
	int num;
	int top;
	int *arrayPointer;
	void initilize(int size)
	{
		arrayPointer= new int[size];
		top=-1;
	}
	void push(int x)
	{
		top++;
		arrayPointer[top]=x;
	}
	void pop()
	{
		top--;
	}
	void InfixtoAns(char s)
	{
		if(int(s)>=48 && int(s)<=57)
		{
			int number=int(s)-48;
			push(number);
		}
		else if(s=='*')
		{
			num=arrayPointer[top]*arrayPointer[top-1];
			pop();
			pop();
			push(num);
		}
		else if(s=='+')
		{
			num=arrayPointer[top]+arrayPointer[top-1];
			pop();
			pop();
			push(num);
		}
		else if(s=='-')
		{
			num=arrayPointer[top]-arrayPointer[top-1];
			pop();
			pop();
			push(num);
		}
		else if(s=='/')
		{
			num=arrayPointer[top]/arrayPointer[top-1];
			pop();
			pop();
			push(num);
		}
	}
	void display()
	{
		for(int i=0;i<=top;i++)
		{
			cout<<arrayPointer[i]<<" ";
		}
	}
};
int  main()
{
	stack Obj;
	string exp="528*+3+";
	Obj.initilize(exp.length());
	for(int i=0;i<exp.length();i++)
	{
		Obj.InfixtoAns(exp[i]);
	}

	Obj.display();
}
