#include<iostream>
#include<iomanip>
using namespace std;

#define DEBUG // 提交代码是，注释掉此行
#ifdef DEBUG
#define d(...) printf(__VA_ARGS__)
#else
#define d(...) ((void)0)
#endif

long long factorial(int n);

int main()
{
    int n;
    long double e = 0;
    long long fac;
    cin >> n;
    for(int i = 0; i <= n; i++){
        fac = factorial(i);
        e += 1.0/fac;
        // printf("%d: %lld, %Lf\n", i, fac);
    }
    cout << fixed << setprecision(10) << e << endl;
    return 0;
}

long long factorial(int n)
{
    if (n == 0) return 1;
    
    int i = 1;
    long long fac = 1;
    
    for (i = 1; i <= n; i++){
        fac *= i;
        // printf("%d: %d! = %lld\n", n, i, fac);
    }
    // printf("%d! = %lld\n", i, fac);
    return fac;
}