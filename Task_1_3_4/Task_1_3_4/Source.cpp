#include<iostream>
using namespace std;

struct Number {};

struct BigInt : Number
{
	BigInt(int x) : x_(x) {}
private:
	int x_;
};

struct String
{
	explicit String(char const * s) : s_(s) {}
private:
	char const * s_;
};



int main() {
	//BigInt c = static_cast<BigInt>(10000);
	BigInt c = 10000;
	//String d = static_cast<String>("Stepik");
	String d = "Stepik";
	//Number *e = static_cast<Number *>(&c);
	Number *e = &c;
	//BigInt *f = static_cast<BigInt *>(e);
	BigInt *f = e;
	//void * g = static_cast<void *>(f);
	void *g = f;
	//BigInt * h = static_cast<BigInt *>(g);
	BigInt *h = g;
	return 0;
}