#include<iostream>
using namespace std;
int insert( int array[] , int numb)
{
	int last=5;
	int first=0;
	int size;
	while(true)
	{
		size=(last+first)/2;
		if(array[size]==numb)
		{
			 return size;	
		}	
		else if(first > last)
		{
			return last;
		}
		else
		{
			if(numb > array[size])
			{
				last = size-1;
			}
			else
			first=first+1;
		}
	}
}
int main()
{
	
	int  number , array[5]={1,2,3,4,5};
	cout<<"Enter the number want search "<<endl;
	cin>>number;
	cout<<insert(array,number);
}

