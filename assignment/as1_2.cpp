#include<iostream>
using namespace std;

//rec linear

int arr[]={5,10,15,20,25,30,35,40,45,50};
int size1 = sizeof(arr)/sizeof(arr[0]);
int size2 = *(&arr + 1) - arr;
static int z=0;
int element=25;

int find(int element=element,int arr[]=arr)
{
    //int z=0;
    if(z<size1 && z > -1 )
    {
    if(arr[z]==element || arr[z]>=element)
    {
            if(arr[z]>element || size1==z)
            {
                z=-2;
            }    
    }  
    else
    {
        z++;
        find(element);
    }    
    
    }
    return z;
}

bool ele_find(int element=element,int arr[]=arr)
{
    bool finded=true;
    int res=find(element);
    if(res==-2)
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
