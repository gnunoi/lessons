#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 2 == 1 || n % 2 == -1) // 注意负数，C++的取余操作符，余数可能是负数
        cout << "odd";
    else
        cout << "even";

    return 0;
}