/* print 1-50 number
#include<iostream>
using namespace std;
void Function(int number)
{
	if(number<=50)
	{
		cout<<number<<" ";
		Function(number+1);
	}
}
int main()
{
	Function(1);
}
// Sum of 1 to n number 
#include<iostream>
using namespace std;
void Function(int n,int sum)
{
	if(n<=5)
	{
		sum+=n;
		Function(n+1,sum);
	}
	else
	{
		cout<<sum;
	}
}
int main()
{
//	int number;
//	cout<<"Enter the number ";
//	cin>>number;
	int sum=0;
	Function(1,sum);
}
// print array element using recrusion
#include<iostream>
using namespace std;
int array[]={1,2,3,3,3,4,4,5,6,6};
void function(int num)
{
	if(num<10)
	{
		cout<<array[num]<<" ";
		function(num+1);		
	}
}
int main()
{
	function(0);
}*/
// count the digit 
#include<iostream>
using namespace std;
int function(int num1)
{
	static int ctr=0;
	if(num1!=0)
	{
		ctr++;
		function(num1/10);
	}
	return ctr;
}
int main()
{
	int num;
	cout<<"Enter the number "<<endl;
	cin>>num;
	cout<<function(num);	
}

