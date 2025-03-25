# C++ string类详解

各位同学，大家好！今天，我将带领大家深入学习C++中的string类。string类是C++标准模板库（STL）的重要组成部分，它为我们处理字符串提供了极大的便利。下面，我们将逐一介绍string类的主要函数。

## 一、构造函数

string类有多种构造函数，用于创建不同形式的字符串对象。

1. **默认构造函数**：创建一个空字符串。

    ```cpp
    string s;
    ```

2. **从C风格字符串构造**：将一个以'\0'结尾的字符数组转换为string对象。

    ```cpp
    const char* cstr = "Hello, World!";
    string s(cstr);
    ```

3. **从另一个string对象构造**：通过拷贝另一个string对象来创建新对象。

    ```cpp
    string s1 = "Original";
    string s2(s1);
    ```

4. **从string对象的子串构造**：从另一个string对象中提取一个子串来构造新对象。

    ```cpp
    string s1 = "Hello, World!";
    string s2(s1, 7, 5); // 从索引7开始，取5个字符，结果为"World"
    ```

5. **重复构造**：用某个字符重复n次来构造字符串。

    ```cpp
    string s(10, 'a'); // 创建一个包含10个'a'的字符串
    ```

## 二、赋值操作

string类提供了多种赋值方式，使我们能够灵活地改变字符串的内容。

1. **基本赋值运算符**：使用'='将一个字符串赋值给另一个字符串。

    ```cpp
    string s1 = "Hello";
    string s2 = "World";
    s2 = s1; // s2现在是"Hello"
    ```

2. **assign()函数**：功能更强大的赋值函数，有多种重载形式。

    - 从C风格字符串赋值：

        ```cpp
        string s;
        s.assign("New string");
        ```

    - 从另一个string对象赋值：

        ```cpp
        string s1 = "Original";
        string s2;
        s2.assign(s1);
        ```

    - 从string对象的子串赋值：

        ```cpp
        string s1 = "Hello, World!";
        string s2;
        s2.assign(s1, 7, 5); // 赋值为"World"
        ```

    - 重复字符赋值：

        ```cpp
        string s;
        s.assign(10, 'a'); // 创建10个'a'
        ```

## 三、访问字符

我们可以使用string类提供的函数来访问字符串中的单个字符。

1. **operator[]**：通过索引访问字符，如果索引超出范围，行为未定义。

    ```cpp
    string s = "Hello";
    char c = s[1]; // c是'e'
    ```

2. **at()函数**：与operator[]类似，但如果索引超出范围，会抛出out_of_range异常。

    ```cpp
    string s = "Hello";
    char c = s.at(1); // c是'e'
    ```

3. **front()和back()函数**：分别获取字符串的第一个和最后一个字符。

    ```cpp
    string s = "Hello";
    char first = s.front(); // 'H'
    char last = s.back(); // 'o'
    ```

## 四、获取字符串长度和大小

1. **size()函数**：返回字符串中字符的数量，不包括结尾的'\0'。

    ```cpp
    string s = "Hello";
    size_t len = s.size(); // len是5
    ```

2. **length()函数**：与size()功能相同。

    ```cpp
    string s = "Hello";
    size_t len = s.length(); // len是5
    ```

3. **empty()函数**：判断字符串是否为空。

    ```cpp
    string s;
    if (s.empty()) {
        cout << "String is empty." << endl;
    }
    ```

## 五、查找与替换

1. **find()函数**：在字符串中查找子串的位置。

    ```cpp
    string s = "Hello, World!";
    size_t pos = s.find("World"); // pos是7
    ```

    如果找不到子串，find()返回string::npos。

2. **rfind()函数**：从字符串的末尾开始查找子串。

    ```cpp
    string s = "Hello, Hello!";
    size_t pos = s.rfind("Hello"); // pos是7
    ```

3. **find_first_of()函数**：查找任意一个指定字符首次出现的位置。

    ```cpp
    string s = "Hello, World!";
    size_t pos = s.find_first_of("o"); // pos是4
    ```

4. **find_last_of()函数**：查找任意一个指定字符最后一次出现的位置。

    ```cpp
    string s = "Hello, World!";
    size_t pos = s.find_last_of("o"); // pos是8
    ```

5. **replace()函数**：替换字符串中的某个范围的内容。

    ```cpp
    string s = "Hello, World!";
    s.replace(7, 5, "there"); // 替换从索引7开始的5个字符为"there"，结果为"Hello, there!"
    ```

## 六、子字符串

**substr()函数**：提取字符串的一个子串。

