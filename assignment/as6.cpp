//#include <iomanip>
//#include <ios>
#include<iostream>
using namespace std;


static int nodecount=0,nodecountverify=0,test=1;
static bool dry_run=true;
static bool dry_run_full=false;

struct  node
{
    public:
    node * prev;
    int data;
    node * next;
}


*head=NULL  
;
    // node * convertAddToNode()
    // {
        

    // }
/*
    node * findLocAddByAdd(node* loc,node *n1=head)
    {
        node *back;
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else if(n1==loc)
        {
            back=NULL;
        }
        else
        {
            while (n1!=loc)
            {
                back=n1;
                //temp=n1;
                n1=n1->next;
                
            }
            // if(n1==back)
            // {
            //     cout<<"\nvery bad\n";
            // }

            //temp=n1;
        }
        return back;

    }

*/
/* 
    node * findLocBack(node* loc,node *n1=head)
    {
        node *back;
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else if(n1==loc)
        {
            back=NULL;
        }
        else
        {
            back=n1->prev;
        }
        return back;
    }
 */

    node * findLocByData(int data=4,node *n1=head)
    {
        node *temp;
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else
        {
            while (n1->data!=data && n1->next!=NULL)
            {
                //back=n1;
                n1=n1->next;
                nodecountverify++;
            }
            if(n1->data==data && n1!=NULL )
            {
                temp=n1;
            }
            else
            {
                temp=NULL;
                cout<<"\nERROR:given data not found\n";
            }
        }
        return temp;
        
    }

    node *findLocByNumeEle(int num=4,node *n1=head)
    {
        node *temp;
        nodecountverify=0;
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else
        {
            while (nodecountverify<num)
            {
                //back=n1;
                temp=n1;
                n1=n1->next;
                nodecountverify++;
            }
        }
        return temp;
    }

    void deleteAtFirst(node *n1=head)
    {
        if(head==NULL)
        {
            cout<<"\nERROR:no node to delete \n";
        }
        else if(n1->next==NULL)
        {
            delete n1;
            head=NULL;
        }
        else
        {
            node *temp=n1;
            //n1=n1->prev;
            head=n1->next;
            head->prev=NULL;
            delete temp;
            nodecount--;
        }

    }

    void insertData(node *n1)
    {
        cin>>n1->data;
    }

    node * insertingAtFirstNode(node *n1=head)
    {
        node *temp=new node();
        if(n1==NULL)
        {
            cout<<"creating first node:";
            head=temp;
            //n1=new node;
            //n1=new node;
            //node* ptr = head;
            //insertData(ptr);
            insertData(temp);
            nodecount+=1;
            //head=n1;
        }
        else
        {
            node *ptr=new node();
            ptr=head;
            cout<<"inserting node at first, first node:";
            insertData(temp);
            temp->next=head;
            temp->prev=NULL;
            head->prev=temp;
            head=temp;
            nodecount++;
        }
        return n1;
    }

    void insertAtLast(node *n1=head)
    {
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else
        {
            while(n1->next!=NULL)
            {
                n1=n1->next;
            }
            cout<<"inserting node at last node:";
            node *temp=new node();
            insertData(temp);
            n1->next=temp;
            temp->prev=n1;
            temp->next=NULL;
            //n1->next=new node;
            //n1=new node;
            //n1=n1->next;
            //insertData(n1);
            nodecount+=1;
        }
    }

    void deleteAtLast(node *n1=head)
    {
        node* temp=NULL;
        if(n1==NULL)
        {
            cout<<"\nERROR:linklist is empty\n";
        }
        else if(n1->next==NULL)
        {
            delete n1;
            nodecount-=1;
        }
        else
        {
            while(n1->next!=NULL)
            {
                temp=n1;
                n1=n1->next;
            }
            temp->next=NULL;
            delete n1;
            //n1->next=new node;
            //n1=new node;
            nodecount-=1;
        }
    }
    
    void deleteAtMid(node *ptr=head)
    {
        
        node *ptr2;
        ptr2=ptr->next;
        node *temp =ptr;
        ptr=ptr->prev;
        //temp=ptr->next;
        ptr->next=ptr2;
        ptr2->prev=ptr;

        delete temp;
        nodecount--;
    }

    void insertAtMidAfterNode(node *n1=head)
    {
        node *temp=new node();
        temp->next=n1->next;
        temp->prev=n1;
        n1->next=temp;
        //n1=n1->next;
        //node *temp=n1->next;
        //n1->next=new node;
        n1=temp->next;
        cout <<"inserting node at mid :" << endl;
        insertData(temp);
        n1->prev=temp;
        nodecount++;
    }


    void insertAfterNode(int num=4,node *n1=head)
    {
        if(nodecount<num)
        {
            cout<<"\nERROR:given node not found or given node out of bounds \n";
        }
        else if(num==nodecount)
        {
            insertAtLast();
        }
        else if(num<2)
        {
            head=insertingAtFirstNode();
        }
        else
        {
            node *loc=findLocByNumeEle(num);
            if(loc!=NULL)
            {
                //node *loc=findLocByNumeEle(num);
                insertAtMidAfterNode(loc);
                //insertAtMid(findLocByNumeEle(num));
                
            }
            // else 

            // loc=findLocByData(6);
            // if(loc!=NULL)
            // {
            //     insertAtMid(loc);//findLocByData
            // }
        }
    }

    void deleteAfterNode(int num=4,node *n1=head)
    {
        if(nodecount<num)
        {
            cout<<"\nERROR:given node not found or given node out of bounds \n";
        }
        else if(num==nodecount && num!=1)
        {
            deleteAtLast();
        }
        else if (num<2)
        {
            deleteAtFirst();
        }
        else
        {
            node *loc=findLocByNumeEle(num,head);
            if(loc!=NULL)
            {
                
                // node *loc=findLocByNumeEle(num);
                deleteAtMid(loc);
                //insertAfterNode(findLocByNumeEle(num));
                
            }
            // else 

            // loc=findLocByData(6);
            // if(loc!=NULL)
            // {
            //     insertAtMid(loc);//findLocByData
            // }
        }
    }

    void insertAtFirst()
    {

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
            if(flag1)
            {
                ptr->data=test++;
            }
            else
            {
                //cin>>ptr->data;
                insertData(ptr);
            }
            
            ptr=ptr->next;
            i++;
            nodecount+=1;
        }
            if(flag1)
            {
                ptr->data=test++;
            }
            else
            {
                //cin>>ptr->data;
                insertData(ptr);
            }
        //ptr->data=test++;
        //cin>>ptr->data;
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
        //cout<<"\n remaining nodes:"<<nodecount<<"\n";
        }
        
    }

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
    insertingAtFirstNode();
    insertingAtFirstNode();
    insertingAtFirstNode();
    insertingAtFirstNode();
    showlink(head);
    insertAfterNode(3);
    showlink(head);
    deleteAfterNode(2);
    showlink();
    deleteAfterNode(2);
    showlink();
    deleteAfterNode(2);
    showlink();
    deleteAfterNode(1);
    showlink(head);
    deleteAfterNode(1);
    showlink(head);



    /* //node* head = NULL;
    //node* ptr = NULL;
    node* test,* test2 = NULL;

    //createNode(head);
    createNodes();
    
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
    //int res = str_inp1->compare(str_inp2); */
    freeAll(head); 
    return 0;
}