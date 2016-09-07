#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class stack
{
private:
    struct memory
    {
        memory *bottom ;
        T data;
    } *top;
public:
    stack()
    {
        top = NULL;
    }
    ~stack()
    {
        while(top!=NULL)
            pop();
    }
    void push(T data)
    {
        memory *temp;
        temp = new memory;
        temp->data = data;
        temp->bottom = top;
        top = temp;
    }
    void pop()
    {
        if(top==NULL)
            {
                cout<<"Stack is empty"<<endl;
            }
        else
        {
            int popData = top->data;
            memory *temp = top;
            top = top->bottom;
            delete temp;
            cout<<popData<<endl;
        }
    }
};

int main()
{
    stack<int> s;
    s.push(2);
    s.push(2);
    s.push(2);
    s.push(2);
}