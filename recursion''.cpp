#include<iostream>
using namespace std;
void function(int n)
{
	if(n>0)
	{
		cout<<n;
		function(n-1);
		function(n-1);
		
	}
}
int main()
{
	function(3);
}
