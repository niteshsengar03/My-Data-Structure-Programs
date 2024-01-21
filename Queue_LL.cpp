#include<iostream>
using namespace std;
 
 struct node
 {
    node *next;
    int item;
 };

class Queue
{
    private:
        node *front;
        node *rear;
    public:

        Queue();
        void Insertion(int);
        void Deletion();
        void viewFront();
        void viewRear();
        void countElements();
};

Queue::Queue()
{
        front = NULL;
        rear = NULL;
}
void Queue::Insertion(int data)
{
    if(front == NULL && rear == NULL)
    {
        node *n;
        n = new node;
        n->item = data;
        n->next = NULL;
        front = n;
        rear = n;
    }
    else
    {
        node *n;
        n = new node;
        n->item =data;
        n ->next = NULL;
        rear->next = n;
        rear = n;
    }
}

void Queue::Deletion()
{
    // one item is in Queue
    if(front==rear && front!=NULL)
    {
        delete front;
        front = NULL;
        rear = NULL;
    }
    else if(front==NULL && rear==NULL)
        cout<<"Queue is empty";
    else
    {
    node*temp;
    temp = front;
    front = front->next;
    delete temp;
    }
}
void Queue::viewFront()
{
    cout<<front->item<<endl;
}
void Queue::viewRear()
{
    cout<<rear->item<<endl;

}
void Queue::countElements()
{
    int count = 0;
    if(front==rear && front!=NULL)
    {
        count = 1;
        cout<<"No of elements in Queue is"<<count<<endl;
    }
    else if(front==NULL && rear==NULL)
    {
        cout<<"Queue is empty";
    }
    else
    {
        node *temp;
        temp = front;
        while(temp->next!=NULL)
        {
            count++;
            temp= temp->next; 
        }
        
        cout<<"No of elements in Queue is "<< count+1<<endl;
    }
}

int main()
{
    Queue q1;
    q1.Insertion(5);
    q1.Insertion(10);
    q1.Insertion(15);
    q1.Insertion(20);
    q1.Insertion(25);
    q1.viewFront();
    q1.viewRear();
    q1.countElements();
}