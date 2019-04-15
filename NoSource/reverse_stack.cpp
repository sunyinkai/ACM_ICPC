#include<stack>
#include<cstdio>
using namespace std;

void dfs(stack<int>& st){
	int a=st.pop();
	if(st.empty())return a;

}
int main(){
	stack<int>st;
	for(int i=0;i<10;++i)
		st.push(i);
	dfs(st);
	return 0;
}
