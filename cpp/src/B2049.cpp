#include<iostream>
using namespace std;

int main()
{
    int a, b, c, r;
    cin >> a >> b >> c;

    if (a > b) 
        r = a;
    else 
        r = b;
    if (r < c) r = c;

    cout << r;

    return 0;
}