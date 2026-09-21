#pragma once
#include "Fraction.h"
#include<string>
class random_expression
{
public:
	//生成表达式
	static Fraction result;
	static std::string getExpression(int max);
};