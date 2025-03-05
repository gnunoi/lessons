#include<iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;

    int a, sum1 = 0, sum5 = 0, sum10=0;
    
    for(int i = 0; i < k; i++){
        cin >> a;
        if(a == 1) sum1++;
        if(a == 5) sum5++;
        if(a == 10) sum10++;
    }
    cout << sum1 << endl;
    cout << sum5 << endl;
    cout << sum10 << endl;

    return 0;
}