# C++基本数据类型的最值

## 源代码

以下是用于显示C++基本数据类型的最大值和最小值的程序：

```cpp
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
```

## **程序说明：**

1. 使用`<limits>`头文件中的`numeric_limits`模板类获取极值信息
2. 对char相关类型进行整型转换以避免输出ASCII字符
3. 对wchar_t使用long long转换确保能正确显示大数值
4. 浮点型直接输出，自动处理科学计数法显示
5. 所有类型统一使用`max()`和`lowest()`方法获取极值
6. 输出格式采用层级缩进增强可读性

注意：实际输出值会根据编译器和操作系统位数有所不同（如32位/64位系统）。

## 输出

```
基本数据类型的最大最小值：

char:
    最大值: 127
    最小值: -128

signed char:
    最大值: 127
    最小值: -128

unsigned char:
    最大值: 255
    最小值: 0

short:
    最大值: 32767
    最小值: -32768

unsigned short:
    最大值: 65535
    最小值: 0

int:
    最大值: 2147483647
    最小值: -2147483648

unsigned int:
    最大值: 4294967295
    最小值: 0

long:
    最大值: 9223372036854775807
    最小值: -9223372036854775808

unsigned long:
    最大值: 18446744073709551615
    最小值: 0

long long:
    最大值: 9223372036854775807
    最小值: -9223372036854775808

unsigned long long:
    最大值: 18446744073709551615
    最小值: 0

wchar_t:
    最大值: 2147483647
    最小值: -2147483648

float:
    最大值: 3.40282e+38
    最小值: -3.40282e+38

double:
    最大值: 1.79769e+308
    最小值: -1.79769e+308

long double:
    最大值: 1.18973e+4932
    最小值: -1.18973e+4932
```

## C语言格式的源代码

```cpp
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <wchar.h>

int main() 
{
    printf("基本数据类型的最大最小值：\n\n");

    // 字符类型
    printf("char:\n");
    printf("    最大值: %d\n", CHAR_MAX);
    printf("    最小值: %d\n\n", CHAR_MIN);

    printf("signed char:\n");
    printf("    最大值: %d\n", SCHAR_MAX);
    printf("    最小值: %d\n\n", SCHAR_MIN);

    printf("unsigned char:\n");
    printf("    最大值: %u\n\n", UCHAR_MAX);

    // 整型
    printf("short:\n");
    printf("    最大值: %hd\n", SHRT_MAX);
    printf("    最小值: %hd\n\n", SHRT_MIN);

    printf("unsigned short:\n");
    printf("    最大值: %hu\n\n", USHRT_MAX);

    printf("int:\n");
    printf("    最大值: %d\n", INT_MAX);
    printf("    最小值: %d\n\n", INT_MIN);

    printf("unsigned int:\n");
    printf("    最大值: %u\n\n", UINT_MAX);

    printf("long:\n");
    printf("    最大值: %ld\n", LONG_MAX);
    printf("    最小值: %ld\n\n", LONG_MIN);

    printf("unsigned long:\n");
    printf("    最大值: %lu\n\n", ULONG_MAX);

    printf("long long:\n");
    printf("    最大值: %lld\n", LLONG_MAX);
    printf("    最小值: %lld\n\n", LLONG_MIN);

    printf("unsigned long long:\n");
    printf("    最大值: %llu\n\n", ULLONG_MAX);
    printf("    最大值: %llu\n\n", ULLONG_MIN);

    // 宽字符类型
    printf("wchar_t:\n");
    printf("    最大值: %d\n", WCHAR_MAX);
    printf("    最小值: %d\n\n", WCHAR_MIN);

    // 浮点型
    printf("float:\n");
    printf("    最大值: %e\n", FLT_MAX);
    printf("    最小值: %e\n\n", FLT_MIN);  // 注意C标准没有直接提供负最大值宏

    printf("double:\n");
    printf("    最大值: %e\n", DBL_MAX);
    printf("    最小值: %e\n\n", DBL_MIN);

    printf("long double:\n");
    printf("    最大值: %Le\n", LDBL_MAX);
    printf("    最小值: %Le\n", LDBL_MIN);

    return 0;
}
```

## 输出

```
基本数据类型的最大最小值：

char:
    最大值: 127
    最小值: -128

signed char:
    最大值: 127
    最小值: -128

unsigned char:
    最大值: 255

short:
    最大值: 32767
    最小值: -32768

unsigned short:
    最大值: 65535

int:
    最大值: 2147483647
    最小值: -2147483648

unsigned int:
    最大值: 4294967295

long:
    最大值: 9223372036854775807
    最小值: -9223372036854775808

unsigned long:
    最大值: 18446744073709551615

long long:
    最大值: 9223372036854775807
    最小值: -9223372036854775808

unsigned long long:
    最大值: 18446744073709551615

wchar_t:
    最大值: 2147483647
    最小值: -2147483648

float:
    最大值: 3.402823e+38
    最小值: 1.175494e-38

double:
    最大值: 1.797693e+308
    最小值: 2.225074e-308

long double:
    最大值: 1.189731e+4932
    最小值: 3.362103e-4932
```

