import random

# 判断一个数是否能被9整除的函数
def is_divisible_by_9(num_str):
    # 计算各位数字之和
    digit_sum = sum(int(digit) for digit in num_str)
    # 如果各位数字之和能被9整除，则返回Yes，否则返回No
    return "Yes" if digit_sum % 9 == 0 else "No"

# 生成测试数据的函数
def generate_test_data():
    test_data = []
    # 生成3个能被9整除的数
    for _ in range(3):
        length = random.randint(1, 100)  # 随机生成1到100位的数
        num_str = ''.join(str(random.randint(0, 9)) for _ in range(length))
        # 调整各位数字之和使其能被9整除
        digit_sum = sum(int(digit) for digit in num_str)
        if digit_sum % 9 != 0:
            # 如果各位数字之和不能被9整除，则调整最后一位数字使其能被9整除
            num_str = num_str[:-1] + str((9 - (digit_sum % 9)) % 10)
        test_data.append(num_str)
    # 生成7个不能被9整除的数
    for _ in range(7):
        length = random.randint(1, 100)  # 随机生成1到100位的数
        num_str = ''.join(str(random.randint(0, 9)) for _ in range(length))
        # 调整各位数字之和使其不能被9整除
        digit_sum = sum(int(digit) for digit in num_str)
        if digit_sum % 9 == 0:
            # 如果各位数字之和能被9整除，则调整最后一位数字使其不能被9整除
            num_str = num_str[:-1] + str((digit_sum % 9 + 1) % 10)
        test_data.append(num_str)
    return test_data

# 将测试数据写入文件的函数
def write_test_files(test_data):
    for i in range(10):
        input_filename = f"{i+1:02d}.in"
        output_filename = f"{i+1:02d}.out"
        with open(input_filename, 'w') as input_file, open(output_filename, 'w') as output_file:
            input_file.write(test_data[i] + '\n')
            output_file.write(is_divisible_by_9(test_data[i]) + '\n')

# 主函数
def main():
    test_data = generate_test_data()
    write_test_files(test_data)

if __name__ == "__main__":
    main()
