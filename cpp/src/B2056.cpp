#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n, a[10000];
    int sum = 0;
  	double average;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    average  = (double)sum / n;
    cout << sum << " " << fixed << setprecision(5) << average;

    return 0;
}