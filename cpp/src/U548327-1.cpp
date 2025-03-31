#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string num;
    cin >> num;
    int remainder = 0;
    for (char c : num) {
        remainder = (remainder * 10 + (c - '0')) % 9 ;
    }
    if (remainder == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}