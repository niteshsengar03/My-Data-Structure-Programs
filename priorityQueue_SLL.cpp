#include<iostream>
using namespace std;

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
        int count = 0;
    public:
        priorityQueue();
        void Insertion(int , int);
};

priorityQueue::priorityQueue()
{
    // if(start!=NULL)
    //     delete start;
    start = NULL;
}
void priorityQueue:: Insertion(int priority, int data)
{
    // prepare node 
    node *n = new node;
    n->priorityNo = priority;
    n->item = data;
    n->next = NULL;

    node *temp1 = start;
    // list is empty
    if(count == 0)
    {
        n->next = start;
        start = n;
        count++;
    }
    // only one node is there
    else if(count==1)
    {
        if(temp1->priorityNo < n->priorityNo)
        {
            n->next = temp1;
            start = n;
            count++;
        }
        else
        {
            temp1->next = n;
            count++;
        }
    }
    ///Two node are present
    // else if(count==2)
    // {
    // while(temp1->next!=0)
    // {
    //     if(temp1->priorityNo < n->priorityNo)
    //         break;
    //     else
    //         temp1 = temp1->next;
    // }  
    // if(temp1 == start)
    // {
    //     n->next = temp1;
    //     start = n;
    // }  
    // else if(temp1->next==NULL)
    // {
    //     temp1->next = n;
    // }
    // }
    else if(count>1)
    {
      temp1 = start;
       int no =0;
        while(temp1->next!=NULL)
        {
            if(temp1->next->priorityNo<n->priorityNo)
                break;
            else
          {
             temp1 = temp1->next;
            no++;
          }
           
        }
        //insertion at first
        if(temp1->priorityNo<n->priorityNo)
        {
        n->next = start;
        start = n;
        count++;
        no++;
        }
        //insertion at last
        else if(temp1->next==NULL)
        {
            temp1->next = n;
            count++;
            no++;
        }
        else
        {
            n->next = temp1->next;
            temp1->next = n;
            count++;
            no++;
        }
    }
}

int main()
{
    priorityQueue q1;
    q1.Insertion(10,10);
    q1.Insertion(12,12);
    q1.Insertion(2,2);
    q1.Insertion(11,11);

    return 0;
}