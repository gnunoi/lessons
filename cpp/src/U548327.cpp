#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string num;
    cin >> num;
    int sum = 0;
    for (char c : num) {
        sum += c - '0';
    }
    if (sum % 9 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}