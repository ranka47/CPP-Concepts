#include <iostream>
using namespace std;

class excep
{
private:
	char *str;
public:
	excep(char *s)
	{
		str=s;
	}
	char *geterror()
	{
		return str;
	}
};

class math
{
public:
	int fun(int n, int d)
	{
		if(d==0)
		{
			excep e("Divide by zero");
			throw e;
		}
		return n/d;
	}
};

int main()
{
	int a=20, b=1;
	math m;
	try
	{
		int c = m.fun(a,b);
	}
	catch (excep p)
	{
		cout<<p.geterror();
	}
	return 0;
}