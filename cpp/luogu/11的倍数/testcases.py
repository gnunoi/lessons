import random

def is_divisible_by_11(num_str):
    """
    判断一个100位以内的正整数是否能被11整除
    :param num_str: 输入的数字字符串
    :return: 如果能被11整除返回True，否则返回False
    """
    if len(num_str) > 100 or not num_str.isdigit() or num_str[0] == '0':
        return False  # 非法输入：超过100位或非正整数
    
    # 计算奇数位和偶数位的差是否是11的倍数
    odd_sum = 0
    even_sum = 0
    for i in range(len(num_str)):
        digit = int(num_str[i])
        if (i + 1) % 2 == 1:  # 奇数位（从左到右，第一位是位置1）
            odd_sum += digit
        else:
            even_sum += digit
    return (odd_sum - even_sum) % 11 == 0

def generate_test_data():
    """
    生成测试数据，保证有3个能被11整除，7个不能
    """
    test_data = []
    
    # 生成3个能被11整除的数
    for _ in range(3):
        while True:
            # 随机生成一个1到100位的数字
            length = random.randint(1, 100)
            num = ''.join(random.choices('0123456789', k=length))
            # 确保第一位不是0
            if num[0] == '0':
                continue
            if is_divisible_by_11(num):
                test_data.append(num)
                break
    
    # 生成7个不能被11整除的数
    for _ in range(7):
        while True:
            # 随机生成一个1到100位的数字
            length = random.randint(1, 100)
            num = ''.join(random.choices('0123456789', k=length))
            # 确保第一位不是0
            if num[0] == '0':
                continue
            if not is_divisible_by_11(num):
                test_data.append(num)
                break
    
    return test_data

def write_test_files(test_data):
    """
    将测试数据写入文件
    """
    for i in range(10):
        num = test_data[i]
        # 写入输入文件
        with open(f"{i+1:02d}.in", 'w') as f:
            f.write(num)
        # 写入输出文件
        result = "Yes" if is_divisible_by_11(num) else "No"
        with open(f"{i+1:02d}.out", 'w') as f:
            f.write(result)

if __name__ == "__main__":
    # 生成测试数据
    test_data = generate_test_data()
    # 写入文件
    write_test_files(test_data)
    print("测试数据文件生成完成！")
