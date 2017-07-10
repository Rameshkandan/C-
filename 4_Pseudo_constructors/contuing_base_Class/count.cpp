#include<iostream>
class A
{
public:
	A() {
		std::cout << "Hello";
	}
	A(const A &a)
	{
		std::cout << "Hi";
	}
	void print()const { std::cout << "\ngoing to be deleted in the pseudo constructor"; delete this; } // pseudo constructor;
	void des()
	{}
private:
	~A()
	{}
	
};

class B :public A{};
class C {
public:
	A *t;
};



int main()
{
	//A q1;
	//B d;
	A *q = new A;
	C y;
	//A *r = q;
	q->print();
	//r->des();
	
	system("pause");
	return 0;
}