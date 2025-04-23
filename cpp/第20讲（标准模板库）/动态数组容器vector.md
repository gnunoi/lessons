# 动态数组容器vector

`std::vector` 是 C++ 标准模板库（STL）中的一个动态数组容器，它提供了类似数组的随机访问能力，同时能够动态调整大小。`vector` 是一种非常常用的容器，广泛应用于各种场景，比如存储一组元素、动态管理数据等。

### 1. **`vector` 的基本概念**

- **动态数组**：`vector` 是一个动态数组，可以在运行时动态调整大小，而不需要手动管理内存。
- **随机访问**：支持通过索引直接访问元素，时间复杂度为 O(1)。
- **内存连续性**：`vector` 内部存储的元素是连续的，这使得它在某些操作（如缓存友好性）上表现优异。
- **自动扩容**：当 `vector` 的容量不足时，它会自动分配更大的内存空间，并将原有数据复制到新位置。

### 2. **`vector` 的基本操作**
以下是 `vector` 的一些常用操作：

#### **声明和初始化**
```cpp
#include <vector>

std::vector<int> vec1;          // 空 vector
std::vector<int> vec2(5);       // 初始化为 5 个元素，值为 0
std::vector<int> vec3(5, 10);   // 初始化为 5 个元素，值为 10
std::vector<int> vec4 = {1, 2, 3}; // 使用初始化列表
std::vector<int> vec5(vec4);    // 复制构造
```

#### **添加元素**
- `push_back(value)`：在尾部添加一个元素。
- `emplace_back(args...)`：在尾部构造一个元素（效率更高）。
- `insert(position, value)`：在指定位置插入一个元素。
- `insert(position, count, value)`：在指定位置插入多个相同值的元素。

```cpp
vec1.push_back(1);  // 添加元素 1
vec1.emplace_back(2);  // 添加元素 2
vec1.insert(vec1.begin(), 0);  // 在开头插入 0
vec1.insert(vec1.end(), 3, 5);  // 在末尾插入 3 个 5
```

#### **删除元素**
- `pop_back()`：删除尾部元素。
- `erase(position)`：删除指定位置的元素。
- `erase(start, end)`：删除从 `start` 到 `end` 的元素。

```cpp
vec1.pop_back();  // 删除尾部元素
vec1.erase(vec1.begin());  // 删除第一个元素
vec1.erase(vec1.begin() + 1, vec1.end() - 1);  // 删除中间部分
```

#### **访问元素**
- `operator[]`：通过索引访问元素（不检查越界）。
- `at(index)`：通过索引访问元素（检查越界，越界会抛出异常）。
- `front()`：访问第一个元素。
- `back()`：访问最后一个元素。

```cpp
int first = vec1[0];  // 访问第一个元素
int last = vec1.back();  // 访问最后一个元素
int third = vec1.at(2);  // 安全访问第三个元素
```

#### **遍历**
- 使用范围 `for` 循环：
```cpp
for (int val : vec1) {
    std::cout << val << " ";
}
```

- 使用迭代器：
```cpp
for (auto it = vec1.begin(); it != vec1.end(); ++it) {
    std::cout << *it << " ";
}
```

#### **容量相关操作**
- `size()`：返回当前元素的数量。
- `capacity()`：返回当前分配的内存量（可能大于 `size()`）。
- `empty()`：判断是否为空。
- `resize(new_size)`：调整大小。
- `reserve(new_capacity)`：预留内存，避免频繁扩容。

```cpp
std::cout << "Size: " << vec1.size() << std::endl;
std::cout << "Capacity: " << vec1.capacity() << std::endl;
vec1.resize(10);  // 调整大小为 10，新元素默认为 0
vec1.reserve(20);  // 预留 20 个元素的空间
```

#### **清空**
- `clear()`：清空所有元素，但保留容量。
```cpp
vec1.clear();
```

### 3. **`vector` 的内存管理**
- **自动扩容机制**：当 `vector` 的容量不足时，它会分配一个更大的内存块（通常是当前容量的两倍），并将原有数据复制到新内存中。这种机制称为 **动态扩容**。
- **内存效率**：虽然 `vector` 的自动扩容机制很方便，但频繁的扩容和数据复制可能会影响性能。如果知道需要存储大量元素，可以预先使用 `reserve()` 预留足够的内存。

### 4. **`vector` 的性能特点**
- **尾部插入和删除**：O(1) 时间复杂度（摊还）。
- **中间插入和删除**：O(n) 时间复杂度，因为需要移动后面的元素。
- **随机访问**：O(1) 时间复杂度。

### 5. **适用场景**
- 当需要动态数组功能时。
- 当需要高效的随机访问时。
- 当需要在尾部频繁插入和删除时。

### 6. **注意事项**
- **迭代器失效**：当 `vector` 发生扩容或删除操作时，旧的迭代器可能失效，需要重新获取。
- **内存占用**：`vector` 会预留额外的内存以避免频繁扩容，这可能导致内存占用比实际需要的多。

### 示例代码
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 添加元素
    vec.push_back(6);
    vec.emplace_back(7);

    // 插入元素
    vec.insert(vec.begin() + 2, 10);

    // 删除元素
    vec.pop_back();
    vec.erase(vec.begin());

    // 遍历
    for (int val : vec) {
        std::cout << val << " ";
    }

    // 输出大小和容量
    std::cout << "\nSize: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    return 0;
}
```

### 总结
`std::vector` 是一个功能强大且灵活的容器，适合大多数需要动态数组的场景。理解它的内存管理机制和性能特点可以帮助我们更高效地使用它。