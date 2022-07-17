#include<iostream>
using namespace std;
//rec binary
int arr[]={5,10,15,20,25,30,35,40,45,50};
int size1 = sizeof(arr)/sizeof(arr[0]);
int size2 = *(&arr + 1) - arr; 
static int a=0,left1=0,right1=size1 - 1,element=25,mid;

int get_mid(int left,int right)
{ 
    return ((left+right)/2); 
}

int find_bin(int element=element,int arr[]=arr)
{
    //int a=0,left=0,right=size1 - 1,mid;
    //int mid;
    if(a<(size1/2)+1)
    {
        mid=get_mid(left1,right1);
        if(arr[mid]==element)
        {
            
        }
        else if(left1==right1)
        {
            mid=-1;
        }
        else
        {
            if(element<arr[mid])
            {
                right1=mid-1;
            }
            else
            {
                left1=mid+1;
            }
            a++;
            find_bin(element);
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
    //int found_at =find_bin(30,arr);
    ele_find(50,arr);
    return 0;
}