#include <iostream>
#include <cwchar>    // 用于wchar_t类型
#include <iostream>
#include <cwchar>    // 用于wchar_t类型
#include <cuchar>    // 用于char16_t/char32_t类型

using namespace std;

typedef struct {
    const char *name;
    int size;
} s_type;

s_type type_array[]={
    {"bool", sizeof(bool)},
    {"char", sizeof(char)},
    {"unsigned char", sizeof(unsigned char)},
    {"short", sizeof(short)},
    {"unsigned short", sizeof(unsigned short)},
    {"int", sizeof(int)},
    {"unsigned int", sizeof(unsigned int)},
    {"long", sizeof(long)},
    {"unsigned long", sizeof(unsigned long)},
    {"long long", sizeof(long long)},
    {"unsigned long long", sizeof(unsigned long long)},
    {"float", sizeof(float)},
    {"double", sizeof(double)},
    {"long double", sizeof(long double)},
    {"wchar_t", sizeof(wchar_t)},
    {"char16_t", sizeof(char16_t)},
    {"char32_t", sizeof(char32_t)},
};

int print_type2() 
{
    for (int i = 0; i < sizeof(type_array) / sizeof(s_type); i++){
        cout << type_array[i].name << ": " << type_array[i].size << "字节" << endl;
    }
    return 0;
}

int main()
{
    print_type2();
    return 0;
}