#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    int num = 30;
    double value = 1234.5678;

    // 十六进制、宽度8、填充0、大写
    cout << uppercase << hex << showbase << setw(8) << setfill('0') << num << endl; // 输出 0X00001E

    // 科学计数法、精度3位、显示符号
    cout << scientific << showpos << setprecision(3) << value << endl; // 输出 +1.235e+03

    // 表格格式：左对齐，宽度10，填充空格
    cout << left << setfill(' ')
         << setw(10) << "Name" << setw(5) << "Age" << endl
         << setw(10) << "Alice" << setw(5) << 25 << endl;
    // 输出:
    // Name      Age  
    // Alice     25   
    return 0;
}