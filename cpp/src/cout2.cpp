#include <iostream>
#include <iomanip>

int main() 
{
    // 整数
    int a = 10;
    std::cout << "整数: a = " << a << std::endl;

    // 浮点数
    double pi = 3.1415926535;
    std::cout << "默认输出六位小数：pi = " << pi << std::endl;
    std::cout << "指定输出两位小数：pi = " << std::fixed << std::setprecision(2) << pi << std::endl;

    // 字符
    char ch = 'A';
    std::cout << "字符：ch = " << ch << std::endl;

    // 字符串
    std::string str = "Hello, World!";
    std::cout << "字符串：str = " << str << std::endl;

    // 指针
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << "数组的地址：arr = " << arr << std::endl;

    return 0;
}