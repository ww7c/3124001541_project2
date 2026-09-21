#include<iostream>
#include"input_parameters.h"
using namespace std;
void input_parameters::input()
{
	cout << "请输入题目数量:";
	cin >> numbers;
	cout << "请输入数字范围:";
	cin >> maxnumbers;
}