#include"random_Fraction.h"
#include<random>
#include"random_num.h"
#include"Fraction.h"
using namespace std;

string random_Fraction::getFraction(int max)
{
	int index = random_num::getnumber(0, 1);
	if (index == 0)
	{
		int result = random_num::getnumber(max);
		return to_string(result);
	}
    else if (index == 1)
	{
        int denominator = random_num::getnumber(2, max);
        int numerator = random_num::getnumber(1, denominator - 1);
        return to_string(numerator) + "/" + to_string(denominator);
	}
	/*else {
		int num1 = random_num::getnumber(1, max - 1);
		int denominator = random_num::getnumber(2, max - 1);
		int numerator = random_num::getnumber(1, denominator - 1);

		return to_string(num1) + "'" + to_string(numerator) + "/" + to_string(denominator);
	}*/
}

 Fraction random_Fraction:: tofraction(const string& str)
{
    //转化为假分数
    size_t pos = str.find('\'');

    if (pos != string::npos)
    {
        // 整数部分
        int integerPart = stoi(str.substr(0, pos));

        // 找到 /
        size_t div_pos = str.find('/', pos);

        // 分子
        int numerator = stoi(
            str.substr( pos + 1,div_pos - pos - 1)
        );

        // 分母
        int denominator = stoi(
            str.substr(div_pos + 1)
        );

        // 带分数转换成假分数
        int newNumerator =
            integerPart * denominator + numerator;

        return Fraction(newNumerator, denominator);
    }

    //转为真分数
    size_t div_pos = str.find('/');

    if (div_pos != string::npos)
    {
        int numerator = stoi(
            str.substr(0, div_pos)
        );

        int denominator = stoi(
            str.substr(div_pos + 1)
        );

        return Fraction(numerator, denominator);
    }

    //转为整数
    int num = stoi(str);

    return Fraction(num, 1);
}