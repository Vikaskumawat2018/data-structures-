#include<iostream>
using namespace std;

struct  node
{
    public:
    int data;
    node * next;
};
    /*
    int * findloc(node * head)
    {
        while (head->next==NULL)
        {
           
        } 
    }
    */

   void showlink(node *n1)
   {
       cout<<"\n\nprinting the list\n\n";
       while (n1!=NULL)
       {
           cout<<n1->data<<"\n";
           n1=n1->next;
       }
       cout<<"X\n";
   }


int main(int argc, char const *argv[])
{
     node* head = NULL;
     node* ptr = NULL;
     node* first=new node;
     node* second=new node;
     head=first;
     first->next=second;
     second->next=NULL;
    cout<<"&head:"<<&head<<"\n";
    cout<<"head:"<<head<<"\n";
    cout<<"head->next:"<<head->next<<"\n";
    //cout<<"*head"<<*head<<"\n";
    cout<<"&first:"<<&first<<"\n";
    cout<<"first:"<<first<<"\n";
    cout<<"first->next:"<<first->next<<"\n";
    cout<<"&second:"<<&second<<"\n";
    cout<<"second:"<<second<<"\n";
    cout<<"second->next:"<<second->next<<"\n";


    // head=new node;
    // ptr=head;
    // cin>>ptr->data;
    // ptr->next=new node;
    // ptr=ptr->next;
    // cin>>ptr->data;
    // ptr->next=new node;
    // ptr=ptr->next;
    // cin>>ptr->data;
    // ptr->next=NULL;
    // showlink(head);
    return 0;
}
