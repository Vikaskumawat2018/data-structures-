#include<iostream>
using namespace std;
//non rec binary
int arr[]={5,10,15,20,25,30,35,40,45,50};
int size1 = sizeof(arr)/sizeof(arr[0]);
int size2 = *(&arr + 1) - arr;
int element=25;

int get_mid(int left,int right)
{ 
    return ((left+right)/2); 
}

int find_bin(int element=element,int arr[]=arr)
{
    int left=0,right=size1 - 1,mid;
    for(int a=0;a<(size1/2)+1;a++)
    {
        mid=get_mid(left,right);
        if(arr[mid]==element)
        {
            break;
        }
        else if(left==right)
        {
            mid=-1;
            break;
        }
        else
        {
            if(element<arr[mid])
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        
    }
    
    
    return mid;
}

bool ele_find(int element=element,int arr[]=arr)
{
    bool finded=true;
    int res=find_bin(element);
    if(res==-1)
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


int main() {
    //cout<<size<<size1;
    //cout<<*(&arr)<<*(&arr + 1)<<arr;
    int found_at =ele_find(30,arr);
    
    
    return 0;
}