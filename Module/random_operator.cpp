#include"random_operator.h"
#include<random>
using namespace std;
string random_operator::getoperator()
{
	//运算符数组
	static string operators[] = {
		"+", "-", "*", "/"
	};

	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 3);
	return operators[dis(gen)];
}

