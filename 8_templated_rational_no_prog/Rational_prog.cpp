// mixed mode arithmetic can be done using the friend function conversions 
#include<iostream>
//template<class T>
class Rational
{
public:
 //explicit 
	Rational(int numerator = 0, int denomenator = 1):n(numerator),d(denomenator){}
    const Rational operator*(const Rational &r)const
	{
	   Rational r1;
	   r1.n = numerator() * r.numerator();
	   r1.d = denominator() * r.denominator();
	   return r1;
	}

	const Rational& operator=(const Rational &r)const
	{
		n = r.numerator();
		d = r.denominator();
		return *this;
	}
	
	const int numerator()const 
	{
		return n;
	}
	const int denominator()const
	{
		return d;
	}

	void print()const
	{
		std::cout << "\nrational rresult" << this->n << "\t" << this->d;
	}
	//friend const Rational operator*(const Rational &r3, const Rational &r);

private:
	mutable int n, d;
};

//template<class T>
//const Rational operator*(const Rational &r3, const Rational &r)
//{
	//Rational r2;
	//r2.n = r3.numerator()*r.numerator();
	//r2.d = r3.denominator()*r.denominator();
	//return r2;
// }

int main()
{
    Rational half(1, 2), three_forth(3, 4);
    const Rational result = half * three_forth;
	//const Rational result2 = Rational(4,5.6) * three_forth;  - can be used when explicit constructors are used.
	const Rational result2 = half * 2; // this executes with the normal operator overloading itself.
	result.print();
	result2.print();
	system("pause");
	return 0;
}
