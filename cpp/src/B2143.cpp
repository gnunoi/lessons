// B2143 进制转换
// 用递归算法将一个十进制整数 X（1≤X≤10^9）转换成任意进制数 M（2≤M≤16，M 为整数）。

#include<iostream>
using namespace std;

void f(int x, int m)
{
    char c[] = "0123456789ABCDEF";
    if (x / m) f(x / m, m);
    cout << c[x % m];
}

int main()
{
    int X, M;
    cin >> X >> M;
    f(X, M);
    return 0;
}