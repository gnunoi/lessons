#include <iostream>
#include <bitset>
#include <string>
using namespace std;

void displayBinary(int num) 
{
    // 使用bitset将整数转换为32位二进制
    bitset<32> binary(num);
    
    // 将bitset转换为字符串
    string binaryStr = binary.to_string();
    
    // 每4位插入一个空格
    string formattedStr;
    for (int i = 0; i < binaryStr.length(); i++) {
        formattedStr += binaryStr[i];
        if ((i + 1) % 4 == 0 && i != binaryStr.length() - 1) {
            formattedStr += " ";
        }
    }
    
    cout << formattedStr << endl;
}

int main() 
{
    int num;
    cout << "输入一个整数：" << endl;
    while(cin >> num){ // 检测EOF，UNIX：CTRL+D，Widnows：CTRL+Z
        displayBinary(num);
    }
    return 0;
}