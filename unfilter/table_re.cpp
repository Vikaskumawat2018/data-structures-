#include<iostream>

using namespace std;

int tab=5;

void table(int n=1,int t=tab)
{	
	if(n<11)
	{	
		cout<<t<<"*"<<n<<"\t=\t"<<t*n<<endl;
		n++;
		table(n);
	}
	
}

int main()
{	
	
	cout<<"enter the value for print table:";
	cin>>tab;
	table();
	//table(1,tab);


}
