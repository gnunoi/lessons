# C++ 循环语句

## 一、循环的作用
在程序中重复执行特定代码块，直到满足终止条件

## 二、for循环

### 1. 语法结构
```cpp
for (初始化表达式; 条件表达式; 更新表达式) {
    // 循环体
}
```

### 2. 执行流程
1. 执行初始化表达式（仅一次）
2. 检查条件表达式
   - 为真：执行循环体 → 执行更新表达式 → 回到步骤2
   - 为假：退出循环

### 3. 适用场景

已知循环次数的情况

### 4. 代码示例
```cpp
#include <iostream>
using namespace std;

int main() {
    // 打印1-10的平方
    for (int i = 1; i <= 10; i++) {
        cout << i << "^2 = " << i*i << endl;
    }
    
    // 嵌套循环示例（九九乘法表）
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << "×" << i << "=" << i*j << "\t";
        }
        cout << endl;
    }
    return 0;
}
```

## 三、while循环
### 1. 语法结构
```cpp
while (条件表达式) {
    // 循环体
    // 需要包含改变条件的语句
}
```

### 2. 执行流程
1. 检查条件表达式
   - 为真：执行循环体 → 回到步骤1
   - 为假：退出循环

### 3. 适用场景
循环次数不确定，需要根据条件判断的情况

### 4. 代码示例
```cpp
#include <iostream>
using namespace std;

int main() {
    // 猜数字游戏
    int target = 42;
    int guess;
    
    cout << "请输入猜测的数字（1-100）：";
    cin >> guess;
    
    while (guess != target) {
        if (guess > target) {
            cout << "太大了！";
        } else {
            cout << "太小了！";
        }
        cout << "请重新输入：";
        cin >> guess;
    }
    
    cout << "恭喜你猜对了！" << endl;
    return 0;
}
```

## 四、do-while循环
### 1. 语法结构
```cpp
do {
    // 循环体
} while (条件表达式);
```

### 2. 执行流程
1. 先执行循环体
2. 检查条件表达式
   - 为真：回到步骤1
   - 为假：退出循环

### 3. 适用场景
需要至少执行一次循环体的情况

### 4. 代码示例
```cpp
#include <iostream>
using namespace std;

int main() {
    // 菜单系统
    int choice;
    
    do {
        cout << "\n==== 菜单 ====" << endl;
        cout << "1. 开始游戏" << endl;
        cout << "2. 加载存档" << endl;
        cout << "3. 设置" << endl;
        cout << "0. 退出" << endl;
        cout << "请输入选项：";
        cin >> choice;
        
        // 处理用户选择
        switch(choice) {
            case 1: /* 游戏逻辑 */ break;
            case 2: /* 加载逻辑 */ break;
            case 3: /* 设置逻辑 */ break;
            case 0: cout << "再见！" << endl; break;
            default: cout << "无效输入！" << endl;
        }
    } while (choice != 0);
    
    return 0;
}
```

## 五、循环控制语句
1. `break`：立即终止当前循环
2. `continue`：跳过当前迭代，进入下一次循环
3. 注意事项：
   - 谨慎使用可能造成无限循环
   - 确保循环条件最终会变为假

## 六、循环选择指南
| 循环类型 | 适用场景         | 特点             |
| -------- | ---------------- | ---------------- |
| for      | 已知循环次数     | 结构紧凑         |
| while    | 条件控制循环     | 可能一次都不执行 |
| do-while | 必须至少执行一次 | 先执行后判断     |

## 七、常见问题
1. 无限循环的两种形式：
   ```cpp
   for (;;) { /* ... */ }  // 合法但危险
   while (true) { /* ... */ }
   ```

2. 循环变量作用域：
   - for循环的初始化变量只在循环内有效（C++11及以后）
   - while循环需要在外部声明变量

3. 效率考虑：
   - 避免在循环条件中进行复杂计算
   - 提前计算好循环不变量

---

这份讲稿包含了理论说明、代码示例和实用建议，可根据听众水平调整讲解深度。建议配合实际编程演示和练习题目进行教学。