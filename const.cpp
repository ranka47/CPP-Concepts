#include <iostream>
using namespace std;
class constant
{
private:
    int i;
    int count;
public:
    constant(int i)
    {
        this->i = i;
        count++;
    }

    void constFunc() const{
        cout<<"Value of i: "<<i<<endl;
        anotherConstFunc();
        cout<<"Value of i: "<<i<<endl;
        (const_cast<constant*> (this))->i = 5;
        /* Ugly and dangerous. Highly recommended not to use it! */
    }
    
    void anotherConstFunc() const{
        cout<<"Constant func calls another const function"<<endl;
    }

    void display()
    {
        cout<<"Count: "<<count<<" "<<"i: "<<i<<endl;
    }
};

int main()
{
    constant c1(1), c2(2);
    c1.constFunc();

    char* p1 = "Hello";
    char p2[] = "Hello";
    const char* p3 = "Hello";
    char* const p4 = "Hello";
    char const *p5 = "Hello";
    const char* const p6 = "Hello"; 
    p1 = p1+1; p1=p1-1;
    p1 = "Bye";
    /* *p1 = 'M'; */
    cout<<"p1: "<<p1<<endl;

    // p2 = p2+1;
    // p2 = "Bye";
    *p2 = 'M';
    cout<<"p2: "<<p2<<endl;

    p3 = p3+1; p3--;
    p3 = "Bye";
    // *p3 = 'M';
    cout<<"p3: "<<p3<<endl;

    // p4 = p4+1;
    // p4 = "Bye";
    /* *p4 = 'M'; */
    cout<<"p4: "<<p4<<endl;

    p5 = p5+1; p5--;
    p5 = "Bye";
    // *p5 = 'M';
    cout<<"p5: "<<p5<<endl;

    // p6 = p6+1;
    // p6 = "Bye";
    // *p6 = 'M';
    cout<<"p6: "<<p6<<endl;
}