#include<iostream>
using namespace std;
class C
{
private : 
	int a;
	int p[10];
public: 
	C(int x) :a(x) {
		for (int i = 0; i < a; i++)
		{
			p[i] = i;
		}
	}
	int  getvalue() const
	{
		
		return const_cast<C*> (this)-> p[2]++;
	}

	void chuma() const
	{
		std::cout << getvalue();
	}

};
	int main()

	{
		C c1(10);
		c1.chuma();
		system("pause");
		return 0;
	}

