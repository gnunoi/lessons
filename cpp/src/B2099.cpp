#include <iostream>

using namespace std;

int main()
{
    int a[6][6];
    int i, j;
    for(i = 1; i <= 5; i++)
        for(j = 1; j <= 5; j++)
            cin >> a[i][j];
    int m, n;
    cin >> m >> n;
    for(i = 1; i <= 5; i++){
        for(j = 1; j <= 5; j++)
            if (i == m)
                cout << a[n][j] << " ";
            else if(i == n)
                cout << a[m][j] << " ";
            else
                cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}