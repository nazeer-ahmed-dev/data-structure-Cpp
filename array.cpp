#include<iostream>
using namespace std;
int main()
{
	string name;
	getline(cin,name);
//	cout<<name;
	//cout<<name.length();
	for(int i=0;i<name.length();i++)
	{
		if(name[i]=='i' && name[i+1]=='s')
		{
			cout<<" was ";
			i=i+2;
		}
		else
		{
			cout<<name[i];
		}
	}
}
