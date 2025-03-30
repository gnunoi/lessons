#include <iostream>

using namespace std;

int print(const string &s)
{
	for(char c : s){
		cout << c << endl;
	}
	return 0;
}

int main()
{
	string s;

	cin >> s;
	print(s);

	return 0;
}
