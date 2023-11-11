//Apply stack using array

#include<iostream>
using namespace std;

class Stack
{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        // To initialise member variable
        Stack();

        // Pass size of Stack
        void CreateStack(int);

        // Pass data
        void Push(int);

        void Peek();

        void Pop();

        void print();
};

Stack::Stack()
{
    capacity=0;
    top=-1;
    ptr=NULL;
}
void Stack::CreateStack(int size)
{
    capacity=size;
    top=-1;
    if(ptr!=NULL)
        delete[] ptr;
    ptr=new int[size];
}
void Stack::Push(int data)
{
    if(ptr==NULL)
        cout<<"Call CreateStack"<<endl;
    else if(top==capacity-1)
        cout<<"Data overflow"<<endl;
    else
    {
        top++;
        ptr[top]=data;
    }
}
void Stack::Peek()
{
    if(top==-1)
        cout<<"Stack Is Empty";
    else
        cout<<ptr[top]<<endl;
}
void Stack::Pop()
{   
    if(top==-1)
        cout<<"Stack is empty"<<endl;
    else 
        top--;
}
void Stack::print()
{
    for(int i=0;i<=top;i++)
        cout<<ptr[i]<<endl;
}

int main()
{
    Stack s1;
    s1.CreateStack(3);
    s1.Push(1);
    s1.print();
    s1.Push(3);
    s1.Push(5);
    cout<<endl;
    s1.print();
    s1.Pop();
    s1.Pop();
    s1.Pop();
    s1.Pop();
    s1.Pop();

}