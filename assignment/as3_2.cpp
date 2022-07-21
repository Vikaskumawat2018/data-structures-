#include<iostream>

/*
Queue linear
*/
using namespace std;
//static int max =7;

class Queue_linear
{
private:
    int front=0,rear=0,max=7;
    int arr[7];
public:

    void setMax(int max)
    {
        this->max=max;
    }

    int input()
    {
        int temp;
        cin >> temp;
        return temp;
    }

    void enQueue()
    {
        if (rear==max)
        {
            cout << "\nqueue is full\n";
        }
        else
        {
            cout<<"\ninsert value for arr["<<rear<<"]=";
            arr[rear]=input();
            rear++;
        }
    }

    void deQueue()
    {
        if (rear==front)
        {
            cout << "\nqueue is empty\n";
            rear=front=0;
        }
        else
        {
            cout<<"removing value of where arr["<<front<<"]="<<arr[front];
            arr[front]=0;
            front++;
        }
    }

    void print()
    {   cout<<"\n";
        for (int i = front; i < rear; i++)
        {
            //cout<<"arr["<<i<<"]="<<arr[i]<<"\t";
            cout<<arr[i]<<"\t";
        }    
        cout<<"\n";
    }

    void insertval()
    {
        enQueue();
    }

    void delval()
    {
        deQueue();
    }

};

int main()
{
    Queue_linear o1;
    //int max=7;
    //o1.setMax(max);
    o1.insertval();
    o1.insertval();
    o1.insertval();
    o1.insertval();
    o1.print();
    o1.insertval();
    o1.insertval();
    o1.insertval();
    o1.insertval();
    o1.insertval();
    o1.print();
    o1.delval();
    o1.delval();
    o1.print();
    return 0;
}