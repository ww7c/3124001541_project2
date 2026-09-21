#pragma once
#include <string>
class Fraction
{
private:
    int numerator;      // 分子
    int denominator;    // 分母

    // 约分
    void simplify();

public:
    // 构造函数
    Fraction(int numerator = 0, int denominator = 1);

    // 加减乘除
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    //比较
    bool operator<(const Fraction& other)const;
    bool operator==(const Fraction& other)const;

    // 获取分子和分母
    int getNumerator() const;
    int getDenominator() const;

        // 判断是否是真分数
     bool proper_Fraction() const;

    // 转换成字符串
    std::string toString() ;
};
