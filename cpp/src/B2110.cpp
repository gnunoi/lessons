#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    // cout << s << endl; // 调试用，需要注释掉

    int i = 0, len = s.length();
    for(i = 0; i < len; i++){
        if (s.find(s[i]) == s.rfind(s[i])){
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}