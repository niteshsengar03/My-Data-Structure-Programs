#include<iostream>
using namespace std;
#define EMPTY_QUEUE 1

// Priority Queue using Singly Link List
struct node
{
    int priorityNo;
    int item;
    node *next;
};

class priorityQueue
{
    private:
        node *start;
    public:
        priorityQueue();
        void Insertion(int , int);
        void Delete();
        int getItem();
        int getHighestPriority();
        ~priorityQueue();
        bool isEmpty();
        
        //define a copy constructor to implement deep copy
        // define a copy assignment operator to implement deep copy
};

priorityQueue::priorityQueue()
{
    start = NULL;
}
void priorityQueue:: Insertion(int priority, int data)
{
    // prepare node 
    node *n = new node;
    n->priorityNo = priority;
    n->item = data;

    node *temp;
    // list is empty or node is adding in first (jb already list mein kuch nodes hai)
    if(start== NULL || start->priorityNo < n->priorityNo)
    {
        n->next = start;
        start = n;
    }
    else 
    {
        temp = start;
        while(temp->next!=NULL)
        {
            if(temp->next->priorityNo < n->priorityNo)
                break;
            temp= temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}
void  priorityQueue::Delete()
{
    node *t;
    if(start)
    {
        t = start;
        start = start->next;
        delete t;
    }
}
int priorityQueue::getItem()
{
    if(start)
        return start->item;
    throw EMPTY_QUEUE;
}
int priorityQueue::getHighestPriority()
{
    if(start)
        return start->priorityNo;
    throw EMPTY_QUEUE;
}
priorityQueue::~priorityQueue()
{
    while (start)
    {
        Delete();
    }
}
bool priorityQueue::isEmpty()
{
    if(start == NULL)
        return true;
    else 
        return false;
}
int main()
{
    priorityQueue q1;
    q1.Insertion(10,10);
    q1.Insertion(12,12);
    q1.Insertion(2,2);
    q1.Insertion(11,11);
    q1.Delete();
    try{
    cout<<q1.getItem()<<endl;
    }
    catch(int  e)
    {
        if(e)
        cout<<"Queue is empty";
    }
    return 0;
}
