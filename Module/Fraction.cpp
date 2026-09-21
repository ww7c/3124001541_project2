#include"Fraction.h"
#include<string>
using namespace std;
//构造函数
Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
	simplify();
}
//求最大公约数
 static int gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
//约分
void Fraction::simplify()
{
	int div = gcd(numerator, denominator);
	if (div != 0) {
		numerator /= div;
		denominator /= div;
	}
}
//重构运算符
//分数加法
Fraction Fraction::operator+(const Fraction& other) const {
	int new_numerator = numerator * other.denominator + other.numerator * denominator;
	int new_denominator = denominator * other.denominator;
	Fraction result(new_numerator, new_denominator);
	return result;
}
//分数减法
Fraction Fraction::operator-(const Fraction& other) const {
	int new_numerator = numerator * other.denominator - other.numerator * denominator;
	int new_denominator = denominator * other.denominator;
	Fraction result(new_numerator, new_denominator);
	return result;
}	
//分数乘法
Fraction Fraction::operator*(const Fraction& other) const {
	int new_numerator = numerator * other.numerator;
	int new_denominator = denominator * other.denominator;
	Fraction result(new_numerator, new_denominator);
	return result;
}
//分数除法
Fraction Fraction::operator/(const Fraction& other) const {
	int new_numerator = numerator * other.denominator;
	int new_denominator = denominator * other.numerator;
	Fraction result(new_numerator, new_denominator);
	return result;
}	
//分数比较
bool Fraction::operator<(const Fraction& other) const {
	return numerator * other.denominator < denominator * other.numerator;
}

bool Fraction::operator==(const Fraction& other)const {
	return numerator * other.denominator == denominator * other.numerator;
}

//获取分子
int Fraction::getNumerator()const
{
	return numerator;
}
//获取分母
int Fraction::getDenominator()const
{
	return denominator;
}	
//判断是否为真分数
bool Fraction::proper_Fraction()const
{
	return numerator < denominator;
}
//分数转字符串
string Fraction::toString() {
	if (denominator == 1) {
		return to_string(numerator);
	}
	if (numerator<denominator) {
		return to_string(numerator) + "/" + to_string(denominator);
	}
	//处理带分数
	int front = numerator / denominator;
	int back = numerator % denominator;
	return to_string(front) + "'" + to_string(back) + "/" + to_string(denominator);
}


