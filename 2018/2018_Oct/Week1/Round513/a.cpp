#include<bits/stdc++.h>
using namespace std;
const int MAXN=107;
char s[MAXN];
int cnt[500];
int main(){
	int N;scanf("%d",&N);
	scanf("%s",s);
	for(int i=0;i<N;++i)
		cnt[s[i]]++;
	int num=N/11;
	printf("%d\n",min(num,cnt[(int)'8']));
	return 0;
}
