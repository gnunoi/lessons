#include <iostream>
#include <string>
using namespace std;
int mod(string num, int divisor){
    int remainder = 0;
    for (char c : num) {
        remainder = (remainder * 10 + (c - '0')) % divisor ;
    }
    return remainder;
}
int main(){
    string num;
    cin >> num;
    if (mod(num, 13) == 0) {
        cout << '1' << endl;
    }else{
        cout << '0' << endl;
    }
    return 0;
}