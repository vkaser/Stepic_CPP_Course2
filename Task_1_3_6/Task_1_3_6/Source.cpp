#include<iostream>
using namespace std;

int main() {
	int a = 27;
	int const b = 412;
	int * pa = &a;

	int const * p1 = pa;
	int * const * p2 = &pa;
	int const ** p3 = &pa;
	int const * const * p4 = &pa;
	return 0;
}