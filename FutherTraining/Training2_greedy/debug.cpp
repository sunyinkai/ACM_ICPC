#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int>st;
	for(int i=0;i<10;++i)st.insert(i);
	for(auto it=st.begin();it!=st.end();++it){
		printf("%d ",*it);
	}
	printf("\n");
	auto it=st.end();it--;
	for(;it!=st.begin();--it){
		printf("%d ",*it);
	}
	printf("\n");
	return 0;
}
