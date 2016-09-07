/* */
#include <iostream>
using namespace std;
class complex
{
private:
	float r = 0, i=0;
public:
	complex operator ++ (int n)
	{
		complex t;
		t.r = 10.5;
		t.i = 20.5;
		cout<<"I am with argument with value: "<<n<<endl;
		return t;
	}
	complex operator ++ ()
	{
		complex t;
		t.r = 10.0;
		t.i = 20.0;
		cout<<"I am without argument"<<endl;
		return t;
	}
	void display()
	{
		cout << r <<" "<< i << " " << endl;
	}
};
int main()
{
	complex c1,c2,c3;
	// c1.display();
	c2 = ++c1;
	c3 = c1.operator ++ ();
	c3 = c1++;
	c2 = c1.operator ++ (2);
	// c2.display();
	// c3.display();
	return 0;
}