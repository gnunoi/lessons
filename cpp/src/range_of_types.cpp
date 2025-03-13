#include <iostream>
#include <limits>

using namespace std;

int main() 
{
    cout << "基本数据类型的最大最小值：" << endl << endl;

    // char类型处理
    cout << "char:" << endl;
    cout << "    最大值: " << static_cast<int>(numeric_limits<char>::max()) << endl;
    cout << "    最小值: " << static_cast<int>(numeric_limits<char>::lowest()) << endl << endl;

    cout << "signed char:" << endl;
    cout << "    最大值: " << static_cast<int>(numeric_limits<signed char>::max()) << endl;
    cout << "    最小值: " << static_cast<int>(numeric_limits<signed char>::lowest()) << endl << endl;

    cout << "unsigned char:" << endl;
    cout << "    最大值: " << static_cast<int>(numeric_limits<unsigned char>::max()) << endl;
    cout << "    最小值: " << static_cast<int>(numeric_limits<unsigned char>::lowest()) << endl << endl;

    // 整型处理
    cout << "short:" << endl;
    cout << "    最大值: " << numeric_limits<short>::max() << endl;
    cout << "    最小值: " << numeric_limits<short>::lowest() << endl << endl;

    cout << "unsigned short:" << endl;
    cout << "    最大值: " << numeric_limits<unsigned short>::max() << endl;
    cout << "    最小值: " << numeric_limits<unsigned short>::lowest() << endl << endl;

    cout << "int:" << endl;
    cout << "    最大值: " << numeric_limits<int>::max() << endl;
    cout << "    最小值: " << numeric_limits<int>::lowest() << endl << endl;

    cout << "unsigned int:" << endl;
    cout << "    最大值: " << numeric_limits<unsigned int>::max() << endl;
    cout << "    最小值: " << numeric_limits<unsigned int>::lowest() << endl << endl;

    cout << "long:" << endl;
    cout << "    最大值: " << numeric_limits<long>::max() << endl;
    cout << "    最小值: " << numeric_limits<long>::lowest() << endl << endl;

    cout << "unsigned long:" << endl;
    cout << "    最大值: " << numeric_limits<unsigned long>::max() << endl;
    cout << "    最小值: " << numeric_limits<unsigned long>::lowest() << endl << endl;

    cout << "long long:" << endl;
    cout << "    最大值: " << numeric_limits<long long>::max() << endl;
    cout << "    最小值: " << numeric_limits<long long>::lowest() << endl << endl;

    cout << "unsigned long long:" << endl;
    cout << "    最大值: " << numeric_limits<unsigned long long>::max() << endl;
    cout << "    最小值: " << numeric_limits<unsigned long long>::lowest() << endl << endl;

    // 宽字符类型
    cout << "wchar_t:" << endl;
    cout << "    最大值: " << static_cast<long long>(numeric_limits<wchar_t>::max()) << endl;
    cout << "    最小值: " << static_cast<long long>(numeric_limits<wchar_t>::lowest()) << endl << endl;

    // 浮点型处理
    cout << "float:" << endl;
    cout << "    最大值: " << numeric_limits<float>::max() << endl;
    cout << "    最小值: " << numeric_limits<float>::lowest() << endl << endl;

    cout << "double:" << endl;
    cout << "    最大值: " << numeric_limits<double>::max() << endl;
    cout << "    最小值: " << numeric_limits<double>::lowest() << endl << endl;

    cout << "long double:" << endl;
    cout << "    最大值: " << numeric_limits<long double>::max() << endl;
    cout << "    最小值: " << numeric_limits<long double>::lowest() << endl;

    return 0;
}