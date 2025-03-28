import random

def is_divisible_by_7(num_str):
    """
    判断一个字符串表示的正整数是否能被7整除
    """
    remainder = 0
    for c in num_str:
        remainder = (remainder * 10 + int(c)) % 7
    return remainder == 0

def generate_test_data():
    """
    生成测试数据并写入文件
    """
    # 生成7个能被7整除的数和13个不能被7整除的数
    divisible = []
    not_divisible = []
    
    # 生成能被7整除的数
    while len(divisible) < 7:
        length = random.randint(1, 100)
        num_str = ''.join(random.choices('0123456789', k=length))
        # 确保生成的数不以0开头
        if num_str[0] == '0':
            num_str = '1' + num_str[1:]
        if is_divisible_by_7(num_str):
            divisible.append(num_str)
    
    # 生成不能被7整除的数
    while len(not_divisible) < 13:
        length = random.randint(1, 100)
        num_str = ''.join(random.choices('0123456789', k=length))
        # 确保生成的数不以0开头
        if num_str[0] == '0':
            num_str = '1' + num_str[1:]
        if not is_divisible_by_7(num_str):
            not_divisible.append(num_str)
    
    # 合并并打乱顺序
    test_data = divisible + not_divisible
    random.shuffle(test_data)
    
    # 写入文件
    for i in range(20):
        input_filename = f"{i+1:02d}.in"
        output_filename = f"{i+1:02d}.out"
        with open(input_filename, 'w') as f_in, open(output_filename, 'w') as f_out:
            f_in.write(test_data[i] + '\n')
            result = 1 if is_divisible_by_7(test_data[i]) else 0
            f_out.write(f'{result}\n')

if __name__ == "__main__":
    generate_test_data()
