//#include <iomanip>
//#include <ios>
#include<iostream>
using namespace std;


static int nodecount=0,nodecountverify=1,test=1;

struct  node
{
    public:
    int data;
    node * next;
}


*head=NULL  
;
    node * convertAddToNode()
    {
        

    }

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
            // if(n1==back)
            // {
            //     cout<<"\nvery bad\n";
            // }

            //temp=n1;
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
        }
        else
        {
            node *temp=n1;
            //n1=n1->next;
            head=n1->next;
            delete temp;
            nodecount--;
        }

    }

    void insertData(node *n1)
    {
        cin>>n1->data;
    }

    node * insertingFirstNode(node *n1=head)
    {
        if(n1==NULL)
        {
            cout<<"creating first node:";
            //n1=new node;
            n1=new node;
            //node* ptr = head;
            //insertData(ptr);
            insertData(n1);
            nodecount+=1;
            head=n1;
        }
        else
        {
            cout<<"\nERROR:linklist already have a node\n";
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
            n1->next=new node;
            //n1=new node;
            n1=n1->next;
            insertData(n1);
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
    
    void deleteAtMid(node *back=head)
    {
        node *temp=back->next;
        back->next=temp->next;
        //n1=n1->next;
        
        delete temp;
        nodecount--;
    }

    void insertAtMid(node *n1=head)
    {
        n1=n1->next;
        node *temp=n1->next;
        n1->next=new node;
        n1=n1->next;
        insertData(n1);
        n1->next=temp;
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
            head=insertingFirstNode();
        }
        else
        {
            node *loc=findLocByNumeEle(num);
            if(loc!=NULL)
            {
                //node *loc=findLocByNumeEle(num);
                insertAtMid(loc);
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
        else if(num==nodecount)
        {
            deleteAtLast();
        }

        else
        {
            node *back=NULL;
            node *loc=findLocByNumeEle(num,head);
            if(loc!=NULL)
            {
                
                // node *loc=findLocByNumeEle(num);
                deleteAtMid(loc);
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
        cout<<"\n\n===========================================";
        cout<<"1.)for create number of nodes\n";
        cout<<"2.)for free all nodes\n";
        cout<<"3.)for insert at first\n";



        cout<<"===========================================\n\n";
    }

    void operation()
    {
        bool flag=true;
        while(flag)
        {

            flag=false;
        }

    }


int main(int argc, char const *argv[])
{
    //node* head = NULL;
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
    freeAll(head);
    return 0;
}