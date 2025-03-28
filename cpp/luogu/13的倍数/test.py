# 初始化一个空列表，用于存储余数
remainders = []

for exponent in range(101):
    # 计算10的幂次方
    power_of_10 = 10 ** exponent
    # 计算余数
    remainder = power_of_10 % 31
    # 将余数添加到列表中
    remainders.append(f'{exponent}:{remainder}')

# 输出所有余数，每个余数占一行
print('\n'.join(map(str, remainders)))
