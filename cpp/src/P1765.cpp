#include <iostream>
#include <string>

using namespace std;

int main()
{
    int alpha[26] = {
        1,2,3,   // 2: abc
        1,2,3,   // 3: def
        1,2,3,   // 4: ghi
        1,2,3,   // 5: jkl
        1,2,3,   // 6: mno
        1,2,3,4, // 7: pqrs
        1,2,3,   // 8: tuv
        1,2,3,4  // 9: wxyz
    };
    string s;
    getline(cin, s);
    // cout << s << endl;
    int times = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            times += 1;
        }
        if(s[i] >= 'a' && s[i] <= 'z'){ // 保护数组下标不越界
            times += alpha[s[i] - 'a'];
        }
    }
    cout << times << endl;
    return 0;
}