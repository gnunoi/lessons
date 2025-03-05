// B2142 求 1+2+3+...+N 的值
// 用递归的方法求 1+2+3+ …… +N 的值。

#include<iostream>
using namespace std;

int sigma(int n)
{
    if (n == 1) return 1;
    return sigma(n - 1) + n;
}

int main()
{
    int N;
    cin >> N;
    cout << sigma(N) << endl;
    return 0;
}