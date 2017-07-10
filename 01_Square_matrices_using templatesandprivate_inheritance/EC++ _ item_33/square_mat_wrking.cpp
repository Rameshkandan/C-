#include<iostream>
template<class T>
class Squarematrixbase
{
protected:
	Squarematrixbase(int n):size(n*n), pdata(new T[size])
	{
	
	}
public:
	void setdataptr(T *ptr)
	{
		for (int i = 0; i < size; i++)
		{
			pdata[i] = ptr[i];
		}
	}
	void print()const
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "\t" << pdata[i];
		}
	}
	
private:
	int size;
	T *pdata;
	
};

template<int n,class T>
class Squarematrix:private Squarematrixbase<T>
	// while using private, access base class functions usinf forwarding functions
{
public:
	Squarematrix():Squarematrixbase<T>(n)
	{

	}

	void setdata(T *x)
	{
		this->setdataptr(x);
	}
	void print1()const
	{
		this->print(); // use this-> to access the member functions of the templated base class 
		//or else it wont work properly in some compilers
	}

	
};

int main()
{
	int p[] = { 2,3,5,6};
	Squarematrix<2, int> r;
	r.setdata(p);
	r.print1();
	system("pause");
	return 0;
}