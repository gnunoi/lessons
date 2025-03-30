#include <iostream>
using namespace std;

// 自定义函数，计算两个正整数的最大公约数
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() 
{
    int a, b;
    
    // 输入两个正整数
    // cout << "请输入两个正整数: ";
    cin >> a >> b;
    
    // 计算并输出最大公约数
    cout << gcd(a, b) << endl;
    
    return 0;
}