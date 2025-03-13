#include <iostream>
#include <bitset>

using namespace std;

string ToBinary(int num) 
{
    bitset<8> binary(num);
    return binary.to_string();
}

int main() 
{
    int num;
    cout << "输入一个整数：" << endl;
    while(cin >> num){ // 检测EOF，UNIX：CTRL+D，Widnows：CTRL+Z
        string str = ToBinary(num);
        cout << str.substr(0, 4) << " " << str.substr(4, 4) << endl;
    }
    return 0;
}