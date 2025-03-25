`strstr` 是C语言中的一个标准库函数，用于在字符串中查找子字符串。在C++中，也可以通过包含 `<cstring>` 头文件来使用这个函数。

### 函数原型
```cpp
char *strstr(const char *haystack, const char *needle);
```

### 参数说明
- `haystack`：主字符串，要在其中进行搜索的字符串。
- `needle`：子字符串，要在主字符串中查找的字符串。

### 返回值
- 如果找到子字符串，则返回指向主字符串中子字符串第一个字符的指针。
- 如果未找到子字符串，则返回空指针 `nullptr`。

### 示例代码
```cpp
#include <iostream>
#include <cstring>

int main() {
    const char *str = "Hello, World!";
    const char *substr = "World";

    // 使用 strstr 查找子字符串
    const char *result = strstr(str, substr);

    if (result != nullptr) {
        std::cout << "子字符串找到，位置在: " << result - str << std::endl;
        std::cout << "子字符串是: " << result << std::endl;
    } else {
        std::cout << "子字符串未找到" << std::endl;
    }

    return 0;
}
```

### 输出结果
```
子字符串找到，位置在: 7
子字符串是: World!
```

### 注意事项
1. `strstr` 函数对大小写敏感，因此在查找时需要确保大小写一致。
2. 如果子字符串为空字符串（即 `""`），`strstr` 会返回主字符串的起始位置。
3. 这个函数只适用于C风格的字符串（以 `\0` 结尾的字符数组），不适用于 `std::string` 类型。如果需要对 `std::string` 进行操作，可以使用 `std::string` 的 `find` 方法。