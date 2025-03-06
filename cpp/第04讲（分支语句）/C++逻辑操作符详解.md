# C++ 逻辑操作符详解

## 目录
1. 逻辑操作符简介
2. 逻辑与（&&）
3. 逻辑或（||）
4. 逻辑非（!）
5. 短路求值特性
6. 真值表
7. 示例代码
8. 常见错误

## 逻辑操作符简介
用于组合/修改布尔表达式，常用于条件判断。C++提供三个逻辑操作符：
- `&&`（逻辑与）
- `||`（逻辑或）
- `!`（逻辑非）


## 逻辑与（&&）
- **语法**：`表达式1 && 表达式2`
- **规则**：仅当两个操作数都为`true`时返回`true`
- **示例**：
```cpp
(age >= 18) && (hasID == true)// 判断是否成年且持有身份证
```

## 逻辑或（||）
- **语法**：`表达式1 || 表达式2`
- **规则**：任意一个操作数为`true`即返回`true`
- **示例**：
```cpp
(temperature < 0) || (temperature > 100)// 判断温度是否异常
```

## 逻辑非（!）
- **语法**：`!表达式`
- **规则**：反转布尔值（真变假，假变真）
- **示例**：
```cpp
!isDoorLocked// 门未锁定时为true
```

## 短路求值特性
- **重要特性**：当表达式结果可以确定时，停止后续计算
- `&&`：遇到第一个`false`即停止
- `||`：遇到第一个`true`即停止
- **优势**：
- 提升性能
- 避免无效操作（如指针判空后访问）

---

## 真值表
| A | B| A && B | A \|\| B | !A |
| :-----: | :-----: | :-----: | :-----: | :-----: |
| true| true| true | true | false |
| true| false | false| true | false |
| false | true| false| true | true|
| false | false | false| false | true|

---

## 示例代码
```cpp
#include <iostream>
using namespace std;

bool check(int value) 
{
cout << "Checking " << value << "... ";
return value > 10;
}

int main() 
{
int x = 5, y = 20;

// 逻辑与（&&）示例
cout << "Logical AND (&&):\n";
if (check(x) && check(y)) {
cout << "Both values are valid\n";
} else {
cout << "At least one value is invalid\n";
}

// 逻辑或（||）示例
cout << "\nLogical OR (||):\n";
if (check(x) || check(y)) {
cout << "At least one value is valid\n";
}

// 逻辑非（!）示例
cout << "\nLogical NOT (!):\n";
bool isOpen = false;
if (!isOpen) {
cout << "The door is closed\n";
}

// 短路求值演示
cout << "\nShort-circuit evaluation:\n";
int* ptr = nullptr;
if (ptr != nullptr && *ptr > 0) {// 安全访问
cout << "Valid pointer value";
} else {
cout << "Invalid pointer or value";
}

return 0;
}
```

**输出结果**：
```
Logical AND (&&):
Checking 5... At least one value is invalid

Logical OR (||):
Checking 5... Checking 20... At least one value is valid

Logical NOT (!):
The door is closed

Short-circuit evaluation:
Invalid pointer or value
```

## 常见错误
1. **混淆位操作符**：
```cpp
if (a & b) // 位与操作（通常需要写成 a && b）
```

2. **错误优先级**：
```cpp
if (a || b && c) // && 优先级高于||，实际为 a || (b && c)
```

3. **冗余判断**：
```cpp
if (isValid == true) → 应简化为 if (isValid)
```

4. **误用逻辑非**：
```cpp
if (!x > 5)// 实际解析为 (!x) > 5
```

## 总结
- 使用逻辑操作符构建复杂条件判断
- 利用短路特性优化代码安全性和效率
- 注意操作符优先级（建议使用括号明确优先级）
- 区分逻辑操作符和位操作符

通过合理使用逻辑操作符，可以编写出更清晰、高效的C++代码。