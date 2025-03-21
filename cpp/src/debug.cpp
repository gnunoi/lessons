#include<iostream>
#include<iomanip>
using namespace std;

#define DEBUG 1 // 提交代码时，将1修改为0.
#if defined(DEBUG) && (DEBUG >= 1)
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
        d("%d: %lld, %Lf\n", i, fac, e);
    }
    cout << fixed << setprecision(10) << e << endl;
    return 0;
}

long long factorial(int n)
{
    int i = 1;
    long long fac = 1;
    
    for (i = 0; i <= n; i++){
        if (i == 0) fac = 1;
		else fac *= i;
        d("%d: %d! = %lld\n", n, i, fac);
    }
    d("%d! = %lld\n", i, fac);
    return fac;
}
