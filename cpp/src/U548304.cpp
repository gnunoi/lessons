#include <iostream>
#include <string>
using namespace std;

bool isDivisibleBy11(const string& num) 
{
    int oddSum = 0, evenSum = 0;
    for (size_t i = 0; i < num.length(); ++i) {
        int digit = num[i] - '0';
        if (i % 2 == 0)  oddSum += digit;
        else evenSum += digit;
    }
    return (oddSum - evenSum) % 11 == 0;
}

int main() 
{
    string num;
    cin >> num;
    if (isDivisibleBy11(num)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}