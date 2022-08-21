#include<iostream>
using namespace std;

//linear 

int arr[]={5,10,15,20,25,30,35,40,45,50};
int size1 = sizeof(arr)/sizeof(arr[0]);
int size2 = *(&arr + 1) - arr;
static int z=0;
int element=25;

int find(int element1=element,int arr1[]=arr)
{
    z=0;
    int i=0;
    
    for (i = 0; i < size2; i++)
    {
        if (arr1[i]==element1)
        {
            z=i;
            break;
        }
    }
    
    return z;
}

bool ele_find(int element1=element,int arr1[]=arr)
{
    bool finded=true;
    int res=find(element1);
    if(res==0)
    {
        cout<<"element not found";
        finded=false;
    }
    else
    {
        cout<<"element found at index:"<<res;
    }
    return finded;
}


int main()
{
    //int result=find();
    //find();
    //cout<<result;
    ele_find(40);


    return 0;
}
