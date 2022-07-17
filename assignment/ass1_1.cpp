#include<iostream>
using namespace std;
//non rec linear
int arr[]={5,10,15,20,25,30,35,40,45,50};
int size1 = sizeof(arr)/sizeof(arr[0]);
int size2 = *(&arr + 1) - arr;

int find(int arr[],int element)
{
    int z;
    for(z=0;z<size1;z++)
    {
        if(arr[z]==element || arr[z]>=element)
        {
            if(arr[z]>element || size1==z)
            {
                z=-1;   
            }
            break;
        }  
    }
    return z;
}

int main() {
    //cout<<size<<size1;
    //cout<<*(&arr)<<*(&arr + 1)<<arr;
    int found_at =find(arr,40);
    if(-1<found_at)
    {
        cout<<"element found at index="<<found_at;
    }
    else
    {
        cout<<"element not found";
    }
    
    return 0;
}