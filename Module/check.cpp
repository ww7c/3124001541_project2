#include "check.h"
#include "random_Fraction.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void check::checkAnswer(
    const string& properAnswerFile,
    const string& userAnswerFile,
    const string& gradeFile)
{
    // 打开正确答案文件
    ifstream properFile(properAnswerFile);

    // 打开用户答案文件
    ifstream userFile(userAnswerFile);

    // 创建批改结果文件
    ofstream gradeFileOut(gradeFile);

    // 检查文件是否打开成功
    if (!properFile.is_open())
    {
        cout << "无法打开正确答案文件："
            << properAnswerFile << endl;
        return;
    }

    if (!userFile.is_open())
    {
        cout << "无法打开用户答案文件："
            << userAnswerFile << endl;
        return;
    }

    if (!gradeFileOut.is_open())
    {
        cout << "无法创建 Grade.txt" << endl;
        return;
    }

    string properAnswer;
    string userAnswer;

    int questionNumber = 0;//题目数量
    int correctCount = 0;//正确数量
    int wrongCount = 0;//错误数量

    string correctQuestions;
    string wrongQuestions;

    // 一行一题，逐题比较
    while (getline(properFile, properAnswer))
    {
        questionNumber++;

        // 读取用户答案
        if (getline(userFile, userAnswer))
        {
            // 去掉 Windows 换行符 \r
            if (!properAnswer.empty() &&
                properAnswer.back() == '\r')
            {
                properAnswer.pop_back();
            }

            if (!userAnswer.empty() &&
                userAnswer.back() == '\r')
            {
                userAnswer.pop_back();
            }

            // 字符串转换成 Fraction
            Fraction proper =
                random_Fraction::tofraction(properAnswer);

            Fraction user =
                random_Fraction::tofraction(userAnswer);

            // 比较两个 Fraction
            if (proper == user)
            {
                // 答案正确
                correctCount++;

                if (!correctQuestions.empty())
                {
                    correctQuestions += ", ";
                }

                correctQuestions += to_string(questionNumber);
            }
            else
            {
                // 答案错误
                wrongCount++;

                if (!wrongQuestions.empty())
                {
                    wrongQuestions += ", ";
                }

                wrongQuestions +=to_string(questionNumber);
            }
        }
        else
        {
            // 用户没有填写答案
            wrongCount++;

            if (!wrongQuestions.empty())
            {
                wrongQuestions += ", ";
            }

            wrongQuestions += to_string(questionNumber);
        }
    }

    // 写入 Grade.txt
    gradeFileOut
        << "Correct: "
        << correctCount
        << " ("
        << correctQuestions
        << ")"
        << endl;

    gradeFileOut
        << "Wrong: "
        << wrongCount
        << " ("
        << wrongQuestions
        << ")"
        << endl;

    // 关闭文件
    properFile.close();
    userFile.close();
    gradeFileOut.close();
    // 控制台输出
    cout << "批改完成！" << endl;
    cout << "正确：" << correctCount << endl;
    cout << "错误：" << wrongCount << endl;
}
