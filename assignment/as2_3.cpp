#include <iostream>

using namespace std;
//int arr[]={1,5,9,6,4,3,8,2,7};
int arr[]={44,33,11,55,77,90,40,60,22};
int size1 = sizeof(arr)/sizeof(arr[0]);
//int size1=10;
int size2 = *(&arr + 1) - arr;
//int j;

class quick_sort
{
    /*  void swap(int *y,int *z)
    {
        int tmp=*y;
        *y=*z;
        *z=tmp;
    }  */
     void swap(int &y,int &z)
    {
        int tmp=y;
        y=z;
        z=tmp;
    } 
    public:

    int partition(int arr[],int low,int high)
    {
        int pivoat=arr[high];
        int in=high;
        int i=low-1;
        for(int j=low;j<high;j++)
        {
            if(arr[j]<arr[in])
            {
                i++;
                swap(arr[i],arr[j]);
            }
        }
        i++;
        swap(arr[i],arr[in]);
        print(arr);
        return i;
    }

    void sort(int arr[],int low,int high)
    {
        
        if(low<high)
        {
            int pavotin=partition(arr,low,high);
            sort(arr,low,pavotin-1);
            sort(arr,pavotin+1,high);   
        }        
    } 

 

    void print(int arr[]=arr)
    {
        for(int a=0;a<size1-1;a++)
        {
            cout<<"=====";
        }
        cout<<"=====\n";
        for(int a=0;a<size1;a++)
        {
            cout<<"| "<<arr[a]<<" |"<<"";
        }
        cout<<"\n";
        for(int a=0;a<size1-1;a++)
        {
            cout<<"=====";
        }
        cout<<"=====\n\n";
    }

};


int main() {
    quick_sort o1;
    o1.print(arr);
    o1.sort(arr,0,size1-1);
    o1.print(arr);

    return 0;
}