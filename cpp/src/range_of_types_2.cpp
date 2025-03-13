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