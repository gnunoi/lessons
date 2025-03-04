#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double xa, ya, xb, yb;
    cin >> xa >> ya;
    cin >> xb >> yb;

    cout << sqrt((xa - xb)*(xa - xb) + (ya - yb)*(ya - yb));
    return 0;
}
