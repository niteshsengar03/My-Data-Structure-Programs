#include<iostream>
using namespace std;
#define TREE_IS_EMPTY 1
#define DATA_NOT_FOUND 2

struct node
{
    int item;
    node *left;
    node *right;
};

class BST
{
    private:
        void recInorder(node*);
        void recPreorder(node*);
        void recPostorder(node*);
        void insertUsingRecursion(node*&,int);
        node* recSearch(node*,int);
        node *root;
    public:
         
        BST();
        ~BST();
        bool treeIsEmpty();
        void insert(int);
        void insertUsingrec(int);
        
        void inorder();
        void preorder();
        void postorder();
        node* Search(int);
        void del(int);

        //define a copy constructor to implement deep copy

        //define a copy assignment operator to implment deep copy

        
};
BST::~BST()
{
    while(root)
        del(root->item);
}
BST::BST()
{
    root = NULL;
}
bool BST::treeIsEmpty()
{
    if (root == NULL)
        return true;
    else 
    return false;
}
void BST::insert(int data)
{
    // prepare a node
    node *n = new node;
    n->item = data;
    n->left = NULL;
    n->right = NULL;
    if(root == NULL)
        root = n;
    
    else{
        node* temp = root;
        if(temp->left == NULL && temp->right == NULL )
        {
            if(n->item<temp->item)
                temp->left = n;
            else if(n->item > temp->item)
                temp->right = n;
                
        }
        else
        {
            bool flag = true;
            while(flag)
            {
                if(n->item < temp->item)
                {
                    if(temp->left == NULL)
                    {
                        temp->left = n;
                        flag = false;
                    }
                    else {
                        temp = temp->left;
                        
                    }
                }

                else if(n->item > temp->item)
                {
                    if(temp->right == NULL)
                    {
                        temp->right = n;
                        flag= false;
                    }
                    else {
                        temp = temp->right;
                    
                    }
                }
            }
        }
    }
    
}
void BST::insertUsingrec(int data)
{
    insertUsingRecursion(root,data);
}
void BST::insertUsingRecursion(node*&temp,int data)
{
     // prepare a node
     if(temp==NULL)
    {
    temp = new node;
    temp->item = data;
    temp->left = NULL;
    temp->right = NULL;
    }
    else
    {
        if(temp->item<data)
            insertUsingRecursion(temp->right,data);
        else if(temp->item>data)
            insertUsingRecursion(temp->left,data);
    }
}
void BST::inorder()
{
    recInorder(root);
}
void BST::recInorder(node*temp)
{
    
    if(temp)
    {
        recInorder(temp->left);
        cout<<temp->item<<" ";
        recInorder(temp->right);
    }
}

void BST::preorder()
{
    recPreorder(root);
}
void BST::recPreorder(node*temp)
{
    if(temp)
    {
        cout<<temp->item<<" ";
        recPreorder(temp->left);
        recPreorder(temp->right);
    }
}

void BST::postorder()
{
    recPostorder(root);
}
void BST::recPostorder(node*temp)
{
    if(temp)
    {
        recPostorder(temp->left);
        recPostorder(temp->right);
        cout<<temp->item<<" ";
    }
}


node*BST::Search(int data)
{
    return recSearch(root,data);
}
node* BST::recSearch(node*temp,int data)
{

    if(temp == NULL)
        return NULL;
    if(temp->item == data )
        return temp;
    if(data < temp->item)
    {
        return recSearch(temp->left,data);
    }
    else{
        return recSearch(temp->right,data);
    }
}
// no child 
// one child 
// two child
void BST::del(int data)
{
    node *ptr, *parrentptr;

    if(root==NULL)
        throw TREE_IS_EMPTY;
    // search the node and point it with ptr
    // and point parrentptr to its parrent node
    parrentptr = NULL;
    ptr = root;
    while(ptr)
    {
        if(ptr->item == data)
            break;
        else if(ptr->item < data)
        {
            parrentptr = ptr;
            ptr = ptr->right;
        }
        else if(ptr->item > data)
        {
            parrentptr = ptr;
            ptr = ptr->left;
        }
    }
    if(ptr==NULL)
        throw DATA_NOT_FOUND;
    // root node to be deleted
    if(parrentptr == NULL && ptr!=NULL)
    {
        // no child
        if(ptr->left==NULL && ptr->right==NULL)
        {
            delete ptr;
            root = NULL;
        }
        //two child
        else if(ptr->left && ptr->right)
        {
            node *suc,*parrentSuccesor;
            suc = ptr->right;
            parrentSuccesor=ptr;
            while(suc->left!=NULL)
            {
                parrentSuccesor = suc;
                suc = suc->left;
            }
            ptr->item = suc->item;
            //now delet the successor
            if(suc==parrentSuccesor->left)
                parrentSuccesor->left=suc->right;
            else
                parrentSuccesor->right=suc->right;
            delete suc;
        }
        // one child
        else 
        {
            if(ptr->left)
                root = ptr ->left;
            else
                root = ptr ->right;
            delete ptr;
        }
    }
    // root to be deleted is not a root node
    else
    {
        //no child
        if(ptr->left==NULL && ptr->right==NULL)
        {
            if(ptr==parrentptr->left){
                parrentptr->left = NULL;
                delete ptr;
            }
            else{
                parrentptr->right = NULL;
                delete ptr;

            }
        }
        // two child
        else if(ptr->left && ptr->right)
        {
            node *suc,*parrentSuccesor;
            suc = ptr->right;
            parrentSuccesor=ptr;
            while(suc->left!=NULL)
            {
                parrentSuccesor = suc;
                suc = suc->left;
            }
            ptr->item = suc->item;
            //now delet the successor
            if(suc==parrentSuccesor->left)
                parrentSuccesor->left=suc->right;
            else
                parrentSuccesor->right=suc->right;
            delete suc;
        }

        // one child 
        else
        {
             if(ptr==parrentptr->left){
               if(ptr->left)
                    parrentptr->left = ptr->left;
                else
                    parrentptr->left = ptr->right;
                delete ptr;
            }
            else{
                if(ptr->left)
                    parrentptr->right = ptr->left;
                else
                    parrentptr->right = ptr->right;
                delete ptr;
            }
        }
    }
}

int main()
{
    BST b1,b2;
  
    b1.insert(20);
    b1.insert(10);
    b1.insert(5);
    b1.insert(15);
    b1.insert(30);
    b1.insert(25);
    b1.insert(32);
    // b1.preorder(b1.root);
    // cout<<endl;
    b1.inorder();
    cout<<"olk"<<endl;
    // b2.insertUsingrec(20);
    // b2.insertUsingrec(10);
    // b2.insertUsingrec(5);
    // b2.insertUsingrec(15);
    // b2.insertUsingrec(30);
    // b2.insertUsingrec(25);
    // b2.insertUsingrec(32);
    // cout<<endl;
    // b2.inorder();
    // cout<<endl;
    cout<<b1.Search(20)<<endl;
    cout<<b1.Search(21)<<endl;
    cout<<b1.Search(30)<<endl;
    cout<<b1.Search(39)<<endl;
    return 0;
}