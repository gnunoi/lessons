在C++中，可以使用多种方法来实现字符串的逆序操作。以下是几种常见的方法：

### 方法一：使用标准库函数`std::reverse`
C++的标准库提供了`std::reverse`函数，可以方便地对字符串进行逆序操作。

```cpp
#include <iostream>
#include <algorithm> // 包含std::reverse
#include <string>

int main() {
    std::string str = "hello";
    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl; // 输出 "olleh"
    return 0;
}
```

### 方法二：手动交换字符
如果不使用标准库函数，可以通过手动交换字符串首尾的字符来实现逆序。

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "hello";
    int length = str.length();
    for (int i = 0; i < length / 2; ++i) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    std::cout << str << std::endl; // 输出 "olleh"
    return 0;
}
```

### 方法三：使用`std::string`的迭代器
可以利用`std::string`的迭代器，从后向前遍历字符串并构建新的字符串。

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "hello";
    std::string reversed_str;
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        reversed_str += *it;
    }
    std::cout << reversed_str << std::endl; // 输出 "olleh"
    return 0;
}
```

### 方法四：使用C风格字符串
如果处理的是C风格字符串（以'\0'结尾的字符数组），可以使用类似手动交换字符的方法。

```cpp
#include <iostream>
#include <cstring>

int main() {
    char str[] = "hello";
    int length = strlen(str);
    for (int i = 0; i < length / 2; ++i) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    std::cout << str << std::endl; // 输出 "olleh"
    return 0;
}
```

以上方法可以根据具体需求选择使用。`std::reverse`是最简洁和高效的方法，而手动交换字符则有助于理解字符串逆序的原理。