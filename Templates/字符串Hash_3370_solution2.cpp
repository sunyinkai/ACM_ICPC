#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
	int N;cin>>N;
	unordered_map<string,int>mp;
	while(N--){
		string s;cin>>s;
		mp[s]=1;
	}
	cout<<mp.size()<<endl;
	return 0;
}
