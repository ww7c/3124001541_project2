#include<iostream>
#include"input_parameters.h"
#include"random_num.h"
#include"random_operator.h"
#include"random_expression.h"	
#include"Fraction.h"
#include"random_Fraction.h"
#include"check.h"
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	// 生成题目
	// Myapp.exe -n 10 -r 10
	if (argc >= 2 && std::string(argv[1]) == "-n")
	{
		if (argc != 5)
		{
			std::cout << "参数错误！" << std::endl;
			std::cout << "正确格式：Myapp.exe -n 10 -r 10" << std::endl;
			return 1;
		}
		//打开文件
		std::ofstream exerciseFile("exercisefile.txt");
		std::ofstream answerFile("proper_answerfile.txt");
		if (!exerciseFile.is_open() || !answerFile.is_open())
		{
			std::cout << "文件打开失败！" << std::endl;
			return 1;
		}
		//输入参数模块
		input_parameters params;
		params.input();

		for (int i = 1; i <= params.numbers; i++)
		{
			std::string expression = random_expression::getExpression(params.maxnumbers);

			// 写入题目文件
			exerciseFile << expression << std::endl;

			//写入答案文件
			Fraction answer = random_expression::result;
			int numerator = answer.getNumerator();
			int denominator = answer.getDenominator();
			//写入答案为整数
			if (numerator % denominator == 0)
			{
				answerFile << numerator / denominator << std::endl;
			}
			//写入答案为带分数
			else if (numerator > denominator)
			{
				int front = numerator / denominator;
				int back = numerator % denominator;

				answerFile << front << "'"
					<< back << "/"
					<< denominator << std::endl;
			}
			else {
				// //写入答案为真分数
				answerFile << numerator << "/"
					<< denominator << std::endl;
			}
		}
		// 关闭文件
		exerciseFile.close();
		answerFile.close();
		std::cout << "题目和答案生成完成！" << std::endl;
	}


	// 批改答案
	// Myapp.exe -e proper_answerfile.txt -a user_answerfile.txt
	else if (argc >= 2 && string(argv[1]) == "-e")
	{
		if (argc != 5)
		{
			cout << "参数错误！" << endl;
			cout << "正确格式：" << endl;
			cout << "Myapp.exe -e ProperAnswer.txt -a user_answer.txt"
				<< endl;
			return 1;
		}

		string properAnswerFile = argv[2];

		if (string(argv[3]) != "-a")
		{
			cout << "参数错误！缺少 -a" << endl;
			return 1;
		}

		string userAnswerFile = argv[4];

		// 调用批改模块
		check::checkAnswer(
			properAnswerFile,
			userAnswerFile,
			"Grade.txt"
		);
		std::cout << "答案批改完成！" << std::endl;
	}

	// 参数错误
	else
	{
		cout << "参数错误！请重新输入" << endl;
		return 1;
	}


	return 0;
}