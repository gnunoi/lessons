#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i;
    for(i = 2; i < sqrt(n); i++){
        if (n % i == 0)
            cout << n / i;
    }
}