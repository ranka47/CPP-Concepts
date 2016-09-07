#include <iostream>
#include <string.h>
using namespace std;

class emp
{
private:
    char name[20];
    int age;
    float salary;
public:
    emp(char *name = "", int age = 0, int salary = 0.0)
    {
        strcpy(this->name,name);
        this->age = age;
        this->salary = salary;
    }

    friend ostream& operator << (ostream& o, emp &e);
};

ostream& operator << (ostream& o, emp &e)
{
    cout<<e.name<<" "<<e.age<<" "<<e.salary<<endl;
    return o;
}

template <class T>
class linkedList
{
private:
    struct node
    {
        T data;
        node* link;
    } *p;
public:
    linkedList()
    {
        p = NULL;
    }
    ~linkedList()
    {
        node *t, *ptr;
        ptr = p;
        while(ptr != NULL)
        {
            t = ptr;
            ptr = ptr->link;
            delete t;
        }
    }
    void addHead(T num)
    {
        node *r;
        r = new node;
        r->data = num;
        r->link = p;
        p = r;
        cout<<"Inserted."<<endl;
        cout<<p->data<<endl;
    }
    void insertAt(int, T);
    void addTail(T);
    void deleteAt(int);
    void del(T);
    void display()
    {
        node *ptr = p;
        while(ptr != NULL)
        {
            cout<<ptr->data;
            if(ptr->link != NULL)
                cout<<"->";
            ptr = ptr->link;
        }
        cout<<endl;
    }
    int count();
};




template <class T>
void linkedList<T>::insertAt(int c, T num)
{
    node *prev, *ptr;
    ptr = p;
    int count = 1;
    if(c<=0)
    {
        cout<<"Invalid Postition entered."<<endl;
        return;
    }
    while (count != c && ptr != NULL)
    {
        count++;
        prev = ptr;
        ptr = ptr->link;
    }

    if(c == count && ptr == NULL)
        addTail(num);
    else if (c == count)
    {
        node *r;
        r = new node;
        r->data = num;
        r->link = ptr;
        prev->link = r;
    }
    else
        cout<<"Position beyond range."<<endl;
}

template <class T>
void linkedList<T>::addTail(T num)
{
    node *prev, *r, *ptr;
    ptr = p;
    while(ptr != NULL)
    {
        prev = ptr;
        ptr = ptr->link;
    }
    r = new node;
    r->data = num;
    r->link = NULL;
    prev->link = r;
    cout<<"Tail Added"<<endl;
}

template <class T>
void linkedList<T>::del(T num)
{
    node *r,*prev, *ptr;
    ptr = p;
    while (ptr != NULL && ptr->data != num)
    {
        prev = ptr;
        ptr = ptr->link;
    }
    if(ptr==p)
    {
        p = ptr->link;
    }
    if (ptr == NULL)
    {
        cout<<"Data doesn't exist."<<endl;
    }
    else 
    {
        prev->link = ptr->link;
        delete ptr;
        cout<<"Deleted"<<endl;
    }
}

template <class T>
void linkedList<T>::deleteAt(int num)
{
    int count = 1;
    node *prev, *ptr;
    ptr = p;
    while (ptr->link != NULL && count!=num)
    {
        prev = ptr;
        ptr = ptr->link;
        count++;
    }
    if (count != num || ptr->link == NULL)
        cout<<"Element does not exist at that position."<<endl;
    else
    {
        prev->link = ptr->link;
        delete ptr;
        cout<<"Deleted"<<endl;
    }
}
