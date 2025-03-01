#include <stdio.h>

int main()
{
  // long long：8字节长度 
	long long int a, b;

  // 输入两个整数到变量a与变量b
	scanf("%lld%lld", &a, &b);
  // 输出a+b的数值
	printf("%lld\n", a+b);
	
	return 0;
}