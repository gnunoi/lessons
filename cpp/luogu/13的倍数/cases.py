import os
import random
import yaml
import zipfile

def create_data_directory():
    """创建data目录"""
    if not os.path.exists('data'):
        os.makedirs('data')
    print("data目录已创建")

def is_divisible(str, divisor):
    remainder = 0
    for c in str:
        remainder = (remainder * 10 + int(c)) % divisor
    return remainder == 0

def generate_test_data(divisor, case_number, divisible_case_number):
    # 确保输出目录存在
    output_dir = "data"
    # 生成7个能被7整除的数和13个不能被7整除的数
    divisible = []
    indivisible = []
    number_of_digits = 1000
    indivisible_case_number = case_number - divisible_case_number
    test_info = []

    while len(divisible) < divisible_case_number:
        length = random.randint(1, number_of_digits)
        num_str = ''.join(random.choices('0123456789', k=length))
        # 确保生成的数不以0开头
        if num_str[0] == '0':
            num_str = '1' + num_str[1:]
        if is_divisible(str = num_str, divisor = divisor)  and not num_str in indivisible:
            divisible.append(num_str)

    while len(indivisible) < indivisible_case_number:
        length = random.randint(1, number_of_digits)
        num_str = ''.join(random.choices('0123456789', k=length))
        # 确保生成的数不以0开头
        if num_str[0] == '0':
            num_str = '1' + num_str[1:]
        if not is_divisible(str = num_str, divisor = divisor) and not num_str in indivisible:
            indivisible.append(num_str)
    
    # 合并并打乱顺序
    test_data = divisible + indivisible
    random.shuffle(test_data)
    
    # 写入文件
    for i in range(20):
        input_filename = f"{output_dir}/{i:02d}.in"
        output_filename = f"{output_dir}/{i:02d}.out"
        with open(input_filename, 'w') as f_in, open(output_filename, 'w') as f_out:
            f_in.write(test_data[i] + '\n')
            result = 1 if is_divisible(str = test_data[i], divisor = 13) else 0
            f_out.write(f'{result}\n')

        # 添加到测试信息
        test_info.append({
            "input": f"{i:02d}.in",
            "output": f"{i:02d}.out",
            "score": 5,
            "is_sample": i <= 2  # 前两个测试点设为样例
        })

    # 生成config.yaml
    config = {
        "test_cases": test_info
    }

    with open(f"{output_dir}/config.yml", 'w') as f:
        yaml.dump(config, f, default_flow_style=False)


def create_zip_file():
    with zipfile.ZipFile('data.zip', 'w') as zipf:
        for root, dirs, files in os.walk('data'):
            for file in files:
                file_path = os.path.join(root, file)
                # 只保留文件名，不包含data目录
                arcname = os.path.basename(file_path)
                zipf.write(file_path, arcname)

    print("data目录已压缩到data.zip")

if __name__ == "__main__":
    create_data_directory()
    divisor = 13
    case_number = 20
    divisible_case_number = 7
    generate_test_data(divisor = divisor,
                       case_number = case_number,
                       divisible_case_number = divisible_case_number)
    create_zip_file()