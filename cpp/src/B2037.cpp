#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 2) // 等同于 n%2 == 1
        cout << "odd";
    else
        cout << "even";

    return 0;
}