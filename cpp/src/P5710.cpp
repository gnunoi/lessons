#include <iostream>

using namespace std;

int main()
{
    unsigned x;
    cin >> x;
    bool b1, b2;
    b1 = x % 2 == 0;
    b2 = x >= 4 && x <= 12;
    if(b1 && b2){
        cout << "1 ";
    }else{
        cout << "0 ";
    }
    if(b1 || b2){
        cout << "1 ";
    }else{
        cout << "0 ";
    }
    if(b1 && !b2 || !b1 && b2){
        cout << "1 ";
    }else{
        cout << "0 ";
    }
    if(!b1 && !b2){
        cout << '1';
    }else{
        cout << '0';
    }
    return 0;
}