#include <iostream>
#define max 5
int arr[max]={2,4,5,7,9};
static int top=0;
int static size2;

using namespace std;

class stack
{
private:
    /* data */
public:
    void push(int arr[]=arr)
    {

        if(top==size2)
        {
            cout<<"stack overflow \n";
        }
        else
        {
            
            cout << "\n enter value for arr["<<top<<"] :";
            cin>>arr[top];
            //arr[top]=(top);
            top++;
            
        }

    }

    void pop(int arr[]=arr)
    {
        if (top==0)
        {
            cout<<"stack underflow\n";
        }
        else
        {
            top--;
            cout << "poping out value for arr["<<top<<"] :"<<arr[top]<<endl;
            arr[top]=0;
        }
        
    }

    void print(int arr[]=arr)
    {
        for(int a=0;a<size2-1;a++)
        {
            cout<<"=====\t";
        }
        cout<<"=====\n";
        for(int a=0;a<size2;a++)
        {
            cout<<"| "<<arr[a]<<" |"<<"\t";
        }
        cout<<"\n";
        for(int a=0;a<size2-1;a++)
        {
            cout<<"=====\t";
        }
        cout<<"=====\n\n";
    }

    void choice(int arr1[]=arr)
    {
        
        int c=6;
        while (c)
        {
            cout << "\n 1[push] , 2[pop] , 3[print] else [exit] :";
            cin>>c;
            switch (c)
            {
            case 1:
                push(arr1);
                break;

            case 2:
                pop(arr1);
                break;

            case 3:
                print(arr1);
                break;

            default:
                cout << "do you want to exit !! ";
                char d;
                cin>>d;
                if(d=='y' || d=='Y')
                {
                    c=0;
                }
                break;
            }
        }
        
    }

};



int main()
{
    
    int a=0;
    stack o1;
    cout << "stack size:";
    int stack_size;
    cin>>stack_size;
    int arr1[stack_size];
    size2 = *(&arr1 + 1) - arr1;
    o1.choice(arr1);
    o1.print(arr1);
    //system("clear");
    return 0;
}


