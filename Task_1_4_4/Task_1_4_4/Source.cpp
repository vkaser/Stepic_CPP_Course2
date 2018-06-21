#include <typeinfo>
#include "Expression.h"

bool check_equals(Expression const *left, Expression const *right)
{
	return (typeid(*left) == typeid(*right));
}

int main() {
	Number *left = new Number(3);
	Number *right = new Number(5);
	Expression * subExpr = new BinaryOperation(left, '+', right);
	cout << subExpr->evaluate() << endl;
	cout << check_equals(left, right) << endl;
	cout << check_equals(left, subExpr) << endl;
	cout << check_equals(subExpr, right) << endl;
	return 0;
}