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


*top=NULL
;

    bool is__empty(node *n1=top)
    {
        return n1==NULL;
    }
    
    void pop()
    {
        if(is__empty(top))
        {
            cout<<"\nERROR:underflow \n";
        }
        else
        {
            node *temp=top;
            //n1=n1->next;
            top=top->next;
            cout<<"freeing node["<<temp<<"] where data is:"<<temp->data<<"\n";
            delete temp;
            nodecount--;
            showlink();
        }
        
    }

    void insertData(node *n1)
    {
        cout << "\ninsert data for top of stack:";
        cin>>n1->data;
    }

    void push()
    {
        node *temp=new node();
        if (!temp)
        {
            cout << "\nerror:stack overflow \n";
        }
        else
        {
            if(top==NULL)
            {
                ;
            }
            else
            {
                temp->next=top;
            }
            top=temp;
            insertData(top);
            nodecount+=1;
            showlink();
        }
    }


    void freeAll(node *n1=top)
    {
        if(n1==NULL)
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

    void showlink(node *n1=top)
    {
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else
        {

            cout<<"&top=\t";
            cout<<&top<<"\ntop=\t";
            cout<<top;
            cout<<"\n\t |  ";
            cout<<"\n\t |  ";
            cout<<"\n\t ^  ";
            node* ptr = top;
            cout<<"\n\t";
            ptr = top;
            while (ptr!=NULL)
            {
                cout<<"=====\t\t";
                ptr=ptr->next;
            }
            cout<<"=====\n\t";
            ptr = top;

            while (ptr!=NULL)
            {
                cout<<"|"<<ptr->data<<"|*|->\t\t";
                //cout<<"|"<<ptr->data<<"|"<<ptr->next<<"|->\t\t";
                ptr=ptr->next;
            }
            cout<<"NULL\n\t";
            ptr = top;
            while (ptr!=NULL)
            {
                cout<<"=====\t\t";
                ptr=ptr->next;
            }
            cout<<"=====\n";

            ptr = top;
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
    void peek()
    {
        cout << "top is:"<<top->data;
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
    pop();
    push();
    pop();
    pop();
    push();
    pop();
    push();
    push();
    peek();
    
    freeAll(top); 
    return 0;
}