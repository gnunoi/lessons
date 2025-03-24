#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    // cout << s; // 调试期间，先检查是否获取到整行

    int num = 0;
    for(int i = 0; i < s.length(); i++){
        if (s[i] >= '0' && s[i] <= '9') num++; 
    }
    cout << num << endl;
    return 0;
}