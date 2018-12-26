#include<cstdio>
typedef long long ll;
int a[MAXN];
ll dp[20][state];//当前在第pos位,状态,有无前导0,有无限制
ll dfs(int pos,int state,bool lead,bool limit){
	if(pos==-1)return 1;
	if(!limit&&!lead&&dp[pos][state]!=-1)return dp[pos][state];
	int up=limit?a[pos]:9;
	ll ans=0;
	for(int i=0;i<=up;++i){
		if()//
		else if(){
			ans+=dfs(pos-1,state2,lead&&i==0,limit&&i==pos);
		}
	}
	if(!limit&&!lead)dp[pos][state]=ans;
	return ans;
}

ll solve(ll x){
	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,state,true,true);
}

int main(){
	ll l,r;
	while(~scanf("%lld%lld",&l,&r)){
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}

