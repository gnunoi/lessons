#include <iostream>
using namespace std;
int main(){
    cout << "请输入2个整数（第2个不可以是0)：" << endl;
    int a, b;
    cin >> a >> b;
    if(b == 0){
        cout << "除数不能为0." << endl;
        return 1;
    }
    cout << a << " / " << b << " = " << a / b << endl;
    cout << a << " % " << b << " = " << a % b << endl;
    return 0;
}