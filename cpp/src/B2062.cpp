// B2062 乘方计算
// 给出一个整数a和一个正整数n，求乘方a^n

#include<iostream>
using namespace std;

int main()
{
    int a, n, p = 1;
    cin >> a >> n;
    for(int i = 0; i < n; i++) p *= a;
    cout << p << endl;
    return 0;
}