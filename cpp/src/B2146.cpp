// B2146 Hermite 多项式
// 对给定的 x 和正整数 n，求多项式的值。
// 输入 n 和 x 。
// 说明/提示(n≤8，x≤8)
#include<iostream>
using namespace std;

int h(int n, int x)
{
    if (n == 0) return 1;
    if (n == 1) return 2*x;
    return 2 * x * h(n-1, x) - 2 * (n-1) * h(n-2, x);
}

int main()
{
    int n, x;
    cin >> n >> x;
    cout << h(n, x) << endl;
    return 0;
}