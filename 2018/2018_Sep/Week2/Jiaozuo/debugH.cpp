#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+9;
char s[MAXN];
struct SAM{
    int p,q,np,nq,cnt,lst,a[MAXN][26],l[MAXN],f[MAXN],tot;
    int Tr(char c){return c-'A';}
    int val(int c){return l[c]-l[f[c]];}
    SAM(){cnt=0;lst=++cnt;}
    void Initialize(){
        memset(l,0,sizeof(int)*(cnt+1));
        memset(f,0,sizeof(int)*(cnt+1));
        for(int i=0;i<=cnt;i++)for(int j=0;j<26;j++)a[i][j]=0;
        cnt=0;lst=++cnt;
    }
    void extend(int c){
        p=lst;np=lst=++cnt;l[np]=l[p]+1;
        while(!a[p][c]&&p)a[p][c]=np,p=f[p];
        if(!p){f[np]=1;}
        else{
            q=a[p][c];
            if(l[p]+1==l[q])f[np]=q;
            else{
                nq=++cnt;l[nq]=l[p]+1;
                memcpy(a[nq],a[q],sizeof(a[q]));
                f[nq]=f[q]; f[np]=f[q]=nq;
                while(a[p][c]==q)a[p][c]=nq,p=f[p];
            }
        }
    }
    int b[MAXN],x[MAXN],r[MAXN];
    bool build(){
        if(scanf("%s",s+1)==-1)return false;
        int len=strlen(s+1);
        for(int i=1;i<=len;i++)extend(Tr(s[i]));
        memset(r,0,sizeof(int)*(cnt+1));
        memset(b,0,sizeof(int)*(cnt+1));
        for(int i=1;i<=cnt;i++)b[l[i]]++;
        for(int i=1;i<=len;i++)b[i]+=b[i-1];
        for(int i=1;i<=cnt;i++)x[b[l[i]]--]=i;
        for(int i=p=1;i<=len;i++){p=a[p][Tr(s[i])];r[p]++;}
        for(int i=cnt;i;i--)r[f[x[i]]]+=r[x[i]];
        return true;
    }
    bool solve(){
        long long ans=0,A,B;
        if(!build())return false;
        scanf("%lld%lld",&A,&B);
        for(int i=1;i<=cnt;i++)if(r[x[i]]>=A&&r[x[i]]<=B)ans+=val(x[i]);
        printf("%lld\n",ans);
        return true;
    }
}sam;
int T;
int main(){
    while(true){
        sam.Initialize();
        if(!sam.solve())break;
    }return 0;
}
