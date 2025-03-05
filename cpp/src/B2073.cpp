#include<iostream>
using namespace std;

int main()
{
    int a, b, n, m;
    cin >> a >> b >> n;

    a = a % b;
    for(int i = 1; i <= n; i++){
        m = a * 10 / b;
        // printf("%d %d %d %d\n", i, a*10, b, m);
        a = a * 10 % b;
    }
    cout << m << endl;

    return 0;
}