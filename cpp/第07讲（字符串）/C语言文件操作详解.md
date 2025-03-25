# C语言文件操作详解

在C语言中，文件操作是程序设计的重要组成部分，它允许程序与外部文件进行交互，实现数据的持久化存储和读取。C语言提供了标准库函数来处理文件操作，这些函数声明在`stdio.h`头文件中。

## 一、文件指针

在C语言中，对文件的操作是通过文件指针来实现的。文件指针是一个指向`FILE`结构体的指针，`FILE`结构体是标准库定义的，用于维护文件相关状态和信息。

```c
FILE *fp;
```

## 二、文件的打开与关闭

### 打开文件

使用`fopen()`函数可以打开或创建一个文件。函数原型为：

```c
FILE *fopen(const char *filename, const char *mode);
```

- `filename`：要打开的文件名，可以包含路径。
- `mode`：打开文件的模式，常见的模式如下：
  - `"r"`：只读模式打开文本文件，文件必须存在。
  - `"w"`：只写模式打开或创建文本文件，若文件存在则清空。
  - `"a"`：追加模式打开或创建文本文件，写入内容添加到文件末尾。
  - `"rb"`：只读模式打开二进制文件，文件必须存在。
  - `"wb"`：只写模式打开或创建二进制文件，若文件存在则清空。
  - `"ab"`：追加模式打开或创建二进制文件，写入内容添加到文件末尾。

示例：以写入模式打开一个文本文件

```c
FILE *fp = fopen("example.txt", "w");
if (fp == NULL) {
    perror("File open failed"); // 输出错误信息
    return 1;
}
```

### 关闭文件

使用`fclose()`函数关闭文件，释放与文件相关的资源。函数原型为：

```c
int fclose(FILE *fp);
```

示例：

```c
fclose(fp);
```

## 三、文件的读写操作

### 写入文件

#### 格式化输出到文件

使用`fprintf()`函数可以将格式化数据写入文件。函数原型为：

```c
int fprintf(FILE *fp, const char *format, ...);
```

示例：向文件写入格式化字符串

```c
fprintf(fp, "Hello, World! %d %f\n", 123, 3.14);
```

#### 写入字符串到文件

使用`fputs()`函数可以将字符串写入文件。函数原型为：

```c
int fputs(const char *str, FILE *fp);
```

示例：向文件写入字符串

```c
fputs("This is a string.", fp);
```

#### 写入二进制数据到文件

使用`fwrite()`函数可以将二进制数据写入文件。函数原型为：

```c
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *fp);
```

- `ptr`：指向要写入数据的指针。
- `size`：每个数据项的大小，以字节为单位。
- `count`：要写入的数据项个数。

示例：向文件写入二进制数据

```c
int data[] = {1, 2, 3, 4, 5};
fwrite(data, sizeof(int), 5, fp);
```

### 读取文件

#### 从文件读取格式化输入

使用`fscanf()`函数可以从文件读取格式化数据。函数原型为：

```c
int fscanf(FILE *fp, const char *format, ...);
```

示例：从文件读取格式化数据

```c
int num;
float f;
fscanf(fp, "%d %f", &num, &f);
```

#### 从文件读取字符串

使用`fgets()`函数可以从文件读取字符串。函数原型为：

```c
char *fgets(char *str, int n, FILE *fp);
```

- `str`：存储读取字符串的缓冲区。
- `n`：要读取的最大字符数，包括结尾的空字符。

示例：从文件读取字符串

```c
char buffer[100];
fgets(buffer, 100, fp);
```

#### 从文件读取二进制数据

使用`fread()`函数可以从文件读取二进制数据。函数原型为：

```c
size_t fread(void *ptr, size_t size, size_t count, FILE *fp);
```

- `ptr`：存储读取数据的指针。
- `size`：每个数据项的大小，以字节为单位。
- `count`：要读取的数据项个数。

示例：从文件读取二进制数据

```c
int data[5];
fread(data, sizeof(int), 5, fp);
```

## 四、文件定位

使用`fseek()`函数可以移动文件内部的位置指针。函数原型为：

```c
int fseek(FILE *fp, long offset, int origin);
```

- `offset`：相对于`origin`的偏移量，以字节为单位。
- `origin`：起始位置，可以是：
  - `SEEK_SET`：文件开头。
  - `SEEK_CUR`：当前位置。
  - `SEEK_END`：文件末尾。

示例：移动文件指针到文件开头

```c
fseek(fp, 0, SEEK_SET);
```

使用`ftell()`函数可以获取文件内部的位置指针的当前位置。函数原型为：

```c
long ftell(FILE *fp);
```

示例：获取文件指针当前位置

```c
long pos = ftell(fp);
```

## 五、错误处理

在文件操作过程中，可能会出现错误，如文件打开失败、读写错误等。可以使用`ferror()`函数检查文件操作是否发生错误。函数原型为：

```c
int ferror(FILE *fp);
```

示例：检查文件操作错误

```c
if (ferror(fp)) {
    perror("File operation error");
    clearerr(fp); // 清除错误标志
}
```

## 六、案例：文件复制

下面是一个完整的案例，演示如何使用C语言的文件操作函数复制一个文本文件。

```c
#include <stdio.h>

int main() {
    FILE *source, *target;
    char filename[100], buffer[1024];
    int count;

    printf("Enter source file name: ");
    scanf("%s", filename);

    // 打开源文件
    source = fopen(filename, "r");
    if (source == NULL) {
        perror("Cannot open source file");
        return 1;
    }

    printf("Enter target file name: ");
    scanf("%s", filename);

    // 打开目标文件
    target = fopen(filename, "w");
    if (target == NULL) {
        perror("Cannot open target file");
        fclose(source);
        return 1;
    }

    // 复制文件内容
    while ((count = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        if (fwrite(buffer, 1, count, target) != count) {
            perror("Write error");
            break;
        }
    }

    // 关闭文件
    fclose(source);
    fclose(target);

    printf("File copied successfully.\n");
    return 0;
}
```

## 七、案例：学生信息管理

下面是一个案例，演示如何使用C语言的文件操作管理学生信息。

```c
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float score;
} Student;

void addStudent(FILE *fp, Student s) {
    fwrite(&s, sizeof(Student), 1, fp);
}

Student readStudent(FILE *fp) {
    Student s;
    fread(&s, sizeof(Student), 1, fp);
    return s;
}

void displayStudent(Student s) {
    printf("ID: %d, Name: %s, Score: %.2f\n", s.id, s.name, s.score);
}

int main() {
    FILE *fp;
    Student students[MAX_STUDENTS];
    int n, i;

    // 打开文件
    fp = fopen("students.dat", "wb+");
    if (fp == NULL) {
        perror("Cannot open file");
        return 1;
    }

    // 添加学生信息
    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        students[i].id = i + 1;
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter score for student %d: ", i + 1);
        scanf("%f", &students[i].score);
        addStudent(fp, students[i]);
    }

    // 移动文件指针到开头
    fseek(fp, 0, SEEK_SET);

    // 读取并显示学生信息
    printf("\nStudent Information:\n");
    for (i = 0; i < n; i++) {
        students[i] = readStudent(fp);
        displayStudent(students[i]);
    }

    // 关闭文件
    fclose(fp);

    return 0;
}
```

## 八、总结

通过以上讲解和案例，我们学习了C语言文件操作的基本方法，包括文件的打开、关闭、读写、定位和错误处理。文件操作在C语言程序设计中应用广泛，掌握这些知识可以更好地进行数据处理和程序开发。