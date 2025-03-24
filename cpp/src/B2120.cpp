#include <iostream>

using namespace std;

int main()
{
    string s;
    bool first = true;
    while(cin >> s){
        if (first) {
            first = !first;
            cout << s.size();
        } else {
            cout << ',' << s.size();
        }
    }
    
    return 0;
}