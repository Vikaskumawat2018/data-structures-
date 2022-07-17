#include <iostream>

using namespace std;
int arr[]={1,5,9,6,4,3,8,2,7};
int size1 = sizeof(arr)/sizeof(arr[0]);
int size2 = *(&arr + 1) - arr;

class bubble_sort
{
    void swap(int &y,int &z)
    {
        int tmp=y;
        y=z;
        z=tmp;
    }
    public:
    void sort(int arr[]=arr)
    {
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size1-i; j++)
            {
                if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
            }
            
        }
        
    }

    void print(int arr[]=arr)
    {
        for(int a=0;a<size1-1;a++)
        {
            cout<<"=====\t";
        }
        cout<<"=====\n";
        for(int a=0;a<size1;a++)
        {
            cout<<"| "<<arr[a]<<" |"<<"\t";
        }
        cout<<"\n";
        for(int a=0;a<size1-1;a++)
        {
            cout<<"=====\t";
        }
        cout<<"=====\n\n";
    }

};


int main() {
    bubble_sort o1;
    o1.print();
    o1.sort();
    o1.print();

    return 0;
}