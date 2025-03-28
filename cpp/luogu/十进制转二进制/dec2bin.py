def int_to_binary():
    num = int(input("请输入一个32位整型数："))
    
    # 检查输入是否为32位整型数
    if num < -2**31 or num > 2**31 - 1:
        print("输入的数超出32位整型范围！")
        return
    
    if num == 0:
        print("0")
        return
    
    # 处理正数
    if num > 0:
        binary = bin(num)[2:]  # 转换为二进制并去掉'0b'前缀
        print(binary)
    # 处理负数
    else:
        # 负数的补码计算：将负数转换为对应的无符号整数，然后取二进制
        binary = bin(num & 0xFFFFFFFF)[2:]  # 0xFFFFFFFF是32位全1的掩码
        # 确保输出为32位，不足部分补0
        binary = binary.zfill(32)
        print(binary)

# 调用函数
int_to_binary()
