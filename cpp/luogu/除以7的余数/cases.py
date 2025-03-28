import os
import random
import yaml

def remainder_10_power_n(n):
    """
    计算10^n除以7的余数
    """
    if n < 0:
        raise ValueError("输入必须是正整数")
    return pow(10, n, 7)

def generate_test_cases(output_dir="data"):
    """
    生成测试点文件
    """
    # 确保输出目录存在
    os.makedirs(output_dir, exist_ok=True)
    
    # 生成20个随机数，范围1-1000
    test_numbers = [random.randint(1, 1000) for _ in range(20)]
    
    # 生成输入和输出文件
    test_info = []
    for i, num in enumerate(test_numbers, 1):
        input_filename = f"{output_dir}/{i:02d}.in"
        output_filename = f"{output_dir}/{i:02d}.out"
        
        # 写入输入文件
        with open(input_filename, 'w') as f:
            f.write(f"{num}\n")
        
        # 写入输出文件
        result = remainder_10_power_n(num)
        with open(output_filename, 'w') as f:
            f.write(f"{result}\n")
        
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

if __name__ == "__main__":
    generate_test_cases()
    print("测试点文件和config.yml已生成")
