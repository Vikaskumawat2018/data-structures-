#include <iostream>

using namespace std;
int arr[]={10,1,5,9,6,4,3,8,2,7};
int size1 = sizeof(arr)/sizeof(arr[0]);
//int size1=10;
int size2 = *(&arr + 1) - arr;
//int j;

class insertion_sort
{
    public:


    void sort(int arr[]=arr)
    {
        
        for(int i=1;i<size1;i++)
        {
            int tmp=arr[i];
            int j=i-1;
            while (j>=0 && arr[j]>tmp)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=tmp;
        }     
    }  

    /*  void sort(int arr[]=arr)
    {
        int i, key, j;
    for (i = 1; i < size1; i++)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    }  */

 

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
    insertion_sort o1;
    o1.print(arr);
    o1.sort(arr);
    o1.print(arr);

    return 0;
}