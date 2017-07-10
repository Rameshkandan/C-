#include<iostream>
class A
{
public:
	A(int x=0):d(x){}
	const A operator++(int i)const
	{
		A q = *this;
		q.d += 1;
		return q;

	}
	void print()const
	{
		std::cout <<"\n"<< d;
	}

	A& operator++()
	{
		this->d += 1;
		return *this;
	}
private:
	int d;
};

int main()
{
	A a(6);
	A r1 = a++++;
		r1.print();
	A r = ++++a;
		r.print();
	system("pause");
	return 0; 
}