#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int i;
    /* When you will uncomment and compile, it will give an error.
    References need to be initialised while declaring.
    Also array of references cannot be declared. 
    But you can have references to a reference. */
    // int &j[3] = {1,22,3} 
    // int &j; 
    int &k = i;
    int &a = k; //Reference to a reference

    cout<<i<<" "<<k<<endl;
    i = 2;    
    cout<<i<<" "<<k<<endl;
    k = 4;
    cout<<i<<" "<<k<<endl;
    a = 12;
    cout<<i<<" "<<k<<" "<<a<<endl;
    cout<<&i<<" "<<&k<<" "<<&a<<endl;
    return 0;
}