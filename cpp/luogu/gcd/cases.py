import os
import random
import yaml
import zipfile
from pathlib import Path

def create_data_directory():
    """创建data目录"""
    data_dir = Path("data")
    data_dir.mkdir(exist_ok=True)
    return data_dir

def gcd(a, b):
    """计算两个正整数的最大公约数"""
    while b != 0:
        a, b = b, a % b
    return a

def generate_test_cases(data_dir):
    """生成测试点信息文件"""
    test_cases = []
    for i in range(1, 11):
        input_file = data_dir / f"{i:02d}.in"
        output_file = data_dir / f"{i:02d}.out"
        
        # 生成测试数据
        while True:
            a = random.randint(1, 10**6)
            b = random.randint(1, 10**6)
            
            # 确保至少有7组数据的gcd不为1
            if i <= 7 or random.random() < 0.5:
                # 生成不互质的数对
                common_divisor = random.randint(2, 100)
                a = a * common_divisor
                b = b * common_divisor
            
            # 计算gcd
            result = gcd(a, b)
            
            # 确保至少7组数据的gcd不为1
            if i <= 7 and result == 1:
                continue
            
            break
        
        # 写入输入文件
        with open(input_file, 'w') as f:
            f.write(f"{a} {b}\n")
        
        # 写入输出文件
        with open(output_file, 'w') as f:
            f.write(f"{result}\n")
        
        test_cases.append({
            'input': f"{i:02d}.in",
            'output': f"{i:02d}.out",
            'score': 10,
            'is_sample': i == 1  # 第一个测试点作为样例
        })
    
    return test_cases

def generate_config_file(data_dir, test_cases):
    """生成config.yml文件"""
    config_data = {
        'test_cases': test_cases
    }
    
    config_file = data_dir / "config.yml"
    with open(config_file, 'w') as f:
        yaml.dump(config_data, f, default_flow_style=False)

def create_zip_file(data_dir):
    """创建zip文件"""
    zip_filename = Path("../data.zip")
    with zipfile.ZipFile(zip_filename, 'w') as zipf:
        for file in data_dir.iterdir():
            zipf.write(file, arcname=file.name)
    
    print(f"压缩文件已创建: {zip_filename}")

def main():
    # 创建data目录
    data_dir = create_data_directory()
    
    # 生成测试点
    test_cases = generate_test_cases(data_dir)
    
    # 生成config.yml
    generate_config_file(data_dir, test_cases)
    
    # 创建zip文件
    create_zip_file(data_dir)
    
    print("数据生成完成！")

if __name__ == "__main__":
    main()
