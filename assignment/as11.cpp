//#include <iomanip>
//#include <ios>
#include <iostream>
#define SPACE 10
using namespace std;

static int nodecount = 0, nodecountverify = 0, test = 1;
static bool dry_run = true;
static bool dry_run_full = false;
static bool flag = true;

struct node
{
public:
    node *left;
    int data;
    node *right;
}
    *root = NULL;
void help()
{
    cout << "\n\n===========================================\n";
    cout << "1.)for create number of nodes\n";
    cout << "2.)for free all nodes\n";
    cout << "3.)for insert at first\n";

    cout << "===========================================\n\n";
}

int getTreeHeight(node *r)
{
    if (r == NULL)
    {
        return -1;
    }
    else
    {
        int lheight = getTreeHeight(r->left);
        int rheight = getTreeHeight(r->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

node *minValue(node *ptr2)
{
    // send right
    node *current = ptr2;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

node *maxValue(node *ptr2)
{
    // send left
    node *current = ptr2;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

bool search(node *ptr, int value)
{
    bool test = false;
    if (ptr->left != NULL)
    {
        search(ptr->left, value);
    }
    if (ptr->right != NULL)
    {
        search(ptr->right, value);
    }
    if (ptr->data == value)
    {
        cout << "\ndata found at [" << ptr << "] where data is:" << ptr->data << "\n";
        test = true;
    }
    return test;
}

/* void createtree(int data,node *ptr=root)
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


} */

int getBalanceFactor(node *ptr)
{
    if (ptr == NULL)
    {
        return -1;
    }
    else
    {
        return (getTreeHeight(ptr->left) - getTreeHeight(ptr->right));
    }
}

node *rightRotate(node *ptr1)
{
    // temp node pointer
    node *Node1 = ptr1->left;
    node *Node2 = Node1->right;

    // rotation
    Node1->right = ptr1;
    ptr1->left = Node2;

    return Node1;
}

node *leftRotate(node *ptr1)
{
    // temp node pointer
    node *Node1 = ptr1->right;
    node *Node2 = Node1->left;

    // rotation
    Node1->left = ptr1;
    ptr1->right = Node2;

    return Node1;
}

node *createTreeNodes(node *ptr, node *temp)
{

    if (ptr == NULL)
    {
        return temp;
    }
    if (temp->data < ptr->data)
    {
        ptr->left = createTreeNodes(ptr->left, temp);
    }
    else if (temp->data > ptr->data)
    {
        ptr->right = createTreeNodes(ptr->right, temp);
    }
    else
    {
        cout << "\nduplicate values not allowed\n";
        return ptr;
    }
    int bf = getBalanceFactor(ptr);
    if (bf > 1 && temp->data < ptr->left->data)
    {
        return rightRotate(ptr);
    }
    if (bf < -1 && temp->data > ptr->right->data)
    {
        return leftRotate(ptr);
    }
    if (bf > 1 && temp->data > ptr->left->data)
    {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }
    if (bf < -1 && temp->data < ptr->right->data)
    {
        ptr->right = leftRotate(ptr->right);
        return leftRotate(ptr);
    }

    return ptr;
}

struct node *deleteNode(node *ptr, int value = 17)
{
    if (ptr == NULL)
    {
        return ptr;
    }
    if (ptr->data > value)
    {
        ptr->left = deleteNode(ptr->left, value);
    }
    else if (ptr->data < value)
    {
        ptr->right = deleteNode(ptr->right, value);
    }
    else
    {
        if (ptr->left == NULL)
        {
            node *temp = ptr->right;
            delete ptr;
            return temp;
        }
        else if (ptr->right == NULL)
        {
            node *temp = ptr->left;
            delete ptr;
            return temp;
        }
        else
        {
            node *temp = minValue(ptr->right);
            ptr->data = temp->data;
            ptr->right = deleteNode(ptr->right, temp->data);
        }
    }
    int bf = getBalanceFactor(ptr);
    if (bf == 2 && getBalanceFactor(ptr->left) >= 0)
    {
        return rightRotate(ptr);
    }
    if (bf == -2 && getBalanceFactor(ptr->right) <= 0)
    {
        return leftRotate(ptr);
    }
    if (bf == 2 && getBalanceFactor(ptr->left) == -1)
    {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }
    if (bf == -2 && getBalanceFactor(ptr->right) == 1)
    {
        ptr->right = leftRotate(ptr->right);
        return leftRotate(ptr);
    }
    return ptr;
}

void print2D(node *r, int space)
{
    if (r == NULL) // Base case  1
        return;
    space += SPACE;           // Increase distance between levels   2
    print2D(r->right, space); // Process right child first 3
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5
        cout << " ";                    // 5.1
    cout << r->data << "\n";            // 6
    print2D(r->left, space);            // Process left child  7
}

void freetree(node *ptr = root)
{
    int i = 0;
    // node *tempRoot=ptr;
    if (ptr == NULL && i == 0)
    {
        cout << "\ntree don't have any node\n";
    }
    else
    {
        if (ptr->left != NULL)
        {
            freetree(ptr->left);
        }
        if (ptr->right != NULL)
        {
            freetree(ptr->right);
        }
        cout << "\nfreeing node[" << ptr << "] where data is:" << ptr->data << "\n";
        delete ptr;
    }
}

void insert(int data)
{
    node *temp = new node();
    temp->data = data;
    root = createTreeNodes(root, temp);
}

void deletenodes(int data)
{
    root = deleteNode(root, data);
}

/*  */

int main(int argc, char const *argv[])
{
    insert(1);
    insert(2);

    insert(3);
    insert(4);
    insert(5);
    insert(6);
    print2D(root, 5);
    deletenodes(6);
    print2D(root, 5);
    deletenodes(5);
    print2D(root, 5);
    // deletenodes(4);
    // insert(3);
    print2D(root, 5);
    cout << "tree hieght is:" << getTreeHeight(root);
    freetree(root);
    return 0;
}