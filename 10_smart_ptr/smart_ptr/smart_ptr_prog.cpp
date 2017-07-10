#include<iostream>
class Top
{
public:
	virtual void print()
	{
		std::cout << "\nHi in Top";
	}
};
class M : public Top
{
public:
	virtual void print()
	{
		std::cout << "\nHello on M";
	}
};
class E : public M
{

public:
	virtual void print()
	{
		std::cout << "\nHello on E";
	}

};
template<class T>
class Smartptr
{
public:
	Smartptr():pdata(0) {}

	Smartptr(Smartptr &r):pdata(r.getdata()){}

	template<class U>
	Smartptr(Smartptr<U> &other) :pdata(other.getdata()) {}
	T* getdata()const
	{
		T *oldp = pdata;
		delete pdata;
		return oldp;
	}

	template<class U>
	Smartptr<T>& operator=(const Smartptr<U> &other1)
	{
		pdata = other1.getdata();
		//Smartptr<T>::Smartptr(Smartptr<U> &other1);
		return *this;
	}
	~Smartptr()
	{
		delete pdata;
	}
	T* operator->()const
	{
		return pdata;
	}
private:
	T *pdata;
};

int main()
{
	//Smartptr<Top> t(Smartptr<M> m);
	Top *t1 = new Top;
	E *t2 = new E;
	Smartptr<Top> m(t2);
	//Smartptr<E> t(t2);
	m = t1;
	m->print();
	return 0;
}
