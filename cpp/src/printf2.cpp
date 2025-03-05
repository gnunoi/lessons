#include <cstdio>
#include <iostream>

int main() {
    // 整数
    int a = 10;
    printf("整数: a = %d\n", a);

    // 浮点数
    double pi = 3.1415926535;
    printf("默认输出六位小数：pi = %f\n", pi);
    printf("指定输出两位小数：pi = %.2f\n", pi);

    // 字符
    char ch = 'A';
    printf("字符：ch = %c\n", ch);

    // 字符串
    const char* str = "Hello, World!";
    printf("字符串：str = %s\n", str);

    // 指针
    int arr[5] = {1, 2, 3, 4, 5};
    printf("数组的地址：%p\n", arr);

    return 0;
}