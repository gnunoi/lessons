#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    int co[] = {1, 3, 2, -1, -3, -2};
    string num;
    cin >> num;
    int sum = 0;
    reverse(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++) {
        sum += (num[i] - '0') * co[i % 6];
    }
    if (sum % 7 == 0) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}