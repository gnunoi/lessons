#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s1[21], s2[21];
    cin >> s1 >> s2;
    if(strstr(s2, s1)){
        cout << s1 << " is substring of " << s2 << endl;
    }else if (strstr(s1, s2)){
        cout << s2 << " is substring of " << s1 << endl;        
    }else{
        cout << "No substring" << endl;
    }
    return 0;
}