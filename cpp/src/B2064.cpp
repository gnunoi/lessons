#include<iostream>
using namespace std;

int Fibonacci(int n)
{
    if (n == 1 || n == 2) return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cout << Fibonacci(a) << endl;
    }
    
    return 0;
}