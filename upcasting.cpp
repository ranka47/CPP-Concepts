#include <iostream>
using namespace std;
class base
{
	protected:
		int i;
	public:
		base(int ii)
		{
			i=ii;
			cout<<"Base CTOR "<<i<<endl;
		}
		~base()	//Avoiding memory leak. Because calling DTOR of a derived classs object 
		{
			cout<<"Base DTOR "<<i<<endl;
		}
};
class derived:public base
{
	public:
		derived(int i):base(i)
		{
			cout<<"derived CTOR "<<i<<endl;
		}
		~derived()
		{
			cout<<"derived DTOR "<<i<<endl;
		}

};

int main()
{
	// making base object in a normal way
	base b(1);
	cout<<"-----------------"<<endl;
	// making derived object in a normal way
	derived d(2);
	cout<<"-----------------"<<endl;
	// declaring base and derived classes' pointers to make objects using 'new' operators
	base *bPtr; derived *dPtr;
	cout<<"-----------------"<<endl;
	// making base object dynamically
	bPtr = new base(3);
	cout<<"-----------------"<<endl;
	// making derived object dynamically
	dPtr = new derived(4);
	cout<<"-----------------"<<endl;
	// deallocating space for base and derived objects
	delete bPtr;
	cout<<"-----------------"<<endl;
	delete dPtr;
	cout<<"-----------------"<<endl;
	// checking in the case of UPCASTING
	bPtr = new derived(5);
	cout<<"-----------------"<<endl;
	// deallocating and checking the sequence of DTOR's when pointer is UPCASTED
	delete bPtr;
	cout<<"Ends Here!"<<endl;
	// You will observer that the derived class DTOR is not called in this UPCASTED case.
	// To solve the problem check out the virtualDestructor.cpp
	return 0;
}