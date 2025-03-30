#include <iostream>
#include <string>

using namespace std;

// 函数mod：计算两个正整数的余数
int mod(const string& a, int b) 
{
    int remainder = 0;
    for (char digit : a) {
        remainder = (remainder * 10 + (digit - '0')) % b;
    }
    return remainder;
}

int main() 
{
    string a;
    int b;
    
    // 输入两个正整数
    cin >> a >> b;
    
    // 计算余数
    int result = mod(a, b);
    
    // 输出结果
    cout << result << endl;
    
    return 0;
}