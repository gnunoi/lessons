# C++代码调试技巧

## 程序设计是什么

程序设计 = 语言 + 算法 + 数据

## 题目B2007

### 题目描述

在大部分的在线题库中，都会将 A + B 问题作为第一题，以帮助新手熟悉平台的使用方法。

A + B 问题的题目描述如下：给定两个整数 *A* 和 *B*，输出 *A*+*B* 的值。保证 *A*,*B* 及结果均在 32 位整型范围内。

现在请你解决这一问题。

### 输入格式

一行，包含两个整数 *A*,*B*，中间用单个空格隔开。*A* 和 *B* 均在 32 位整型范围内。

### 输出格式

一个整数，即 *A*+*B* 的值。保证结果在 32 位整型范围内。保证答案非负。

### 输入输出样例

**输入 #1**复制

```
1 2
```

**输出 #1**复制

```
3
```

### 说明/提示

对于 100% 的数据，*A*,*B*,*A*+*B* 均在 32 位整型范围内，且 *A*+*B*≥0。

## B2027 计算球的体积

### 题目描述

已知球半径为 $r$ 时，球的体积为 $V=\frac{4}{3}\pi r^3$。

小理手里有个半径为 $r$ 的球体，他现在想知道这个球的体积为多少？

**计算时，取 $\pi = 3.14$**。

### 输入格式

输入共一行，其中包括一个正整数 $r$ 表示球体的半径。

#### 输出格式

输出共一行，其中包括球体的体积。**要求保留小数点后$5$ 位**。

###### 输入输出样例 #1

**输入 #1**

```
5
```

***输出 #1***

```
523.33333
```

### 说明/提示

$1\leq r\leq 100$。

## 程序设计错误

程序设计错误 = 语法错误 / 算法错误 / 数据错误

### 语法错误

常见的语法错误有：

1. 将英文符号输入为中文符号
2. 单词拼写错误
3. 语句结束忘记加分号**";"**

**语法错误的最主要表现就是无法通过编译，无法得到可执行文件。**

**错误案例一**

`B2007`

```cpp
#inclde<iostream>
using namespace std

int main（）
{
  int a, b;
  cin >> a >> b
  cout << a + b
}
```

![C++语法错误调试](png/C++语法错误调试.png)

```
1	2	Z:\Desktop\gnunoi\lessons\cpp\src\B2007-E1.cpp	[Error] invalid preprocessing directive #inclde; did you mean #include?
2	20	Z:\Desktop\gnunoi\lessons\cpp\src\B2007-E1.cpp	[Error] expected ';' before 'int'
6	3	Z:\Desktop\gnunoi\lessons\cpp\src\B2007-E1.cpp	[Error] expected primary-expression before 'int'
6	3	Z:\Desktop\gnunoi\lessons\cpp\src\B2007-E1.cpp	[Error] expected '}' before 'int'
5	1	Z:\Desktop\gnunoi\lessons\cpp\src\B2007-E1.cpp	[Note] to match this '{'
7	3	Z:\Desktop\gnunoi\lessons\cpp\src\B2007-E1.cpp	[Error] 'cin' does not name a type
9	1	Z:\Desktop\gnunoi\lessons\cpp\src\B2007-E1.cpp	[Error] expected declaration before '}' token
```



### 算法错误

计算方法错误，或者程序逻辑错误。复杂算法的错误主要体现在程序的逻辑上。

**算法错误的通常表现就是测试点不能够通过。**

**算法错误案例一**

`B2007`

```cpp
#include<iostream>
using namespace std;
// 计算两数之和
int main()
{
  int a, b;
  cin >> a >> b;
  cout << a - b;
}
```

上面的案例，将加法写成了解法，与结果大相径庭。

![C++算法错误调试](png/C++算法错误调试.png)

**算法错误案例二**

`B2027`

```cpp
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int r;

    cout << fixed << setprecision(5) << 3.14 * 4 / 3 * r * r * r;

    return 0;
}
```



### 数据错误

数据错误中最常见的错误就是数据的边界错误，即：数据的范围错误和临界值处理错误。

**边界错误的最主要表现就是一部分测试点能够通过，另外一部分测试点不能够通过。**

**数据错误案例一**

`B2007`

```cpp
#include<iostream>
using namespace std;
// 计算两数之和
int main()
{
  short int a, b;
  cin >> a >> b;
  cout << a + b;
}
```

![C++数据错误调试](png/C++数据错误调试.png)

`B2027`

使用float浮点数，精度不够，题目要求保留5位小数，float计算后无法保证5为小数的精确度。需要将float改为double。

**数据错误案例二**

```cpp
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int r;
    cin >> r;
    float pi = 3.14;
    double v = 4.0 / 3 * pi * r * r * r;
    cout << fixed << setprecision(5) << v;

    return 0;
}
```

**数据错误案例三**

使用4/3，整数类型除法使用整除法，得不到浮点数。

```cpp
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int r;
    cin >> r;
    cout << fixed << setprecision(5) << 4 / 3 * 3.14 * r * r * r;

    return 0;
}
```
