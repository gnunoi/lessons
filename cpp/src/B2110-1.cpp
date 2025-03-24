#include <iostream>

using namespace std;

int count(string s, char c)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == c) count++;
    }
    // cout << c << " : " << s << " : " << count << endl; // 调试用，需要注释掉
    return count;
}


int main()
{
    string s;
    cin >> s;
    // cout << s << endl; // 调试用，需要注释掉

    int i = 0, len = s.length();
    for(i = 0; i < len; i++){
        if(count(s, s[i]) == 1){
            cout << s[i] << endl;
            break;
        }
    }
    if (i == len) cout << "no" << endl;
    return 0;
}