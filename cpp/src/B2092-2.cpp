#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    bool a[5001];
    for(int i = 1; i <= N; i++){
        a[i] = true; // 开灯状态
    }
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (j % i == 0) a[j] = !a[j]; // 相反操作
        }
    }
    for(int i = 1; i <= N; i++){
        if (!a[i]) cout << i << " ";
    }
    return 0;
}