#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int number,counter,sum=0;
	cout<<"Enter the number :";
	cin>>number;
		for(int i=1;i<=number;i++)
		{
			if(number%i==0)
			{
					if(i%2!=0)
					{
						sum+=i;
					}
			}
		
		}
	cout<<"Sum of odd number is :"<<sum<<endl;
}
