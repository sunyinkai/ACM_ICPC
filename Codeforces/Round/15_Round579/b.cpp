#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=500+7;
int a[MAXN*2];
map<int,int>mp;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int N;scanf("%d",&N);
        mp.clear();
        for(int i=0;i<4*N;++i){
            int x;scanf("%d",&x);
            mp[x]++;
        }
        bool hasAns=true;
        int id=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            int val=it->first,cnt=it->second;
            if(cnt%2!=0)hasAns=false;
            for(int i=0;i<cnt/2;++i)a[id++]=val;
        }
        int val=a[0]*a[id-1];
        for(int i=0;i<id;++i){
            if(a[i]*a[id-1-i]!=val)hasAns=false;
        }
        printf(hasAns?"YES\n":"NO\n");
    }
    return 0;
}
