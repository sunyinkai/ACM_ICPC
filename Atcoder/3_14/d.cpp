#include<cstdio>
#include<cstring>
const int MAXN=11;
char s[MAXN];
int N;
int visit[MAXN];
bool check(){
    if(N==1)return true;
    memset(visit,0,sizeof(visit));
    int max_num=0;
    bool isok=true;
    for(int i=1;i<N;++i){
        if(s[i]-'a' == max_num+1)max_num++;
        else if(s[i]-'a'<max_num+1);
        else isok=false;
    }
    return isok;
}

void dfs(int h){
    if(h==N){
        s[N+1]='\0';
        if(check()){
            printf("%s\n",s);
        }
        return ;
    }
    for(int i='a';i<='a'+h;++i){
        s[h]=i;
        dfs(h+1);
    }
}

int main(){
    scanf("%d",&N);
    dfs(0);
    return 0;
}
