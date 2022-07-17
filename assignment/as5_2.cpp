//#include <iomanip>
//#include <ios>
#include<iostream>
using namespace std;


static int nodecount=0,nodecountverify=1,test=1;
static bool dry_run=true;
static bool dry_run_full=false;

struct  node
{
    public:
    int data;
    node * next;
}


*front=NULL,*rear=NULL
;

void showlink(node *n1=front)
    {
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else
        {

            cout<<"&=\t";
            cout<<&front<<"\nfront=\t";
            cout<<front;
            cout<<"\n\t |  ";
            cout<<"\n\t |  ";
            cout<<"\n\t ^  ";
            node* ptr = front;
            cout<<"\n\t";
            ptr = front;
            while (ptr!=NULL)
            {
                cout<<"=====\t\t";
                ptr=ptr->next;
            }
            cout<<"=====\n\t";
            ptr = front;

            while (ptr!=NULL)
            {
                cout<<"|"<<ptr->data<<"|*|->\t\t";
                //cout<<"|"<<ptr->data<<"|"<<ptr->next<<"|->\t\t";
                ptr=ptr->next;
            }
            cout<<"NULL\n\t";
            ptr = front;
            while (ptr!=NULL)
            {
                cout<<"=====\t\t";
                ptr=ptr->next;
            }
            cout<<"=====\n";

            ptr = front;
            cout<<"\t";
            while (ptr!=NULL)
            {
                cout<<ptr<<"  ";
                ptr=ptr->next;
            }
            cout<<"\n\t";


        }
        cout<<"\n\n num of node:"<<nodecount<<"\n";
   }

    bool is__empty()
    {
        return front==NULL && rear==NULL;
    }
    
    void dequeue()
    {
        if(is__empty())
        {
            cout<<"\nERROR:underflow \n";
        }
        else
        {
            if(rear==front)
            {
                node *temp=front;
                cout<<"freeing last node["<<temp<<"] where data is:"<<temp->data<<"\n";
                delete temp;
                front=NULL;
                rear=NULL;
            }
            else
            {
                node *temp=front;
                //n1=n1->next;
                front=front->next;
                cout<<"freeing node["<<temp<<"] where data is:"<<temp->data<<"\n";
                delete temp;
            }
            
            nodecount--;
            showlink();
        }
        
    }

    void insertData(node *n1)
    {
        cout << "\ninsert data for rear of queue:";
        cin>>n1->data;
    }

    void enqueue()
    {
        node *temp=new node();
        if (!temp)
        {
            cout << "\nerror:stack overflow \n";
        }
        else
        {
            if(rear==NULL)
            {
                rear=temp;
                front=temp;
            }
            else
            {
                rear->next=temp;
                //rear=rear->next;
                rear=temp;
            }
            //top=temp;
            insertData(rear);
            nodecount+=1;
            showlink();
        }
    }


    void freeAll(node *n1=front)
    {
        if(front==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else
        {
        cout<<"\n\n";
        node *ptr=n1;
        //node *temp=ptr->next;
        node *temp;

        while (ptr!=NULL)
        {
            //cout<<"freeing node where data[not dup.] is:"<<ptr->data<<"\n";
            cout<<"freeing node["<<ptr<<"] where data is:"<<ptr->data<<"\n";
            temp=ptr;
            ptr=ptr->next;
            delete temp;
            nodecount-=1;
        }
        //cout<<"\n remaining nodes:"<<nodecount<<"\n";
        }
        
    }

    

    void peek_front()
    {
        if(!is__empty())
        {
            cout << "front is:"<<front->data;
        }
        else
        {
            cout << "\nERROR:queue is empty";
        }
    }
    
    void peek_rear()
    {
        if(!is__empty())
        {
            cout << "front is:"<<front->data;
        }
        else
        {
            cout << "\nERROR:queue is empty";
        }
    }

    void help()
    {
        cout<<"\n\n===========================================\n";
        cout<<"1.)for push\n";
        cout<<"2.)pop\n";
        cout<<"3.)for insert at first\n";



        cout<<"===========================================\n\n";
    }

/*
    void operation(node *n1=top)
    {
        bool flag=true;
        help();
        int choice=8;
        
        while(choice)
        {
            showlink();
            cin>>choice;
            
            switch (choice)
            {
                
            case 1:
                if (!dry_run_full)
                {
                    cout << "enter number of node to create:" <<endl;
                    int k;
                    cin >> k;
                    if(dry_run)
                        createNodes(k);
                    else
                    {
                        createNodes(k,dry_run);
                    }
                }
                else
                {
                    createNodes();
                }
                
                
                
                break;
            
            case 2:
                freeAll(top);
                break;
            
            case 3:
                
                break;
            
            case 4:
                
                break;
            
            case 5:
                
                break;
            
            default:
                help();
                cout << "do you want to exit : ";
                char z;
                cin >> z;
                if (z=='y' || z=='Y')
                {
                    choice=0;
                }
                
                break;
            }
            
        }

    }

*/

int main(int argc, char const *argv[])
{
    int a=0;
    //operation();
    
    //top=insertingFirstNode();
    //system("clear") ;
    //deleteAtFirst();
    dequeue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();


    //peek();
    freeAll(front); 
    return 0;
}