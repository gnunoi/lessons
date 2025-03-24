#include <iostream>

using namespace std;

int main(){
	string s;//定义字符串。
	while(cin>>s){//输入字符串。
		for(int i=s.size()-1;i>=0;i--){//循环输出。
			cout<<s[i];
		}
		cout<<endl;//换行。
	}
	return 0;
}