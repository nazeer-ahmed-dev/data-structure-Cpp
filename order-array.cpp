#include<iostream>
#include<conio.h>
using namespace std;
void insert(int Array[],int num)
{
	int i;
	for(i=0;i<6;i++)
	{
		if(num<Array[i])
		break;
	}
	for(int j=6;j>i;j--)
	{
		Array[j]=Array[j-1];
	}
	Array[i]=num;
	cout<<"List is :";
	for(int s=0;s<6;s++)
	{
		cout<<Array[s]<<" ";
	}
	cout<<endl;
}
int search(int srch,int Array[],int sizeofarray)
{
	int loweridex=0;
	int upperindex=sizeofarray-1;
	int size;
	while(true)
	{
	 size=(loweridex+upperindex)/2;
		if(Array[size]==srch)
		{
			cout<<"index is : ";	
			return size;
		}
		else if(loweridex>upperindex)
		{
			return sizeofarray;	
		}
		else
		{
			if(Array[size]<srch)
			{
				loweridex=size+1;
			}
			else
			upperindex=size-1;	
		}
	}
}
int main()
{
	int array[6]={1,2,4,5,6},number;
	cout<<"ENTER THE NUMBER WHICH YOU WNAT TO INSERT :";
	cin>>number;
	cout<<endl;
	insert(array,number);
	int nElm=sizeof(array)/sizeof(array[0]);
	cout<<"Enter the number which index you want to search :";
	int srch;
	cin>>srch;
	search(srch,array,nElm);
}
