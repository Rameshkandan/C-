#include<iostream>
template<class T>
class Array
{
public:

	Array(int s) :size(s), a(new T[size]) // to avoid implicit conversions! - method -1
	{
		for (int i = 0; i < size; i++)
			a[i] = 0;
	}

	T& operator[](int i)const
	{
		return a[i];
	}


	~Array()
	{
		delete[] a;
	}
	void print()const
	{
		for (int i = 0; i < this->size; i++)
			std::cout << "\t" << a[i];
		std::cout << "\n";
	}

	//friend bool operator==(const Array<T> &lhs, const Array<T> &rhs);

	bool operator==(const Array<T> &rhs)

	{
		for (int i = 0; i < size; i++)
		{
			if (a[i] == rhs.a[i])
				return true;
			else
				return false;
		}
	}

private:
	int size;
	T *a;
};



int main()
{
	Array<int> a(10);
	Array<int> b(10);
	Array<int> c(10);

	for (int i = 0; i < 10; i++)
		a[i] = 5 - i;
	for (int i = 0; i < 10; i++)
		b[i] = 3 + i;
	for (int i = 0; i< 10; i++)
	{
		//if (a == Array<int>(b[i]))
		if (a[i] == b[i]) // this works ... but the output is wrong ... 
						  //here the implicit conversion takes place via the constructor with the single value as a parameter.
						  //   ........ if(a==static_cast< Array<int> >(b[i])**** this is what is happening 
						  //to have the correct output we need to do with a[i]  only!
		{
			c[i] = a[i];
		}
		else
		{
			c[i] = 0;
		}
	}
	a.print();
	b.print();
	c.print();
	system("pause");
	return 0;

}
