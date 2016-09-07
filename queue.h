#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class queue
{
private:
    struct memory
    {
        memory *next;
        T data;
    } *front, *last;
public:
    queue()
    {
        front = last = NULL;
    }
    ~queue()
    {
        while(front!=NULL)
            pop();
    }
    void push(T data)
    {
        if(front==NULL)
        {
            memory *temp;
            temp = new memory;
            temp->next=NULL;
            temp->data = data;
            front = last = temp;
        }
        else
        {
            memory *temp;
            temp = new memory;
            temp->next=NULL;
            temp->data = data;
            last->next = temp;
            last = temp;
        }
    }
    void pop()
    {
        if(front==NULL)
            cout<<"Queue is empty"<<endl;
        else
        {
            cout<<front->data<<endl;
            memory *temp;
            temp = front;
            front = front->next;
            delete temp;
        }
    }
};

template <class T>
class circularQueue
{
private:
    T arr[20];
    T* tail, head;
    int length;
public:
    circularQueue()
    {
        head = &arr[0];
        tail = &arr[0];
    }
    void push(T data)
    {
        if(length==20)
            cout<<"Queue is full"<<endl;
        else
        {
            *tail = data;
            if(tail == &arr[19])
                tail = &arr[0];
            else tail++;
        }
    }
    void pop()
    {
        if(length==0)
            cout<<"Queue is empty"<<endl;
        else
        {
            cout<<*head<<endl;
            if(head == &arr[19])
                head = &arr[0];
            else head++;

        }
    }
};
