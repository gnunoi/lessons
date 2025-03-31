#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BigInt {
private:
    vector<int> digits; // 从最低位到最高位存储数字

public:
    BigInt() {
        digits.clear(); // 默认构造函数，初始化为空
    }

    BigInt(int num) {
        if (num == 0) {
            digits.push_back(0);
            return;
        }
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    // 重载乘法运算符
    BigInt operator*(int multiplier) const {
        BigInt result;
        int carry = 0;
        for (size_t i = 0; i < digits.size(); i++) {
            int product = digits[i] * multiplier + carry;
            result.digits.push_back(product % 10);
            carry = product / 10;
        }
        while (carry > 0) {
            result.digits.push_back(carry % 10);
            carry /= 10;
        }
        return result;
    }

    // 重载乘法赋值运算符
    BigInt& operator*=(int multiplier) {
        *this = *this * multiplier;
        return *this;
    }

    // 转换为字符串以便输出
    string toString() const {
        if (digits.empty()) return "0";
        string result;
        for (auto it = digits.rbegin(); it != digits.rend(); it++) {
            result += to_string(*it);
        }
        return result.empty() ? "0" : result;
    }
};

BigInt factorial(int n) {
    BigInt result(1); // 阶乘从1开始

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    BigInt result = factorial(n);
    cout << result.toString() << endl;

    return 0;
}