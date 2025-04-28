#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n][m];

    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> a[i][j];
    for(j = 0; j < m; j++){
        for(i = 0; i < n; i++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}