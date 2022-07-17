#include <iostream>

using namespace std;
int arr[]={1,5,9,6,4,3,8,2,7};
int size1 = sizeof(arr)/sizeof(arr[0]);
//int size1=10;
int size2 = *(&arr + 1) - arr;
//int j;

class selection_sort
{
    void swap(int *y,int *z)
    {
        int tmp=*y;
        *y=*z;
        *z=tmp;
    }
    public:

    void sort(int arr[]=arr)
    {
        int min,i,j;
        for (i = 0; i < size1-1; i++)
        {
            min=i;
            for (j = i+1; j < size1; j++)
            if(arr[j]<arr[min])
                min=j;
             
            swap(&arr[min],&arr[i]);
        } 
    } 


 /*    void sort(int arr[]) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < size1-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < size1; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swap(&arr[min_idx], &arr[i]); 
    } 
} */ 
    

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
    selection_sort o1;
    o1.print(arr);
    o1.sort(arr);
    o1.print(arr);

    return 0;
}