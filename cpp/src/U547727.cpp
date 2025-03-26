#include <iostream>
using namespace std;

int main() 
{
    int x;
    cin >> x;
    
    bool alice = false, bob = false, cindy = false, david = false;
    
    // 判断是否满足性质1（奇数）
    bool prop1 = (x % 2 == 1);
    
    // 判断是否满足性质2（除以3余2）
    bool prop2 = (x % 3 == 2);
    
    // Alice喜欢同时满足两个性质的数
    alice = prop1 && prop2;
    
    // Bob喜欢至少满足一个性质的数
    bob = prop1 || prop2;
    
    // Cindy喜欢恰好满足一个性质的数
    cindy = (prop1 != prop2);
    
    // David喜欢不满足任何一个性质的数
    david = !prop1 && !prop2;
    
    cout << alice << " " << bob << " " << cindy << " " << david << endl;
    
    return 0;
}