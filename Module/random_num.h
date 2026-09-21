#pragma once
class random_num {
public:
	//生成自然数  （0<=num<max）
	static int getnumber(int max);
	//生成两个数之间的随机数  （min<=num<=max）
	static int getnumber(int min, int max);
};