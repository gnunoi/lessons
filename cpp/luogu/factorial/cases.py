import os
import yaml
import zipfile
from math import factorial as math_factorial

def create_data_directory():
    """创建data目录"""
    if not os.path.exists('data'):
        os.makedirs('data')
    print("data目录已创建")

def factorial(n):
    """计算正整数n的阶乘"""
    if n < 0:
        raise ValueError("n必须是非负整数")
    return math_factorial(n)

def generate_test_cases():
    """生成测试点信息文件"""
    create_data_directory()  # 确保data目录存在
    
    # 生成测试点
    for i in range(1, 21):
        input_filename = f"data/{i:02d}.in"
        output_filename = f"data/{i:02d}.out"
        
        # 写入输入文件
        with open(input_filename, 'w') as f:
            f.write(str(i))
        
        # 计算阶乘并写入输出文件
        result = factorial(i)
        with open(output_filename, 'w') as f:
            f.write(str(result))
    
    print("测试点文件已生成")

def generate_config_file():
    """生成config.yml文件"""
    create_data_directory()  # 确保data目录存在
    
    config_data = {
        "test_cases": []
    }
    
    # 计算每个测试点的分数
    total_test_cases = 20
    score_per_case = 100.0 / total_test_cases
    
    for i in range(1, 21):
        config_data["test_cases"].append({
            "input": f"{i:02d}.in",
            "output": f"{i:02d}.out",
            "score": score_per_case,
            "is_sample": True
        })
    
    # 写入config.yml文件
    with open('data/config.yml', 'w') as f:
        yaml.dump(config_data, f, default_flow_style=False)
    
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
    # 依次执行各个功能
    create_data_directory()
    generate_test_cases()
    generate_config_file()
    zip_data_directory()
