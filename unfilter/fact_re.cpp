#include<iostream>
using namespace std;

int fact(int n=5)
{	
	int result=1;
	if(n>0)
	{	
		result*=(n*fact(n-1));
	}
	
	return result; 
}

int main()
{
	cout<<"\nfactorial is "<<fact();

}
