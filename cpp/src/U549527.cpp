#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}