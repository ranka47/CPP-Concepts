#include <iostream>
using namespace std;
class sample
{
private:
    int i;
    static int count;
public:
    sample(int i)
    {
        this->i = i;
        count++;
    }
    static void staticDisplay()
    {
        /* Next line would give error because static fns can access only static data.
        No non-static member fns can be accessed in static fns 
        this ptr does not get pass in static fns. */
        // cout<<count<<" "<<this->i<<endl;
        cout<<"Count: "<<count<<endl;
    }
    void display()
    {
        cout<<"Count: "<<count<<" "<<"i: "<<i<<endl;
    }
};

class singleton
{
private:
    int i;
    static singleton *p;    
    singleton() //CTOR needs to be private so that it doesnt get called outside the class.
    {
        i = 47;
    }
public:
    static singleton* create()
    {
        if (p==NULL) // PTR p is static so that it remains constant across every object and static can acess only static data member.
        {
            p = new singleton;
        }
        return p;
    }
};
int sample::count = 0;
singleton* singleton::p = NULL;
int main()
{

    cout<<"Calling without any instance defined: ";
    sample::staticDisplay();
    sample s1(1), s2(2);
    cout<<"Using object s1 => ";
    s1.display();
    s1.staticDisplay();
    cout<<"Using object s2 => ";
    s2.display();
    s2.staticDisplay();
    cout<<"Using class namespace => ";
    sample::staticDisplay();

    /* Size of single int. If data member 'i' is removed then sizeof() returns 1 */
    cout<<"Size of 'sample' objects: "<<sizeof(s1)<<endl;


    // singleton sig1;  //Wont work as CTOR is made private. 
    cout<<"--------Singleton--------"<<endl;
    singleton *sigPtr1 = singleton::create();
    singleton *sigPtr2 = singleton::create();
    cout<<sigPtr1<<" "<<sigPtr2<<endl;      //Same address gets printed
}