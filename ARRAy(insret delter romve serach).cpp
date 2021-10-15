#include<iostream>
using namespace std;
void InsertUnorder(int array[], int num ,int num1)
{
	array[4]=num;
	for(int i=0;i<num1;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
void removeUorder(int array1[], int num,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(num==array1[i])
		{
			break;
		}		
	}
		for(int j=i;j<6;j++)
			{
				array1[j]=array1[j+1];
			}
}
	
void searchunordder(int array[],int number1)
{
	for(int i=0;i<6;i++)
	{
		 if(number1==array[i])
		 {
			cout<<i; 	
		 }	
	}	
}
void insertorder()
{
	
}
void binraryserach()
{
	
}
void removeorder()
{
	
}
void reversearray()
{
	
}
int main()
{
	int number,removenumber,search;
	int array[6]={1,3,4,5};
	cout<<"enter the number"<<endl;
	cin>>number;
	InsertUnorder(array,number,5);
	cout<<"Enter the number which you want remove "<<endl;
	cin>>removenumber;
	removeUorder(array,removenumber,6);
	cout<<"Enter the number which you want to search: "<<endl;
	cin>>search;
	searchunordder(array,4);
}
