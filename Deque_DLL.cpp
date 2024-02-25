#include<iostream>
using namespace std;
#define UNDERFLOW 1

// Deque with Doubly Linkly List
struct node
{
    node *prev;
    int item;
    node *next;
};
class Deque_DLL
{
    private:
        node *front;
        node *rear;
    public:
        Deque_DLL();
        void InsertAtFirst(int);
        void InsertAtlast(int);
        void deleteAtFront();
        void deleteAtLast();
        int getFirst();
        int getLast();
        bool isEmpty();
        ~Deque_DLL();

        // Define a copy construtor to implement deep copy
        
        // Define a copy assignment operator to implement deep copy

};

Deque_DLL::Deque_DLL()
{
    front = NULL;
    rear = NULL;
}
void Deque_DLL::InsertAtFirst(int data)
{
    node*n = new node;
    n->next = NULL;
    n->prev = NULL;
    n->item = data;

    //list is empty
    if(front== NULL )
    {
        front = n;
        rear = n;
    }
    else
    {
        n->next = front;
        front ->prev = n;
        front = front->prev;
    }
}
void Deque_DLL::InsertAtlast(int data)
{
    // prepare a new node
    node*n = new node;
    n->next = NULL;
    n->prev = NULL;
    n->item = data;
    //list is empty
    if( rear== NULL )
    {
        front = n;
        rear = n;
    }
    else
    {
        rear->next = n;
        n->prev = rear;
        rear = rear->next;
    }
    
}
void Deque_DLL::deleteAtFront()
{
    if(isEmpty())
        cout<<"List is empty";
    else if(front == rear )
    {
        delete front;
        front = NULL;
        rear = NULL;
    }
    else
    {
    front = front->next;
    delete front->prev;
    front -> prev = NULL;
    }
    
}
void Deque_DLL::deleteAtLast()
{
    if(isEmpty())
        cout<<"List is empty";
    else if(front == rear )
    {
        delete front;
        front = NULL;
        rear = NULL;
    }
    else
    {
        rear = rear->prev;
        delete rear->next;
        rear->next = NULL;
    }
    
}
int Deque_DLL::getFirst()
{
    if(front==NULL)
        throw UNDERFLOW ;
    return front->item;
}
int Deque_DLL::getLast()
{
    if(rear==NULL)
        throw UNDERFLOW ;
    return rear->item;
}
bool Deque_DLL::isEmpty()
{
    if(front==rear && front==NULL && rear == NULL)
        return true;
    else 
        return false;
}

Deque_DLL::~Deque_DLL()
{
    node*temp = front;
    while(temp!=NULL)
    {
        node*current = temp;
        temp= temp->next;
        delete current; 
    }
    front=NULL;
    rear = NULL;
}

int main()
{
    Deque_DLL d1;
  d1.InsertAtFirst(5);
    d1.InsertAtFirst(10);

    // Inserting elements at the end
    d1.InsertAtlast(15);
    d1.InsertAtlast(20);

    // Deleting element from the front
    d1.deleteAtLast();
    d1.deleteAtLast();
    try{
    int a= d1.getFirst();
    cout<<a<<endl;
    }
    catch (int e)
    {
        if(e==UNDERFLOW)
            cout<< "list is empty"<<endl;
    }
    try{
          cout<<d1.getLast()<<endl;
    }
    catch(int e)
    {
        if(e==UNDERFLOW)
            cout<< "list is empty"<<endl;;
    }
  
    cout<< d1.isEmpty();
    return 0;
}
