// B2085 第 n 小的质数
#include<iostream>
#include<cmath>
using namespace std;

bool is_prime(int n)
{
    if (n < 2) return false;
    int root = sqrt(n);
    for(int i = 2; i <= root; i++) if (n % i == 0) return false;
    return true;
}

int main()
{
    int n, m, i;
    cin >> n;
    for(i = 1, m = 2;i <= n;m++) if(is_prime(m)) i++;
    cout << m - 1 << endl;
    return 0;
}