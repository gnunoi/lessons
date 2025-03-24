#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, shortest, longest;
    bool first = true;
    while(cin >> s){
        int pos1 = s.find(',');
        int pos2 = s.find('.');
        if(pos1 != string::npos) {
            s = s.erase(pos1, pos1);
            cout << s << endl;
        }
        if(pos2 != string::npos) {
            s = s.erase(pos2); 
            cout << s << endl;
        }
        if(first){
            first = false;
            shortest = s;
            longest = s;
        }else{
            if(s.size() < shortest.size()) shortest = s;
            if(s.size() > longest.size()) longest = s;
        }
    }
    cout << longest << endl;
    cout << shortest << endl;
    return 0;
}