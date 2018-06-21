#pragma once
#include<iostream>
using std::cout;
using std::endl;

struct Number;
struct BinaryOperation;

struct Expression
{
	virtual double evaluate() const = 0;
	virtual ~Expression() = default;
};

struct Number : Expression
{
	Number(double value);
	~Number();
	double evaluate() const;

	double get_value() const;
private:
	double value;
};

struct BinaryOperation : Expression
{
	~BinaryOperation();
	BinaryOperation(Expression const * left, char op, Expression const * right);

	double evaluate() const;

	Expression const * get_left() const;
	Expression const * get_right() const;
	char get_op() const;

private:
	Expression const * left;
	Expression const * right;
	char op;
};

Number::Number(double value)
	: value(value)
{}
Number::~Number() {
	cout << "~Number" << endl;
}
double Number::evaluate() const {
	return value;
}

double Number::get_value() const { return value; }

BinaryOperation::~BinaryOperation() {
	cout << "~BinaryOperation" << endl;
	delete left;
	delete right;
}

BinaryOperation::BinaryOperation(Expression const * left, char op, Expression const * right)
	: left(left), op(op), right(right)
{ }

double BinaryOperation::evaluate() const {
	switch (op) {
	case '+': return left->evaluate() + right->evaluate();
	case '-': return left->evaluate() - right->evaluate();
	case '*': return left->evaluate() * right->evaluate();
	case '/': return left->evaluate() / right->evaluate();
	default: return 0.0;
	}
}

Expression const * BinaryOperation::get_left() const { return left; }
Expression const * BinaryOperation::get_right() const { return right; }
char BinaryOperation::get_op() const { return op; }