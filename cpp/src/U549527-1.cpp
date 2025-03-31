#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(vector<int> &num, int n) {
    int carry = 0;
    for (int i = 0; i < num.size(); i++) {
        int product = num[i] * n + carry;
        num[i] = product % 10;
        carry = product / 10;
    }
    while (carry > 0) {
        num.push_back(carry % 10);
        carry /= 10;
    }
    return num;
}

vector<int> factorial(int n) {
    vector<int> result;
    result.push_back(1); // 阶乘从1开始

    for (int i = 2; i <= n; i++) {
        result = multiply(result, i);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> result = factorial(n);

    // 从最高位到最低位输出
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}