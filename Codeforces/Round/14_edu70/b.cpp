#include<cstdio>
#include<cstring>
const int MAXN=2e6+7;
const int MAXM=12;
const int INF=1e9+7;
char s[MAXN];

int ans[MAXM][MAXM];
int step[MAXM][MAXM];
int len;

int solve(int x,int y){
    int res=0;
    for(int i=0;i<=len-2;++i){
        int ans=INF;
        if(step[s[i]-'0'][s[i+1]-'0']){
            ans=step[s[i]-'0'][s[i+1]-'0'];
        }else{
            for(int cnt_x=0;cnt_x<=9;++cnt_x){
                for(int cnt_y=0;cnt_y<=9;++cnt_y){
                    if(cnt_x==0&&cnt_y==0)continue;
                    if((cnt_x*x+cnt_y*y+s[i]-'0')%10==s[i+1]-'0'){
                        if(cnt_x+cnt_y<ans){
                            ans=cnt_x+cnt_y;
                            break;
                        }
                    }
                }
            }
            step[s[i]-'0'][s[i+1]-'0']=ans;
        }
 //       printf("%c --> %c ans:%d\n",s[i],s[i+1],ans);
        if(ans==INF)return -1;
        if(ans!=0)res+=ans-1;
    }
    return res;
}

int main(){
    scanf("%s",s);
    len=strlen(s);
    solve(0,1);
    for(int i=0;i<10;++i){
        for(int j=i;j<10;++j){
            memset(step,0,sizeof(step));
            ans[i][j]=solve(i,j);
            ans[j][i]=ans[i][j];
        }
    }
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
