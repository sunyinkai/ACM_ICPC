
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
 
using namespace std;
const int maxn = 1005;
const int INF = 1e8;
 
char from[maxn], to[maxn];
int d[maxn][15][15][15];
bool vis[maxn][15][15][15];
string s1, s2;
 
int dp(int pos, int a, int b, int c)	//pos是当前的位置，a,b,c分别是pos,pos+1,pos+2上的数字
{
	int& t = d[pos][a][b][c];
	if(vis[pos][a][b][c])	return t;
	if(pos >= s1.length())	return 0;
 
	int target = s2[pos] - '0', d;
	if(a < target){
		d = target - a;	//向上旋转
		for(int i = 0; i <= d; i++){	//枚举pos+1位置上旋转的距离
			for(int j = 0; j <= i; j++){
				t = min(t, dp(pos+1, (b+i)%10, (c+j)%10, s1[pos+3]-'0') + d);
			}
		}
 
		d = 10 - d;	//向下旋转
		for(int i = 0; i <= d; i++){
			for(int j = 0; j <= i; j++){
				t = min(t, dp(pos+1, (b-i+10)%10, (c-j+10)%10, s1[pos+3]-'0') + d);
			}
		}
	}else{
		d = a - target;	//向下旋转
		for(int i = 0; i <= d; i++){
			for(int j = 0; j <= i; j++){
				t = min(t, dp(pos+1, (b-i+10)%10, (c-j+10)%10, s1[pos+3]-'0') + d);
			}
		}
 
		d = 10 - d;	//向上旋转
		for(int i = 0; i <= d; i++){	//枚举pos+1位置上旋转的距离
			for(int j = 0; j <= i; j++){
				t = min(t, dp(pos+1, (b+i)%10, (c+j)%10, s1[pos+3]-'0') + d);
			}
		}
	}
 
	vis[pos][a][b][c] = true;
	return t;
}
 
int main()
{
	//freopen("in.txt", "r", stdin);
    while(~scanf("%s%s", from, to)){
		s1 = string(from);	s2 = string(to);
		int a = s1[0] - '0', b = s1[1] - '0', c = s1[2] - '0';
		memset(d, 0x3f, sizeof(d));
		memset(vis, 0, sizeof(vis));
		printf("%d\n", dp(0, a, b, c));
    }
    return 0;
}

