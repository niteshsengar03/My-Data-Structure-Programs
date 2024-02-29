#include<iostream>
using namespace std;

// Stack using doubly link list
struct node
{
    node *next;
    node *prev;
    int item;
};

class Stack
{
    private:
        node *top;
        node *head;
    public:
        Stack();

        void Append(int);
        
        void print();

        // peek top element
        void peek();

        void pop();
};

Stack::Stack()
{
    top=NULL;
    head=NULL;
}

void Stack::Append(int data)
{
    if(top==NULL)
    {
        //if Stack is empty
        top=new node;
        head=top;
        top->prev=NULL;
        top->next=NULL;
        top->item=data;
    }
    else
    {
        node*n;
        n=new node;
        n->item=data;
        n->prev=top;
        n->next=NULL;
        top->next=n;
        top=n;
    }
}

void Stack::print()
{
    if(top==NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else{
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->item<<endl;
            temp=temp->next;
        }
    }
}

void Stack::peek()
{
    if(top==NULL)
        cout<<"Stack is empty";
    else
        cout<<top->item;
}

void Stack::pop()
{
    if(top==NULL)
    {
        cout<<"Stack is empty";
    }
    else
    {
        if(top->next==NULL && top->prev==NULL)
        {
            node *temp;
            temp=top;
            delete temp;
            top=NULL;
        }
        else
        {
            node*temp;
            temp=top;
            top=top->prev;
            top->next=NULL;
            delete temp;
        }
    }
}






int main()
{
    Stack s1;
    s1.Append(5);
    s1.Append(6);
    s1.Append(10);
    s1.print();
    
    cout<<endl;
    s1.pop();
    s1.pop();
    // s1.pop();
    s1.print();
    s1.pop();
    return 0;
}