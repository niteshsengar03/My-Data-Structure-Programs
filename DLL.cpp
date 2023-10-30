#include<iostream>
using namespace  std;

struct node
{
    int item;
    node *next;
    node *prev;
};
class DLL
{
    private:
            node*start;
    public:
        DLL();
        void insertAtfirst(int);

        void insertAtend(int);

        bool isEmpty();

        // retrun address of the node if found else return NULL(0)
        node* searchdata(int);

        //insert after given index (index starting from zero as array)
        void insertAfter(int,int);

        void deletfirstnode();

        void deletlastnode();

        void deletspecificnode(int);

        void print();

        
};  
DLL::DLL()
{
    start=NULL;
}
void DLL::insertAtfirst(int data)
{
        node*n;
        n=new node;
        n->prev=NULL;
        n->item=data;
        n->next=start;
        if(start!=NULL)
            start->prev=n;
        start=n;
}
void DLL::insertAtend(int data)
{
    //prepare a node
    node*a;
    a=new node;
    a->item=data;
    a->next=NULL;
    a->prev=NULL;
    if(start==NULL)
    {
        start=a;
    }
    else
    {
        node*temp;
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=a;
        a->prev=temp;
    }
}
void DLL::insertAfter(int position,int data)
{

        //preparing node
	    node*a;
	    a=new node;
	    a->item=data;
	    a->prev=NULL;
	    a->next=NULL;

        //traverse temp to desired node
        node*temp;
	    temp=start;
        while(position>0)
        {
            temp=temp->next;
            position--;
        }

        // join the node with main branch
	    a->next=temp->next;
	    temp->next=a;
	    if(a->next!=NULL)
	    {
	        a->next->prev=a;
	    }
	    a->prev=temp;
}
void DLL::deletfirstnode()
{
    node*temp;
    if(start!=NULL)
    {
        temp=start;
        start=start->next; // traverse one node
        start->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else 
        cout<<"List is empty"<<endl;

}
void DLL:: deletlastnode(){
    
    node*temp;
    temp=start;

    if(temp==NULL)
        cout<<"List is empty"<<endl;
    else
    { 
        //there is one node in list
        if(temp->next==NULL)
        {
            delete temp;
            start=NULL;
        }
        //there are more than one node in a list
        else
        {
        node*tail;
        while(temp->next!=NULL)
                temp=temp->next;
        tail=temp;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;
        }
    }
}
void DLL::deletspecificnode(int position)
{
    node*temp;
	    temp=start;
        while(position>0)
        {
            temp=temp->next;
            position--;
        }
        if(temp->prev==NULL)
        {
            deletfirstnode();
        }
        else if(temp->next==NULL)
        {
            deletlastnode();
        }
        else{
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }
}


node* DLL::searchdata(int data)
{
    node*temp;
    temp=start;
    while(temp->next!=NULL)
    {
        if (temp->item==data)
            return temp;
        temp=temp->next;
       
    }
    return NULL;
}

void DLL::print()
{
    node*temp;
    temp=start;
    while(temp) // till temp is not storing NULL
    {
        cout<<temp->item<<endl;
        temp=temp->next;
    }
}



int main()
{
    DLL d1;
    d1.insertAtfirst(5);
    d1.insertAtend(4);
    d1.insertAtend(10);
    d1.insertAtend(15);
    d1.print();
    cout<<endl;
    d1.deletspecificnode(3); 
    d1.print();
    return 0;
}