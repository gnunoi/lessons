import os
import random
import math
import yaml
import zipfile

def create_data_directory():
    """创建data目录"""
    try:
        os.makedirs("data", exist_ok=True)
        print("data目录已创建")
    except Exception as e:
        print(f"创建data目录时出错: {e}")

def lcm(a, b):
    """计算两个正整数的最小公倍数"""
    return a * b // math.gcd(a, b)

def generate_test_cases():
    """生成测试点信息文件"""
    create_data_directory()  # 确保data目录存在
    
    test_cases = []
    for i in range(1, 11):
        # 随机生成两个整数
        a = random.randint(1, 10**4 - 1)
        b = random.randint(1, 10**4 - 1)
        
        # 计算最小公倍数
        result = lcm(a, b)
        
        # 创建输入和输出文件
        input_filename = f"data/{i:02d}.in"
        output_filename = f"data/{i:02d}.out"
        
        with open(input_filename, 'w') as f_in:
            f_in.write(f"{a} {b}\n")
        
        with open(output_filename, 'w') as f_out:
            f_out.write(f"{result}\n")
        
        # 添加到测试点列表
        test_cases.append({
            "input": f"{i:02d}.in",
            "output": f"{i:02d}.out",
            "score": 10,
            "is_sample": True
        })
    
    return test_cases

def generate_config_file(test_cases):
    """生成config.yml文件"""
    config = {
        "test_cases": test_cases
    }
    
    with open("data/config.yml", 'w') as f:
        yaml.dump(config, f, default_flow_style=False)
    
    print("config.yml文件已生成")

def zip_data_directory():
    """将data目录下的所有文件压缩到data.zip"""
    with zipfile.ZipFile('data.zip', 'w') as zipf:
        for root, dirs, files in os.walk('data'):
            for file in files:
                file_path = os.path.join(root, file)
                arcname = os.path.relpath(file_path, 'data')
                zipf.write(file_path, arcname=arcname)
    
    print("data目录已压缩到data.zip")

if __name__ == "__main__":
    # 1. 创建data目录
    create_data_directory()
    
    # 2. 生成测试点文件
    test_cases = generate_test_cases()
    
    # 3. 生成config.yml文件
    generate_config_file(test_cases)
    
    # 4. 压缩data目录
    zip_data_directory()
