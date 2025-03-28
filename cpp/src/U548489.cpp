#include <iostream>
using namespace std;

int main() 
{
    int n;
    // cout << "请输入一个正整数n (0 ≤ n < 1000): ";
    cin >> n;
    
    // 使用模运算的性质来计算10^n mod 7
    int result = 1; // 10^0 mod 7 = 1
    for (int i = 0; i < n; i++) {
        result = (result * 10) % 7; // 每次乘10后取模7
    }
    
    cout << result << endl;
    return 0;
}