import os
import zipfile
import yaml

def create_data_directory():
    """创建data目录"""
    if not os.path.exists('data'):
        os.makedirs('data')
    print("data目录已创建")

def fibonacci(n):
    """计算斐波那契数列的第n项"""
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        a, b = 0, 1
        for _ in range(2, n+1):
            c = a + b
            a = b
            b = c
        return b

def generate_test_files():
    """生成测试点信息文件"""
    create_data_directory()  # 确保data目录存在
    
    test_cases = []
    total_cases = 50
    
    for i in range(total_cases):
        input_filename = f"data/{i+1:02d}.in"
        output_filename = f"data/{i+1:02d}.out"
        
        # 生成输入文件
        with open(input_filename, 'w') as f:
            f.write(str(i))
        
        # 生成输出文件
        fib_value = fibonacci(i)
        with open(output_filename, 'w') as f:
            f.write(str(fib_value))
        
        # 添加到测试点信息
        test_cases.append({
            'input': f"{i+1:02d}.in",
            'output': f"{i+1:02d}.out",
            'score': 100 / total_cases,
            'is_sample': True
        })
    
    # 生成config.yml文件
    config = {
        'test_cases': test_cases
    }
    
    with open('data/config.yml', 'w') as f:
        yaml.dump(config, f, default_flow_style=False)
    
    print("测试文件和配置文件已生成")

def create_zip_file():
    """将data目录下的所有文件压缩到data.zip"""
    create_data_directory()  # 确保data目录存在
    
    with zipfile.ZipFile('data.zip', 'w') as zipf:
        for root, dirs, files in os.walk('data'):
            for file in files:
                file_path = os.path.join(root, file)
                # 只保留文件名，不包含data目录
                arcname = os.path.basename(file_path)
                zipf.write(file_path, arcname)
    
    print("data目录已压缩到data.zip")

if __name__ == "__main__":
    # 执行所有功能
    create_data_directory()
    generate_test_files()
    create_zip_file()
