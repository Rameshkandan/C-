#include<iostream>
class B
{

};
class A
{
public:
	A()
	{}
//private:
	explicit A(const B& b) {}
	void f(const A& b)
	{
		std::cout << " Hello";
	}
	virtual void pdt() {
		std::cout << "Hi in A";
	}
	

};

class C :  private A
{
	//private  A{   - dynamic cast willwork but returns null ptr for private and protected inheritance .... 
	//that is .. 
	//only in the run time it tells you that this ptr is a 
public:
	C():A(){
	}
	C( C& c)
	{
		A *d = &c;
		d->pdt();
	}
	virtual void pdt() {
		std::cout << "Hi in C";
	}
};
int main()
{
	//A d;
	//B e;
	//C *q = new C;
	A *q = new A;
	//C *s = new C;
	//A *w = dynamic_cast<A*>(q);
	A *w = static_cast<A*>(q);
	//A *w = dynamic_cast<A*>(q);
	if (!w)
		std::cout << "\n\nNull ptr!";
	else

		std::cout << "\n\n not a Null ptr!";
	//C *c = new  C;
//	C c;
//	C t = c;
	
//	A *d = c;
//	d.f(A(e));
	system("pause");
	return 0;
}
