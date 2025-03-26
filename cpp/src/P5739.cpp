#include <iostream>

using namespace std;

long long factorial(unsigned long n){
    if(n == 1) return 1;
    else return n*factorial(n-1);
}

int main()
{
    unsigned long n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}