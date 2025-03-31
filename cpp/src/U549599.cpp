#include <iostream>

using namespace std;
typedef unsigned long long ull;

ull fibonacci(int n) 
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    ull a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() 
{
    int n;
    cin >> n;
    
    cout << fibonacci(n) << endl;
    
    return 0;
}