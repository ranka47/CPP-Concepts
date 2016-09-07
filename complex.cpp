#include <iostream>
// #include <iomanip>
using namespace std;

class complex
{
private:
    float real, img;
public:
    complex (float rr = 0.0, float ii = 0.0)
    {
        real = rr;
        img = ii;
        cout<<"HI";
    }

    complex operator ++ ()
    {
        complex temp;
        temp.real = ++real;
        temp.img = img;
        cout<<"Without argument"<<endl;
        return temp;

    }

    complex operator ++ (int n)
    {
        complex temp;
        temp.real = real++;
        temp.img = img;
        cout<<"With argument"<<endl;
        return temp;
    }

    complex operator = (const complex &c)  
    /* Pass the args as 'const' 
    Because literals (and rvalues in general) cannot be passed by non-const reference 
    since it would make no sense if the callee could change them. 
    Either pass by value or by const reference: */
    {
        real = c.real;
        img = c.img;
        cout<<"Overloaded assignment operator is called"<<endl;
        return *this;
    }

    complex (const complex &c)
    /* Pass the args as 'const' 
    Because literals (and rvalues in general) cannot be passed by non-const reference 
    since it would make no sense if the callee could change them. 
    Either pass by value or by const reference: */
    {
        real = c.real;
        img = c.img;
        cout<<"Copy CTOR is called"<<endl;
    }
    /* This is helpful in adding commutative property to the addition.
    Due to adding operator add fn as friend fn you can use both 'a+d' and 'd+a'.*/

    friend complex operator + (complex c1, complex c2);
    friend ostream& operator << (ostream& out, complex temp);
};

int main()
{
    complex a(11.0, 1);
    complex b(2.0, 2.0);
    complex c;

    double d = 1.1, e = 2.2;
    c = a + b + e;
    cout<<c;
    c=a++;
    cout<<c;
    c=++a;
    cout<<c;

    c = a + d;      
/* This works as 'complex c2(2)', hence assigning c2.real == 2 and c2.img == 0.0 To prevent this 
   you must add the keyword 'explicit' in front of CTOR. This will make a strict type checking while adding 
   two complex numbers. */
   // cout<<"----------";
    cout<<c;

    return 0;
}

complex operator + (complex c1, complex c2)
{
    complex temp;
    temp.real = c1.real + c2.real;
    temp.img = c1.img + c2.img;
    return temp;
}

ostream& operator << (ostream& out, complex temp)
{
    //showpoint is a formatting flag
    out<<"Real : "<<hex<<temp.real<<" Img : "<<temp.img<<endl;
}