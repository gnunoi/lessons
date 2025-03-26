def int_to_binary(num):
    if num == 0:
        return "0"

    # 处理正数
    if num > 0:
        binary = bin(num)[2:]  # 转换为二进制并去掉'0b'前缀
        return binary
    # 处理负数
    else:
        # 负数的补码计算：将负数转换为对应的无符号整数，然后取二进制
        binary = bin(num & 0xFFFFFFFF)[2:]  # 0xFFFFFFFF是32位全1的掩码
        # 确保输出为32位，不足部分补0
        binary = binary.zfill(32)
        return binary


def generate_test_cases():
    # 定义测试数据数组，包含20个元素
    test_data = [
        0, 2 ** 8 - 1, 2 ** 8, 2 ** 16 - 1, 2 ** 16,
           2 ** 20, 2 ** 20 + 1, 2 ** 24 - 1, 2 ** 24, 2 ** 31 - 1,
        -1, -2 ** 8 + 1, -2 ** 8, -2 ** 16 + 1, -2 ** 16,
           -2 ** 24 + 1, -2 ** 24, -2 ** 24 - 1, -2 ** 31 + 1, -2 ** 31
    ]

    # 生成测试点信息文件
    for i in range(len(test_data)):
        # 输入文件名
        in_filename = f"{i + 1:02d}.in"
        # 输出文件名
        out_filename = f"{i + 1:02d}.out"

        # 写入输入文件
        with open(in_filename, 'w') as in_file:
            in_file.write(str(test_data[i]) + '\n')

        # 计算输出结果
        result = int_to_binary(test_data[i])

        # 写入输出文件
        with open(out_filename, 'w') as out_file:
            out_file.write(result + '\n')


# 调用函数生成测试点信息文件
generate_test_cases()