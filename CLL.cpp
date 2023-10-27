#include<iostream>
using namespace std;

// defining node
struct node
{
    int item;
    node*next;
};

//Circular linklist
class Cll
{
    //defineing pointer will be pointing last node
    private:
        node*last;
    public:
        Cll();   // initalising last pointer with NULL
        void insertAtfirst(int);
        void insertAtend(int);
        bool search(int);
        void print();
        void insertAfter(int,int);
        void deletfirst();
        void deletlast();
        void deletafter(int);

};

Cll::Cll()
{
    last=NULL;
}
void Cll::insertAtfirst(int data)
{
    //preparing node
    node*n;
    n=new node;
    n->item=data;
    n->next=NULL;
    // node is empty
    if(last==NULL)
    {
        last=n;
        n->next=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
void Cll::insertAtend(int data)
{
    //prepare node
    node*n;
    n=new node;
    n->item=data;
    n->next=NULL;
    if(last==NULL)
    {
        last=n;
        n->next=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
}
bool Cll::search(int data)
{
    node*temp;
    if(last->item==data)
        return true;
    temp=last->next;
    while(temp!=last)
    {
        if(temp->item==data)
            return true;
         temp=temp->next;
    }
    return false;
}
void Cll::print()
{
        node*temp;
        temp=last->next;
        while (temp!=last)
        {
            cout<<temp->item<<endl;
            temp=temp->next;
       }
        cout<<last->item<<endl;
}
void Cll::insertAfter(int position, int data)
{
    if(last==NULL) // if node is empty
        insertAtfirst(data);
    else {
        int p=position;
        //prepare node
        node*n;
        n=new node;
        n->item=data;
        n->next=NULL;
        
        node*t;
        t=last;
        while(position>-1)
        {
                t=t->next;
                position--;
        }
        if(t==last && p!=-1)
                insertAtend(data);
        else
        {
            n->next=t->next;
            t->next=n;
        }
    }
}
void Cll::deletfirst()
{
    node*temp;
    temp=last->next;
    last->next=temp->next;
    delete temp;
}
void Cll::deletlast()
{
    node*t;
    t=last->next;
    while(t->next!=last)
        t=t->next;
    t->next=last->next;
    delete last;
    last=t;   
}
void Cll::deletafter(int position)
{

        int p=position;
        node*t;
        t=last;
        while(position>-1)
        {
                t=t->next;
                position--;
        }
         if(t==last && p!=-1)
                deletlast();
        else
        {
            node*t1;
            t1=last;
            while(t1->next!=t)
                t1=t1->next;
            t1->next=t->next;
            delete t;
        }
}

int main()
{
    Cll c1;
    c1.insertAtfirst(3);
    c1.insertAtend(5);
    c1.insertAtfirst(8);
    c1.insertAtend(10);

    c1.print();
    
    c1.deletafter(3);
    cout<<endl<<endl;
    c1.print();
    return 0;
}