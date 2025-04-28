# 创建列表
numbers = [1, 2, 3, 4, 5]
mixed_list = [1, "hello", 3.14, True]

# 访问列表元素
print(numbers[0])   # 1
print(mixed_list[2]) # 3.14

# 列表操作
numbers.append(6)   # 添加元素
print(numbers)      # [1, 2, 3, 4, 5, 6]

numbers.remove(3)   # 删除元素
print(numbers)      # [1, 2, 4, 5, 6]
