# 定义判断函数
def is_alice_like(x):
    return x % 2 == 1 and x % 3 == 2

def is_bob_like(x):
    return x % 2 == 1 or x % 3 == 2

def is_cindy_like(x):
    return (x % 2 == 1 and x % 3 != 2) or (x % 2 != 1 and x % 3 == 2)

def is_david_like(x):
    return x % 2 != 1 and x % 3 != 2

# 生成测试用例的输入和输出文件
def generate_test_cases(nums):
    for i, x in enumerate(nums):
        # 生成输入文件
        input_filename = f"0{i+1}.in"
        with open(input_filename, 'w') as f:
            f.write(f"{x}\n")

        # 生成输出文件
        output_filename = f"0{i+1}.out"
        alice = int(is_alice_like(x))
        bob = int(is_bob_like(x))
        cindy = int(is_cindy_like(x))
        david = int(is_david_like(x))
        with open(output_filename, 'w') as f:
            f.write(f"{alice} {bob} {cindy} {david}\n")

if __name__ == "__main__":
    nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    generate_test_cases(nums)
