#include <iostream>
using namespace std;

// 浮点数向0舍入
int main()
{
    // 双精度浮点数
    double x;
    cin >> x;
    
    // 输出：长长整型
    printf("%lld", (long long)x);
    
    return 0;
}