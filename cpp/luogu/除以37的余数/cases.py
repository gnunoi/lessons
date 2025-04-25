import os
import random
import zipfile
import yaml


def create_data_directory():
    """创建data目录"""
    if not os.path.exists('data'):
        os.makedirs('data')
        print("data目录已创建")
    else:
        print("data目录已存在")


def mod(a, b):
    # 如果a是字符串形式的大数，逐位计算余数
    if isinstance(a, str):
        remainder = 0
        for digit in a:
            remainder = (remainder * 10 + int(digit)) % b
        return remainder
    else:
        return a % b


def generate_test_cases():
    """生成测试点信息文件"""
    b = 37
    create_data_directory()  # 确保data目录存在

    for i in range(1, 11):
        # 生成输入文件
        input_filename = f"data/{i:02d}.in"
        output_filename = f"data/{i:02d}.out"

        # 随机生成a和b
        # a是一个小于10000位的正整数，这里生成1-50位的随机数
        a_length = random.randint(1, 50)
        a = ''.join([str(random.randint(0, 9)) for _ in range(a_length)])
        # 确保a的第一个字符不是0
        if a[0] == '0' and len(a) > 1:
            a = '1' + a[1:]

        # 计算余数
        remainder = mod(a, b)

        # 写入输入文件
        with open(input_filename, 'w') as f:
            f.write(f"{a}\n{b}")

        # 写入输出文件
        with open(output_filename, 'w') as f:
            f.write(f"{remainder}\n")

        print(f"已生成测试点{i}: {input_filename} 和 {output_filename}")


def generate_config_file():
    """生成config.yml文件"""
    config_data = {
        'test_cases': []
    }

    for i in range(1, 11):
        config_data['test_cases'].append({
            'input': f"{i:02d}.in",
            'output': f"{i:02d}.out",
            'score': 10,
            'is_sample': True
        })

    with open('data/config.yml', 'w') as f:
        yaml.dump(config_data, f, default_flow_style=False)

    print("已生成config.yml文件")


def zip_data_directory():
    """将data目录下的所有文件压缩到data.zip文件"""
    with zipfile.ZipFile('data.zip', 'w') as zipf:
        for root, dirs, files in os.walk('data'):
            for file in files:
                file_path = os.path.join(root, file)
                # 压缩时不包含data目录名
                arcname = os.path.relpath(file_path, 'data')
                zipf.write(file_path, arcname)

    print("已将data目录压缩到data.zip")


if __name__ == "__main__":
    # 生成测试点
    generate_test_cases()

    # 生成配置文件
    generate_config_file()

    # 压缩data目录
    zip_data_directory()