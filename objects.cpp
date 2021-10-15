#include<iostream>
using namespace std;
struct Node
{
	int data;
	int array[3];
};
int main()
{
	Node obj[10];
	cout<<sizeof(obj)/sizeof(Node);
}
