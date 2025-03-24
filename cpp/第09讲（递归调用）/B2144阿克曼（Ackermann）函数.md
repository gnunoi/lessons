# B2144 阿克曼（Ackermann）函数

## 题目描述

阿克曼（Ackermann）函数 $A(m,n)$ 中，$m, n$ 定义域是非负整数（$m \le 3$，$n \le 10$），函数值定义为：

$\mathit{akm}(m,n)=n+1$；（$m=0$ 时）。

$\mathit{akm}(m,n)=\mathit{akm}(m-1,1)$；（$m>0$、$n=0$ 时）。

$\mathit{akm}(m,n)=\mathit{akm}(m-1,\mathit{akm}(m,n-1))$；（$m,n>0$ 时）。

## 输入格式

$m$ 和 $n$。

## 输出格式

函数值。

## 输入输出样例 #1

### 输入 #1

```
2 3
```

### 输出 #1

```
9
```

## 代码

```cpp
#include<iostream>
using namespace std;

int A(int m, int n)
{
    if (m == 0) return n+1;
    if(m > 0 && n == 0) return A(m-1, 1);
    return A(m-1, A(m, n-1));
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << A(m, n) << endl;
    return 0;
}
```

