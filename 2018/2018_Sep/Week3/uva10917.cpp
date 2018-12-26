#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int MAXN=1007;
const int INF=1e9+7;

vector<P>G[MAXN];
int done[MAXN],d[MAXN];
int N,M;
void dijkstra(int s){
	for(int i=1;i<=N;++i)d[i]=INF;
	memset(done,0,sizeof(done));
	d[s]=0;

}
int main(){
	
	return 0;
}
