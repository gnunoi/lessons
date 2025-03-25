#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, shortest, longest;
    bool first = true;
    getline(cin, s);
    // cout << s; // 注释掉
 
    unsigned long start = 0, end = 0;
    for(end = 0; end < s.size(); end++){
        if(s[end] == ' ' || s[end] == ',' || s[end] == '.'){
            if(first){
                shortest = s.substr(start, end - start); // substr(pos, count)
                longest = shortest;
                // cout << shortest << endl; // 注释掉
                // cout << longest << endl; // 注释掉
                first = false;
                start = end+1;
            }else{
                if(end - start < shortest.size()) shortest = s.substr(start, end - start);
                if(end - start > longest.size()) longest = s.substr(start, end - start);
                start = end+1;
            }
        }
    }
    cout << longest << endl;
    cout << shortest << endl;
    return 0;
}