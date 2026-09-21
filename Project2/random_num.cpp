#include "random_num.h"
#include <random>
using namespace std;

int random_num::getnumber(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());

    // 分布范围随参数动态生成
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}
//函数生成一个随机数，小于max
int random_num::getnumber(int max) {
    return getnumber(0, max - 1);
}