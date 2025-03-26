#include <iostream>
#include <string>
using namespace std;

string decimalToBinary(int n) {
    string binary = "";
    if (n == 0) {
        return "0";
    }
    bool isNegative = n < 0;
    unsigned int num = isNegative ? (unsigned int)n : n;

    for (int i = 31; i >= 0; --i) {
        binary += ((num >> i) & 1) ? '1' : '0';
    }

    if (isNegative) {
        return binary;
    } else {
        size_t firstOne = binary.find('1');
        return binary.substr(firstOne);
    }
}

int main() {
    int num;

    cin >> num;
    cout << decimalToBinary(num) << endl;

    return 0;
}