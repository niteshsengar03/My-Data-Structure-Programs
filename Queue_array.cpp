#include<iostream>
using namespace std;

// Queue using array 
// This is very special because you can use the free space of array when item is removed in a circular manner but
// from outside it will look normal queue

class Queue
{
    private:
        int capacity,front,rear,*ptr;
    public:
        Queue();

       void CreateQueue(int);

       void Insertion(int);
        
        void Deletion();
       void printQueue();

};

Queue::Queue()
{
    capacity=0;
    front=-1;
    rear=-1;
    ptr=NULL;
}

void Queue::CreateQueue(int size)
{
    capacity=size;
    front=-1;
    rear=-1;
    if(ptr!=NULL)
        delete []ptr;
    ptr= new int[size];
}
void Queue::Insertion(int data)
{
    // Queue is empty
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        ptr[rear]=data;

    }
    else if(front == rear)
    {
        rear ++;
        ptr[rear]=data;
    }
    else if(rear<capacity-1 && rear > front)
    {
        rear++;
        ptr[rear]=data;
    }
    else if(rear==capacity-1) 
    {
    // when rear is in the last but queue is full
        if(front==0)
        {
             cout<<"Que is overflow"<<endl;
        }
        // when rear is in the last index and queue is empty from first
        else
        {
            rear = 0;
            ptr[rear] = data;
        }
    }
    else if(rear < front && rear != front - 1 )
    {
        rear ++;
        ptr[rear]= data;
    }
    else if(rear == front - 1)
    {
        cout<<"Que is overflow"<<endl;
    }
}

void Queue::Deletion()
{
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    // only one value is in queue
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if(front<rear)
    {
        front++;
    }
    else if(rear<front)
    {
        if(front!=capacity-1)
            front++;
        else
            front =0;
    }
}

void Queue::printQueue(){
    if(rear>front){
    for(int i=front;i<=rear;i++){
        cout<<ptr[i]<<endl;
    }
    }
    else{
        for(int i = front ;i<capacity;i++)
        {
            cout<<ptr[i]<<endl;
        }
        for(int i=0;i<=rear;i++)
        {
            cout<<ptr[i]<<endl;
        }
    }
}


int main()
{
    Queue q1;
    q1.CreateQueue(5);
    q1.Insertion(10);
    q1.Insertion(20);
    q1.Insertion(30);
    q1.Insertion(40);
    q1.Insertion(50);
    q1.Deletion();
    q1.Deletion();
    q1.Insertion(60);
    q1.Insertion(70);
    q1.Insertion( 80);
    q1.Deletion();
     q1.Insertion( 80);
      q1.Deletion();
    q1.Deletion();
    q1.Insertion(90);
    q1.printQueue();
    
}