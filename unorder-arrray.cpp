#include<iostream>
#include<conio.h>
using namespace std;
int IsertArray(int Array[])
{
	
	cout<<"Enter the number "<<endl;
	//cout<<size;
		cin>>Array[3];
	for(int j=0;j<5;j++)
	{
		cout<<Array[j]<<" ";
	}
	cout<<endl;
	
}
void searching(int Array[],int num)
{

	for(int i=0;i<5;i++)
	{
		if(Array[i]==num)
		{
			
			cout<<"Index is : "<<i<<endl;
		}
	}
}
void remove(int Array[],int numb)
{
	for(int i=0;i<5;i++)
	{
		if(Array[i]==numb)
		{
			for(int j=i;j<5;j++)
			{
					Array[j]=Array[j+1];
			}
			
		}
	}
	cout<<"List is : ";
	for(int i=0;i<5;i++)
	{
		cout<<Array[i];
		
	}
	cout<<endl;
	
}
int main()
{
	int array[5]={4,6,3},num,val;
	IsertArray(array);
	
	cout<<"Enter the number for searching : ";
		cin>>num;
	searching(array,num);
	cout<<"Enter the number for remove : ";
	cin>>val;
	remove(array,val);
}
