#include<iostream>
using namespace std;

// Queue using array 

class Queue
{
    private:
        int capacity,front,rear,*ptr;
    public:
        Queue();

       void CreateQueue(int);

       void Insertion(int);

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
        ptr[0]=data;
        front=0;
        rear=0;
    }
}



int main()
{

}