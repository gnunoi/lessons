#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count[101] = {0,};
    int temp;
    
    for (int i = 0; i < n; i++){
        cin >> temp;
        count[temp] += 1;
        if(count[temp] == 1) cout << temp << " ";
    }

    return 0;
}