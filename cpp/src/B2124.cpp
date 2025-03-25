#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s2;
    s1 = s2;
    reverse(s2.begin(), s2.end());
    if(s1 == s2) cout << "yes" << endl;
    else cout << "no" << endl;
    
    return 0;
}