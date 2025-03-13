#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

/*
输入：
long double ld = 0.123456789123456789123456789123456789123456789;

输出：
sizeof(float) = 4
十进制有效位数: 6
二进制尾数位数: 24
sizeof(double) = 8
十进制有效位数: 15
二进制尾数位数: 53
sizeof(long double) = 16
十进制有效位数: 18
二进制尾数位数: 64
f = 0.12345679104328155517578125000000
d = 0.12345678912345678379658409085096
ld = 0.123456789123456783796584090850956272
*/
int main() 
{
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "十进制有效位数: " 
        << numeric_limits<float>::digits10 << endl
        << "二进制尾数位数: " << numeric_limits<float>::digits << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "十进制有效位数: " 
        << numeric_limits<double>::digits10 << endl
        << "二进制尾数位数: " << numeric_limits<double>::digits << endl;
    cout << "sizeof(long double) = " << sizeof(long double) << endl;
    cout << "十进制有效位数: " 
        << numeric_limits<long double>::digits10 << endl
        << "二进制尾数位数: " << numeric_limits<long double>::digits << endl;
    
    float f = 0.123456789123456789123456789123456789123456789;
    double d = 0.123456789123456789123456789123456789123456789;          
    long double ld = 0.123456789123456789123456789123456789123456789;
    cout << fixed << setprecision(32) << "f = " << f << endl;
    cout << fixed << setprecision(32) << "d = " << d << endl;
    cout << fixed << setprecision(36) << "ld = " << ld << endl;

    return 0;
}