```cpp
string s = "Hello, World!";
string sub = s.substr(7, 5); // 提取从索引7开始的5个字符，结果为"World"
```

## 七、字符串拼接

1. **+运算符**：用于连接两个字符串。

    ```cpp
    string s1 = "Hello";
    string s2 = "World";
    string s3 = s1 + " " + s2; // s3是"Hello World"
    ```

2. **+=运算符**：将一个字符串追加到另一个字符串的末尾。

    ```cpp
    string s1 = "Hello";
    string s2 = "World";
    s1 += " "; // s1变为"Hello "
    s1 += s2; // s1变为"Hello World"
    ```

3. **append()函数**：功能更强大的追加函数，有多种重载形式。

    - 追加另一个字符串：

        ```cpp
        string s1 = "Hello";
        s1.append(" World"); // s1变为"Hello World"
        ```

    - 追加另一个字符串的子串：

        ```cpp
        string s1 = "Hello";
        string s2 = " World, everyone!";
        s1.append(s2, 7, 9); // 追加从s2索引7开始的9个字符，结果为"Hello everyone"
        ```

    - 追加n个字符：

        ```cpp
        string s = "Hello";
        s.append(3, '!'); // s变为"Hello!!!"
        ```

## 八、比较字符串

string类重载了比较运算符，使我们能够方便地比较两个字符串。

```cpp
string s1 = "apple";
string s2 = "banana";

if (s1 == s2) {
    cout << "Strings are equal." << endl;
} else if (s1 < s2) {
    cout << "s1 comes before s2 lexicographically." << endl;
} else {
    cout << "s2 comes before s1 lexicographically." << endl;
}
```

## 九、输入输出

1. **输入**：使用cin和getline()函数从标准输入读取字符串。

    ```cpp
    string s;
    cout << "Enter a string: ";
    cin >> s; // 读取直到遇到空白字符

    // 或者使用getline()读取整行
    getline(cin, s);
    ```

2. **输出**：使用cout输出字符串。

    ```cpp
    string s = "Hello, World!";
    cout << s << endl;
    ```

## 十、其他常用函数

1. **c_str()函数**：返回一个指向以'\0'结尾的C风格字符串的指针，该指针指向string对象内部的字符数组。

    ```cpp
    string s = "Hello";
    const char* cstr = s.c_str();
    ```

2. **data()函数**：与c_str()类似，但返回的指针可能不包含结尾的'\0'。

    ```cpp
    string s = "Hello";
    char* data = s.data();
    ```

3. **clear()函数**：清空字符串内容，使其长度变为0。

    ```cpp
    string s = "Hello";
    s.clear();
    if (s.empty()) {
        cout << "String is cleared." << endl;
    }
    ```

4. **resize()函数**：改变字符串的大小，如果新大小大于原大小，新位置用指定字符填充（默认是'\0'）。

    ```cpp
    string s = "Hello";
    s.resize(10, 'x'); // s变为"Helloxxxxx"
    ```

5. **insert()函数**：在指定位置插入子串。

    ```cpp
    string s = "Hello, World!";
    s.insert(7, "there "); // 在索引7处插入"there "，结果为"Hello, there World!"
    ```

6. **erase()函数**：删除指定范围的字符。

    ```cpp
    string s = "Hello, World!";
    s.erase(7, 5); // 删除从索引7开始的5个字符，结果为"Hello, !"
    ```

7. **swap()函数**：交换两个字符串的内容。

    ```cpp
    string s1 = "Hello";
    string s2 = "World";
    s1.swap(s2); // 现在s1是"World"，s2是"Hello"
    ```

8. **begin()和end()函数**：返回指向字符串开头和结尾的迭代器，用于遍历字符串。

    ```cpp
    string s = "Hello";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << endl;
    }
    ```

9. **rbegin()和rend()函数**：返回指向字符串末尾和开头的反向迭代器，用于逆序遍历字符串。

    ```cpp
    string s = "Hello";
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it << endl;
    }
    ```

10. **copy()函数**：将字符串的内容复制到一个字符数组中。

    ```cpp
    string s = "Hello";
    char buffer[10];
    s.copy(buffer, 5); // 复制前5个字符到buffer
    buffer[5] = '\0'; // 手动添加结尾符
    cout << buffer << endl; // 输出"Hello"
    ```

通过以上对C++ string类主要函数的详细介绍，我们能够更加熟练地在程序中运用这些功能，高效地处理各种字符串相关的问题。希望这些知识对大家今后的编程实践有所帮助。谢谢大家！