#include <iostream>  // std::cin, std::cout, std::endl
#include <string>    // string
using namespace std; // 可以省略std::
int main()
{
    string num;
    cin >> num;
    int r = 0; // 定义保存余数的变量
    for (char c : num){
        r = r * 10 + (c - '0');
        cout << r << "的余数是：" << r % 13 << endl;
        r %= 13;
    }
    cout << num << "的余数是：" << r << endl;
    if (r == 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}