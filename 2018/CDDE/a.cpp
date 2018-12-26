#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define ll long long
#define inf 100005
const ll INF=1e18+10;
char s[110];
int k[inf], n, m;
ll lenth[70], pre[70][110][30], num[70][30];
//pre[i][j][k]:翻转i次，长度为j的字符串中ch出现的次数
//k[i]:第i次翻转的个数

int find(int x, ll len)
{
	if(!x) return s[len]-'a';
	if(len <= lenth[x-1]) return find(x-1, len);
	len-=lenth[x-1];
	if(k[x] >= len) return find(x-1, lenth[x-1]-k[x]+len);
	return find(x-1, len-k[x]);
}

void init()
{
	lenth[0] = strlen(s+1);
	for(int i=1; i<=lenth[0]; i++)
	{//翻转次数
		for(int j=0; j<26; j++) pre[0][i][j] = pre[0][i-1][j];
		pre[0][i][s[i]-'a']++;
	} 
	for(int i=0; i<26; i++) num[0][i] = pre[0][lenth[0]][i];
	for(int i=1; i<=n; i++)
	{
		lenth[i] = lenth[i-1]*2;
		k[i]%=lenth[i-1];
		for(int j=0; j<26; j++) num[i][j] = num[i-1][j]*2;
		if(lenth[i] >= INF) 
		{
			n = i;
			break;
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=k[i]; j++)
		{
			for(int r=0; r<26; r++)
			{
				pre[i][j][r] = pre[i][j-1][r];
			}
			int c = find(i-1, lenth[i-1]-k[i]+j);
			pre[i][j][c]++;
		}
	}
} 

ll solve(int x, ll len, int c)
{
	if(!len) return 0;
	if(!x) return pre[0][len][c];
	if(len <= lenth[x-1]) return solve(x-1, len, c);
	len-=lenth[x-1];
	if(len <= k[x]) return num[x-1][c]+pre[x][len][c];
	return num[x-1][c]+pre[x][k[x]][c]+solve(x-1, len-k[x], c);
}

int main()
{
	scanf("%s", s+1);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &k[i]);
	}
	init();
	while(m--)
	{
		ll l, r;
		char c[10];
		scanf("%lld%lld%s", &l, &r, c);
		printf("%lld\n", solve(n,r,c[0]-'a') - solve(n,l-1,c[0]-'a'));
	}
	return 0;
}


