//#include <iomanip>
//#include <ios>
#include<iostream>
#define SPACE 10
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


    node* minValue(node *ptr2)
    {
        //send right
        node * current=ptr2;
        while (current->left!=NULL)
        {
            current=current->left;
        }
        return current;
    }

    node* maxValue(node *ptr2)
    {
        //send left
        node * current=ptr2;
        while (current->right!=NULL)
        {
            current=current->right;
        }
        return current;
    }

    bool search(node* ptr,int value)
    {
        bool test=false;
        if (ptr->left!=NULL)
        {
            search(ptr->left,value);
        }
        if (ptr->right!=NULL)
        {
            search(ptr->right,value);
        }
        if(ptr->data==value)
        {
            cout<<"\ndata found at ["<<ptr<<"] where data is:"<<ptr->data<<"\n";
            test=true;
        }
        return test;
    }

    struct node * deleteNode(node* ptr,int value=17)
    {
        if (ptr==NULL)
        {
            return ptr;
        }
        if (ptr->data>value)
        {
            ptr->left=deleteNode(ptr->left,value);   
        }
        else if (ptr->data< value)
        {
            ptr->right=deleteNode(ptr->right,value);
        }
        else
        {
            if (ptr->left==NULL)
            {
                node * temp=ptr->right;
                delete ptr;
                return temp;
            }
            else if (ptr->right==NULL)
            {
                node * temp=ptr->left;
                delete ptr;
                return temp;
            }
            else
            {
                node * temp=minValue(ptr->right);
                ptr->data=temp->data;
                ptr->right=deleteNode(ptr->right,temp->data);
            }
            
        }
        return ptr;
    }

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

    void print2D( node* r, int space) {
    if (r == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> data << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
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
    csearch(root,17);
    print2D(root,5);
    deleteNode(root,10);
    print2D(root,5);
    freetree(root); 
    return 0;
}