#include"random_expression.h"
#include"random_num.h"
#include"random_operator.h"
#include"random_Fraction.h"
#include<string>
using namespace std;
//声明成员变量
Fraction random_expression::result;

string random_expression::getExpression(int max)
{
	//随机生成运算符数量，范围为1-3
	int operator_count = random_num::getnumber(3) + 1; 
	//生成第一个数
	string nums1 = random_Fraction::getFraction(max);
	Fraction prev_value = random_Fraction::tofraction(nums1);
	//初始化运算结果为0
	Fraction result (0,1);
	//中间存储变量
	Fraction temp = prev_value;
	//表达式变量
	string expression = nums1;
	//存储变量前的运算符号
	string prev_op = "+";

	for(int i=0;i<operator_count;i++)
	{
		string next_op = random_operator::getoperator();//随机生成运算符
		//生成下一个数
		string nums2= random_Fraction::getFraction(max);
		Fraction next_value = random_Fraction::tofraction(nums2);
		//符号判定
		if(next_op == "/" ){
			while (next_value < temp || next_value == temp)
			{//除数<=被除数时
					int minDivisor = temp.getNumerator() / temp.getDenominator() + 1;
					int minnum = 0;
					if (minDivisor >= max) {//不满足除法规则，变为加号运算
						next_op = "+";
						break;
					}
					else {
						minnum = random_num::getnumber(minDivisor, max-1);
						nums2 = to_string(minnum);
						next_value = random_Fraction::tofraction(nums2);
					}
				
			}
				if(next_op=="/") temp = temp / next_value;
		}
		if (next_op == "*")
		{
			temp = temp * next_value;
		}

		if (next_op == "+")
		{
			if(prev_op=="+")
			{
				result = result + temp;//写入结果
			}
			else if (prev_op == "-")
			{
				result = result - temp;//写入结果
			}
			temp = next_value;
			prev_op = "+";
		}

		else if (next_op == "-")
		{
			// 先计算当前已计算的结果
			Fraction currentResult = result;
			if (prev_op == "+")
			{
				currentResult = currentResult + temp;
			}
			else if (prev_op == "-")
			{
				currentResult = currentResult - temp;
			}
			// 暂时判断：
		   // currentResult - next_value >= 0
		   // 如果不满足，就重新生成 value
			while (currentResult < next_value)
			{
				int minnum = currentResult.getNumerator() / currentResult.getDenominator();
				if(minnum<=0)
				{
					//如果被减数<=0，改为加号运算
					next_op = "+";
					break;
				}
				if (minnum > max)
				{
					int temp_value = random_num::getnumber(max);
					nums2 = to_string(temp_value);
					next_value = random_Fraction::tofraction(nums2);
					break;
				}
				else {
					int temp_value = random_num::getnumber(0, minnum);
					nums2 = to_string(temp_value);
					next_value = random_Fraction::tofraction(nums2);
					break;
				}
			}
			// 把前面的 temp 加入 result
			if (prev_op == "+")
			{
				result = result + temp;
			}
			else if (prev_op == "-")
			{
				result = result - temp;
			}
			// 当前数字成为新的 temp
			temp = next_value;
			prev_op = next_op;
		}	 
		//更改表达式
		expression += " " + next_op + " " + nums2;
	}
	//计算最后结果
	if (prev_op == "+")
	{
		result = result + temp;
	}
	if (prev_op == "-")
	{
		result = result - temp;
	}
	//将结果传回类中
	random_expression::result = result;
	//拼接生成完整表达式
	 expression +=" =";

	return expression;
}