remainders = []
divisor = int(input("请输入一个整数: "))
for exponent in range(divisor):
  power_of_10 = 10 ** exponent
  remainder = power_of_10 % divisor
  if remainder > divisor / 2:
    coefficient = remainder - divisor
  else:
    coefficient = remainder
  remainders.append(f'{exponent+1}:{remainder}:{coefficient}')
print('\n'.join(map(str, remainders)))
