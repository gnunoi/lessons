#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int r;
    cin >> r;
    double pi = 3.14;
    double v = 4.0 / 3 * pi * r * r * r;
    cout << fixed << setprecision(5) << v;

    return 0;
}
