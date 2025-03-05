#include <iostream>
#include <cwchar>    // 用于wchar_t类型
#include <iostream>
#include <cwchar>    // 用于wchar_t类型
#include <cuchar>    // 用于char16_t/char32_t类型

using namespace std;

int print_type1() 
{
    cout << "C++基础类型在当前系统的存储宽度：\n";
    cout << "==================================\n";

    // 布尔类型
    cout << "1. 布尔型:\n";
    cout << "bool: " << sizeof(bool) << " 字节 (" << sizeof(bool)*8 << " 位)\n\n";

    // 字符类型
    cout << "2. 字符类型:\n";
    cout << "char: " << sizeof(char) << " 字节 (" << sizeof(char)*8 << " 位)\n";
    cout << "unsigned char: " << sizeof(unsigned char) << " 字节 (" << sizeof(unsigned char)*8 << " 位)\n\n";

    // 整型家族
    cout << "3. 整型:\n";
    cout << "short: " << sizeof(short) << " 字节 (" << sizeof(short)*8 << " 位)\n";
    cout << "unsigned short: " << sizeof(unsigned short) << " 字节 (" << sizeof(unsigned short)*8 << " 位)\n";
    cout << "int: " << sizeof(int) << " 字节 (" << sizeof(int)*8 << " 位)\n";
    cout << "unsigned int: " << sizeof(unsigned int) << " 字节 (" << sizeof(unsigned int)*8 << " 位)\n";
    cout << "long: " << sizeof(long) << " 字节 (" << sizeof(long)*8 << " 位)\n";
    cout << "unsigned long: " << sizeof(unsigned long) << " 字节 (" << sizeof(unsigned long)*8 << " 位)\n";
    cout << "long long: " << sizeof(long long) << " 字节 (" << sizeof(long long)*8 << " 位)\n";
    cout << "unsigned long long: " << sizeof(unsigned long long) << " 字节 (" << sizeof(unsigned long long)*8 << " 位)\n\n";

    // 浮点类型
    cout << "4. 浮点型:\n";
    cout << "float: " << sizeof(float) << " 字节 (" << sizeof(float)*8 << " 位)\n";
    cout << "double: " << sizeof(double) << " 字节 (" << sizeof(double)*8 << " 位)\n";
    cout << "long double: " << sizeof(long double) << " 字节 (" << sizeof(long double)*8 << " 位)\n\n";

    // 宽字符类型
    cout << "5. 宽字符型:\n";
    cout << "wchar_t: " << sizeof(wchar_t) << " 字节 (" << sizeof(wchar_t)*8 << " 位)\n";
    cout << "char16_t: " << sizeof(char16_t) << " 字节 (" << sizeof(char16_t)*8 << " 位)\n";
    cout << "char32_t: " << sizeof(char32_t) << " 字节 (" << sizeof(char32_t)*8 << " 位)\n\n";

    // 平台差异说明
    cout << "注意事项：\n";
    cout << "- long类型在Windows中通常为4字节，在Linux/macOS中为8字节\n";
    cout << "- long double的大小可能因编译器而异（常见8/12/16字节）\n";
    cout << "- wchar_t在Windows中为2字节，在Linux中通常为4字节\n";

    return 0;
}

int main()
{
    print_type1();
    return 0;
}