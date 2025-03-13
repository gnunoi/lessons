#include <iostream>
#include <iomanip>
using namespace std;

/*
输入：
float a = 123456789.f;
float b = 123456788.f;
float c = 0.123456789;
float f = 4.0 / 3 * 3.14 * 125;
double d = 4.0 / 3 * 3.14 * 125; 

macos输出：
a = 123456792
b = 123456784
c = 0.123456791
f = 523.333312988
d = 523.333333333

有效精度：一般为6-7位有效数字，这里是7位。
计算以后，精度进一步损失，*125，小数点后精度损失3位，整体仍为7位有效数字，含小数点之前。
*/
int main() {
    float a = 123456789.f;
    float b = 123456788.f;

    // 测试大整数是否能区分
    cout << fixed << setprecision(0);
    cout << "a = " << a << "\n";  // 输出可能相同
    cout << "b = " << b << "\n";

    // 测试小数精度
    float c = 0.123456789f;
    cout << setprecision(9);
    cout << "c = " << c << "\n";  // 输出可能为0.123456785（后几位不精确）

    float f = 4.0 / 3 * 3.14 * 125;
    double d = 4.0 /3 * 3.14 * 125;

    cout << "f = " << fixed << setprecision(9) << f << endl;
    cout << "d = " << fixed << setprecision(9) << d << endl;
    
    return 0;
}