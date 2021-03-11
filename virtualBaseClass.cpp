/* Contains how the diamond shaped inheritance can be solved by looking into the sizes of objects formed
Also it shows  how the static data gets inherited */
#include <iostream>

using namespace std;
class base
{
	public:
		int data;

	public:
		base()
		{
			data=500;
		}
};
class derived1:public base
{

};
class derived2:public base
{

};
class derived3:public derived1, public derived2
{
	public:
		int setdata()
		{
			return derived1::data=100;
		}

};
class virtualBase
{
	public:
		int data = 1234;
};
class derived4:virtual public virtualBase
{

};
class derived5:virtual public virtualBase
{

};
class derived6:public derived4, public derived5
{
	public:
		derived6()
		{
			cout << data << endl;
		}
};
class staticBase
{
public:
	static int data;
};
class staticDerived:public staticBase
{

};

int staticBase::data = 100;
int main()
{
	derived3 der3;
	der3.setdata();
	derived6 der6;

	cout << der3.derived1::data << "----" << der3.derived2::data << endl;
	printf("%ld %ld %ld %ld\n", sizeof(base), sizeof(derived1), sizeof(derived2), sizeof(derived3));

	// Size of virtual inheritance increases because of overhead due to virtual pointers
	printf("%ld %ld %ld %ld\n", sizeof(virtualBase), sizeof(derived4), sizeof(derived5), sizeof(derived6));

	// Size of static members not counted in sizeof classes. Hence, 1.
	printf("%ld %ld\n", sizeof(staticBase), sizeof(staticDerived));
	cout << staticDerived::data << endl;
	return 0;
}