# C++高级调试技巧

---

## **引言：调试的本质与价值**  
调试是程序员的核心能力，如同医生诊断病情。  
**高级调试 = 工具熟练度 + 方法论 + 经验沉淀**  
今天分享三个关键技巧：宏定义调试分级、二分法定位、断点高阶用法。

---

## **一、分级日志输出**

### **1.1 为何使用宏？**  
- **编译期控制**：通过`#ifdef`实现条件编译，发布版本自动剥离调试代码  
- **灵活性**：动态切换调试级别（ERROR/WARNING/INFO）  
- **性能零开销**：非调试模式下不生成冗余代码  

### **1.2 实现方案**

```cpp
// 定义调试级别（可在编译命令中使用 -D 指定）
#define DEBUG_LEVEL 3  // 0:关闭 1:ERROR 2:WARNING 3:INFO

// 调试输出宏
#if DEBUG_LEVEL >= 1
#define DEBUG_ERROR(fmt, ...) \
    printf("[ERROR] %s:%d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define DEBUG_ERROR(fmt, ...)
#endif

#if DEBUG_LEVEL >= 2
#define DEBUG_WARNING(...) \
	printf("[WARNING] %s:%d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define DEBUG_WARNING(fmt, ...)
#endif

#if DEBUG_LEVEL >= 3
#define DEBUG_INFO(...) \
	printf("[INFO] %s:%d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define DEBUG_INFO(fmt, ...)
#endif
```

### **1.3 进阶技巧**  
- **颜色标记**：在printf中使用`\033[31m`等ANSI颜色代码  
- **多输出目标**：重定向到文件（`fprintf(stderr, ...)`）  
- **性能统计**：通过宏包裹耗时计算代码  

---

## **二、二分法定位：科学缩小问题范围**  

**代码二分法**

**场景**：复杂逻辑中快速定位出错代码段  
**步骤**：  

1. 注释掉50%代码 → 测试问题是否复现  
2. 若问题消失 → 错误在被注释部分，否则在剩余部分  
3. 重复分割剩余可疑代码  

**示例**：  
```cpp
void complexFunction() {
    // 阶段A
    // 注释B段，测试A段是否正常
    // 阶段B
}
```

---

## **三、断点调试高阶技巧**  

### **3.1 条件断点（GDB示例）**  
```bash
b main.cpp:20 if i==100    # 循环中i=100时中断
watch *(int*)0x7fffffffdda4  # 监视内存变化
```

### **3.2 数据断点**  
- **监视变量修改**（VS：右键变量 → Breakpoint → Data Breakpoint）  
- **检测野指针访问**：在释放内存后设置数据断点  

### **3.3 调用栈分析**  
- **查看栈帧**：`bt`（GDB）/ Call Stack窗口（VS）  
- **跳转栈帧**：`frame n` 查看历史上下文  

### **3.4 多线程调试**  
- **冻结线程**：暂停非关键线程（VS：线程窗口右键）  
- **线程专属断点**：GDB使用`thread apply all break`  

### **3.5 反汇编调试**  
**场景**：排查编译器优化导致的异常  
```bash
disassemble /m          # 查看源码对应汇编
stepi / nexti           # 单步执行汇编指令
```

---

## **总结与答疑**  
- **调试心法**：假设 → 验证 → 缩小范围 → 复现  
- **工具组合拳**：日志分级 + 二分法 + 断点 = 高效调试  
- **终极建议**：编写可调试的代码（模块化、防御性编程）  

**Q&A环节**：实际开发中遇到的疑难杂症，现场诊断！

---

**注**：可根据听众熟悉程度，现场演示Visual Studio/GDB实操演示。