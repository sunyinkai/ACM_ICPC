#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
map<string,int>origin;
int main(){
	int N;cin>>N;
	while(N--){
		string t;cin>>t;
		origin[t]++;
		sort(t.begin(),t.end());
		mp[t]++;
	}
	int M;cin>>M;
	while(M--){
		string t;cin>>t;
		int x=origin[t];
		sort(t.begin(),t.end());
		int y=mp[t];
		cout<<y-x<<endl;
	}
	return 0;
}

