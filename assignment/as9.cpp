//#include <iomanip>
//#include <ios>
#include<iostream>
using namespace std;


static int nodecount=0,nodecountverify=0,test=1;
static bool dry_run=true;
static bool dry_run_full=false;
static bool flag=true;

struct  node
{
    public:
    node * left;
    int data;
    node * right;
}
*root=NULL  
;

    void createtree(int data,node *ptr=root)
    {
        flag=true;
        node *temp=new node();
        temp->data=data;
        if(root==NULL)
        {
            root=temp;
            cout<<"\ncreating root node["<<root<<"] where data is:"<<root->data<<"\n";
            flag=false;
        }
        while (flag)
        {
            if (ptr->data==data)
            {
                cout << "ERROR:duplicate data" << endl;
                flag=false;
                delete temp;
            }
            else if (ptr->data>data)
            {
                if(ptr->left==NULL)
                {
                    cout<<"\ncreating new node["<<temp<<"] where data is:"<<temp->data<<"\n";
                    ptr->left=temp;
                    flag=false;
                }
                else
                {
                    ptr=ptr->left;
                }
                
            }
            else
            {
                if(ptr->right==NULL)
                {
                    cout<<"\ncreating new node["<<temp<<"] where data is:"<<temp->data<<"\n";
                    ptr->right=temp;
                    flag=false;
                }
                else
                {
                    ptr=ptr->right;
                }
            }
            
        }

        
    }

    void preOrder(node *ptr=root)
    {
        if (ptr==NULL)
        {
            return;
        }
        
        cout<<ptr->data<<"\t";
        if (ptr->left!=NULL)
        {
            preOrder(ptr->left);
        }

        if (ptr->right!=NULL)
        {
            preOrder(ptr->right);
        }
    }

    void inOrder(node *ptr=root)
    {
        if (ptr==NULL)
        {
            return;
        }
        if (ptr->left!=NULL)
        {
            inOrder(ptr->left);
        }
        cout<<ptr->data<<"\t";
        if (ptr->right!=NULL)
        {
            inOrder(ptr->right);
        }
    }

    void postOrder(node *ptr=root)
    {
        if (ptr==NULL)
        {
            return;
        }
        if (ptr->left!=NULL)
        {
            postOrder(ptr->left);
        }
        if (ptr->right!=NULL)
        {
            postOrder(ptr->right);
        }
        cout<<ptr->data<<"\t";
    }

    void freetree(node *ptr=root)
    {
        //node *tempRoot=ptr;
        if (ptr->left!=NULL)
        {
            freetree(ptr->left);
        }
        if (ptr->right!=NULL)
        {
            freetree(ptr->right);
        }
        cout<<"\nfreeing node["<<ptr<<"] where data is:"<<ptr->data<<"\n";
        delete ptr;
    }

    void help()
    {
        cout<<"\n\n===========================================\n";
        cout<<"1.)for create number of nodes\n";
        cout<<"2.)for free all nodes\n";
        cout<<"3.)for insert at first\n";



        cout<<"===========================================\n\n";
    }

   /*  */

int main(int argc, char const *argv[])
{
    createtree(10);
    createtree(8);
    createtree(15);
    createtree(7);
    createtree(9);
    createtree(13);
    createtree(17);
    cout << "\n\ninOrder traverce :";
    preOrder();
    cout << "\n\n";
    cout << "\n\npreOrder traverce :";
    inOrder();
    cout << "\n\n";
    cout << "\n\npostOrder traverce :";
    postOrder();
    cout << "\n\n";
    freetree(root); 
    return 0;
}