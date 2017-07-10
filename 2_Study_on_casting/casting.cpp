#include<iostream>
class Widget
{
public:
	Widget() {}
	virtual ~Widget() {}
};
class Superwidget :public Widget
{
public:
	Superwidget() {}
	virtual ~Superwidget() {}
};
class B
{

};

void update(Superwidget *ws)
{}

void up(Superwidget &sr)
{}
int main()
{
	Superwidget e, *R;
	const Superwidget s;
	const Superwidget *s1 = new Superwidget;
	//B *wd;
	//wd = static_cast<Superwidget*>(R);
	Widget *pw, *pw1, *pw2;
	pw = static_cast<Superwidget *>(const_cast<Superwidget *>(s1));
	pw1 = static_cast<Superwidget *>(&e);
	//update(pw); // incompatible  conversion creates a dervied class pointer from a base class 
	update(dynamic_cast<Superwidget *>(pw)); // should work fine with static cast. // dynamic cast will only work if the ineritance atleast has one virtual function
	update(const_cast<Superwidget *>(&s)); // works fine
	update(const_cast<Superwidget *>(s1)); // works fine
	up(dynamic_cast<Superwidget&>(*pw));

	system("pause");
	return 0;
}