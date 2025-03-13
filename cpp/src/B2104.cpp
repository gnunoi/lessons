#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int A[n][m];
    int B[n][m];

    int i,j;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> A[i][j];
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> B[i][j];
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++)
            cout << A[i][j] + B[i][j] << " ";
        cout << endl;
    }
}