#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    double a, b;
    
    cin >> a >> b;
	cout << a - (int)(a / b) * b;

    return 0;
}
