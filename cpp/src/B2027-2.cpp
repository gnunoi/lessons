#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double r;
    cin >> r;
    cout << fixed << setprecision(5) << 4.0/3*3.14*r*r*r;
    return 0;
}