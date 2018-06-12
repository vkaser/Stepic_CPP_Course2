#include<iostream>
using namespace std;

struct Base {  
	int a{0};
};

struct D1 : Base { 
	int a{1};
};

struct D2 : Base { 
	int a{2};
};

struct D3 : D1, D2 { 
	int a{3};
};

Base const * D1BaseToD2Base(Base const * base)
{
	return (Base const *)(D2 *)(D3 *)(D1 *)base;
}


void main() {
	D3 d3;
	D1 &d1 = d3;
	Base const * base = &d1;
	cout << ((D1 *)base)->a << endl;

	D1 *pd1 = (D1 *)base;
	D3 *pd3 = (D3 *)pd1;
	D2 *pd2 = (D2 *)pd3;
	cout << pd2->a << endl;

	Base const * d2base = D1BaseToD2Base(base);
	cout << ((D2 *)d2base)->a << endl;

};