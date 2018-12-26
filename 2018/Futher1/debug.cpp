#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int N = 100002;
int cap[12],map[N][12],vlink[12],link[12][N];
bool vis[12];
int n,m;
int in()  
{  
    char ch;  
    int a = 0;  
    while((ch = getchar()) == ' ' || ch == '\n');  
    a += ch - '0';  
    while((ch = getchar()) != ' ' && ch != '\n')  
    {  
        a *= 10;  
        a += ch - '0';  
    }  
    return a;  
}
int path(int s)
{
    for(int i=0;i<m;i++)
    {
        if(map[s][i] && !vis[i])
        {
            vis[i]=true;
            if(vlink[i]<cap[i])
            {
                link[i][vlink[i]++]=s;
                return 1;
            }
            for(int j=0;j<vlink[i];j++)
            {
                if(path(link[i][j]))
                {
                    link[i][j]=s;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                map[i][j]=in();
        for(int i=0;i<m;i++)
            scanf("%d",&cap[i]);
        memset(vlink,0,sizeof(vlink));
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            memset(vis,false,sizeof(vis));
            if(!path(i))
            {
                flag=false;
                break;
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
