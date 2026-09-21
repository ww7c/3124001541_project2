#pragma once
#include"Fraction.h"
#include<string>
class random_Fraction {
public:
	//随机生成整数,真分数，带分数
	static std::string getFraction(int max);
	//将字符串转换成fraction类型
	static Fraction tofraction(const std::string& str);

};