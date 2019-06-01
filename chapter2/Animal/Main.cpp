
#include "animal.h"
#include "fish.h"
#include <iostream.h>

class Base 
{
public:
	virtual void xfn(int i)
	{
		cout<<"Base:xfn(int i)"<<endl; 
	}

	virtual void yfn(float f)
	{
		cout<<"Base::yfn(float f)"<<endl; 
	}

	void zfn()
	{
		cout<<"Base::zfn()"<<endl; 
	}
}; 

class Derived : public Base
{
public:
	void xfn(int i)
	{
		cout<<"Derived::xfn(int i)"<<endl; 
	}

	void yfn(int c)
	{
		cout<<"Derived::yfn(int c)"<<endl; 
	}

	void zfn()
	{
		cout<<"Derived::zfn()"<<endl; 
	}
}; 

void main()
{
	Derived d; 
	Base* pB = &d; 
	Derived* pD = &d; 

	pB->xfn(5); 
	pD->xfn(5); 

	pB->yfn(3.14f); 
	pD->yfn(3); 

	pB->zfn(); 
	pD->zfn(); 

	animal * pAn; 
	fish fh; 
	pAn = &fh; 
	pAn->breathe(); 

	int a; 
	cin>>a; 
}