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


*head=NULL  
;
    void showlink(node *n1=head)
    {
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else
        {

            cout<<"&head=\t";
            cout<<&head<<"\nhead=\t";
            cout<<head;
            cout<<"\n\t |  ";
            cout<<"\n\t |  ";
            cout<<"\n\t ^  ";
            node* ptr = head;
            cout<<"\n\t";
            ptr = head;
            while (ptr!=NULL)
            {
                cout<<"=====\t\t";
                ptr=ptr->next;
            }
            cout<<"=====\n\t";
            ptr = head;

            while (ptr!=NULL)
            {
                cout<<"|"<<ptr->data<<"|*|->\t\t";
                //cout<<"|"<<ptr->data<<"|"<<ptr->next<<"|->\t\t";
                ptr=ptr->next;
            }
            cout<<"NULL\n\t";
            ptr = head;
            while (ptr!=NULL)
            {
                cout<<"=====\t\t";
                ptr=ptr->next;
            }
            cout<<"=====\n";

            ptr = head;
            cout<<"\t";
            while (ptr!=NULL)
            {
                cout<<ptr<<"  ";
                ptr=ptr->next;
            }
            cout<<"\n\t";

            // ptr = head;
            // cout<<"";
            // while (ptr!=NULL)
            // {
            //     cout<<&ptr<<"  ";
            //     ptr=ptr->next;
            // }
            // cout<<"\n\t";

        }
        //cout<<"\n\n num of node:"<<nodecount<<"\n";
   }

     void insertData(node *n1,bool flag1=true)
    {
        if(flag1)
        {
            n1->data=test++;
        }
        else
        {
            cin>>n1->data;
        }
        
    }

    

    node *deleteDataAt(node *n1=head,int num=4)
    {
        node *temp;
        
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else if (num==1 && n1->next==NULL)
        {
            delete n1;
            cout<<"freeing node["<<n1<<"] where data is:"<<n1->data<<"\n";
            head=NULL;
        }
        else if (num==1)
        {
            head=n1->next;
            delete n1;
            cout<<"freeing node["<<n1<<"] where data is:"<<n1->data<<"\n";
            
        }
        else
        {
            if(nodecountverify==num-1)
            {
                temp=n1;
                n1=n1->next;
                cout<<"freeing node["<<temp<<"] where data is:"<<temp->data<<"\n";
                delete temp;
                nodecountverify=0;
                return n1;
            }
            else
            {
                nodecountverify++;
                n1->next=deleteDataAt(n1->next,num);
            }
        }
        return n1;
    }

    node *deleteByData(node *n1=head,int data=4)
    {
        node *temp;
        
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else if (nodecountverify==0 && n1->next==NULL && n1->data==data)
        {
            cout<<"freeing node["<<n1<<"] where data is:"<<n1->data<<"\n";
            delete n1;
            head=NULL;
        }
        else if (nodecountverify==0 && n1->data==data)
        {
            head=n1->next;
            cout<<"freeing node["<<n1<<"] where data is:"<<n1->data<<"\n";
            delete n1;
        }
        else
        {
            if(nodecountverify>0 && n1->data==data)
            {
                temp=n1;
                n1=n1->next;
                cout<<"freeing node["<<temp<<"] where data is:"<<temp->data<<"\n";
                delete temp;
                nodecountverify=0;
                return n1;
            }
            else
            {
                nodecountverify++;
                n1->next=deleteByData(n1->next,data);
            }
        }
        return n1;
    }

    node *insertDataAt(node *n1=head,int num=4,bool flag1=true)
    {
        node *temp=new node;
        
        if(n1==NULL && num==0)
        {
            insertData(temp);
            head=temp;
        }
        else if (num==1)
        {
            temp->next=n1;
            head=temp;
            cout <<"\ninserting "<<nodecountverify+1<<" node:" ;
            insertData(temp);
            cout <<"\n \n \n" ;
            nodecount+=1;
        }
        else
        {
            if(nodecountverify==num-1)
            {
                
                cout <<"\ninserting "<<nodecountverify+1<<" node:" ;
                insertData(temp);
                nodecountverify=0;
                temp->next=n1->next;
                n1->next=temp;
                nodecount+=1;
                cout <<"\n \n \n" ;
                return n1;
            }
            else
            {
                nodecountverify++;
                n1->next=insertDataAt(n1->next,num);
            }
        }
        return n1;
    }

    node *insertAfterData(node *n1=head,int data=4)
    {
        node *temp=new node;
        
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else
        {
            if(n1->data=data)
            {
                cout <<"\ninserting "<<nodecountverify+2<<" node:" ;
                insertData(temp);
                nodecountverify=0;
                temp->next=n1->next;
                n1->next=temp;
                nodecount+=1;
                cout <<"\n \n \n" ;
                return n1;
            }
            else
            {
                nodecountverify++;
                n1->next=insertDataAt(n1->next,data);
            }
        }
        return n1;
    }

    //void createNode(node *n1,int num=5)
    //void createNodes(bool flag1=true,int num=5)
    void createNodes(int num=5,bool flag1=true)
    {
        int i=1;
        head=new node;
        node* ptr = head;
        
        while (i<num)
        {
            ptr->next=new node;
            insertData(ptr,flag1);
            ptr=ptr->next;
            i++;
            nodecount+=1;
        }
        insertData(ptr,flag1);
        nodecount+=1;
        cout<<"\n\n"<<nodecount<<" nodes created \n\n";
    }

    void freeAll(node *n1=head)
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
        head=NULL;
        //cout<<"\n remaining nodes:"<<nodecount<<"\n";
        }
        
    }

    

    

    void help()
    {
        cout<<"\n\n===========================================\n";
        cout<<"1.)for create number of nodes\n";
        cout<<"2.)for free all nodes\n";
        cout<<"3.)for insert at first\n";



        cout<<"===========================================\n\n";
    }

    void operation(node *n1=head)
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
                        createNodes(k,false);
                    }
                }
                else
                {
                    createNodes();
                }
                
                
                
                break;
            
            case 2:
                freeAll(head);
                break;
            
            case 3:
                /* code */
                break;
            
            case 4:
                /* code */
                break;
            
            case 5:
                /* code */
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


int main(int argc, char const *argv[])
{
    //operation();
    createNodes();
    showlink();
    nodecountverify=0;
    insertDataAt(head,1);
    showlink();
    deleteDataAt(head,2);
    showlink();
    deleteByData(head,4);
    showlink();
    deleteByData(head,5);
    //insertAfterData(head,1);
    showlink();

    //showlink();

    //showlink();
    //node *temp=0x55555556bf10;
    //deleteAtMid(temp);
    freeAll(head);



    /* //node* head = NULL;
    //node* ptr = NULL;
    node* test,* test2 = NULL;

    //createNode(head);
    createNodes();
    //showlink(head);
    //head=insertingFirstNode();
    //showlink();
    //insertAtLast();
    
    //insertAfterNode(3);
    //getchar();

    //system("clear") ;
    //deleteAtLast();
    //deleteAfterNode(2);
    //deleteAtFirst();
    showlink();
    //cin>>test;
    //test="0x561723c73ed0";
    test=findLocByNumeEle(3)->next;
    cout<<"\n\nadd of num 3 node:"<<test<<endl;
    test2=findLocBack(test);
    cout<<"add of num 3 back node:"<<test2;
    node *str_inp1=head;
    string str_inp2("0x5577ef130ef0");
    //cin>>str_inp2;
    //int res = str_inp1->compare(str_inp2);
    freeAll(head); */
    return 0;
}