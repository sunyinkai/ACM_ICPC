
#include<iostream>  
#include<algorithm>  
#include<cstring>  
#include<cstdio>  
using namespace std;  
const int maxn = 1010;  
const int maxm = 505;  
int g[maxn][maxn];//邻接表存图  
int linker[maxm][maxn];//linker[i][0]表示右边点已经匹配到的左边点的个数  
int num[maxm];//右边最大的匹配数  
int uN, vN;//uN左边点的个数,vN左边点的个数  
bool used[maxm];//右边的点是否被访问过  
bool dfs(int u)  
{  
    for(int v = 0; v < vN; v++)  
        if(g[u][v] && !used[v])  
        {  
            used[v] = true;  
            if(linker[v][0] < num[v])  
            {  
                linker[v][++linker[v][0]] = u;  
                return true;  
            }  
            for(int i = 1; i <= linker[v][0]; i++)  
                if(dfs(linker[v][i]))  
                {  
                    linker[v][i] = u;  
                    return true;  
                }  
        }  
    return false;  
}  
int hungary()  
{  
    int res = 0;  
    for(int i = 0; i < vN; i++)  
        linker[i][0] = 0;  
    for(int u = 0; u < uN; u++)  
    {  
        memset(used, false, sizeof(used));  
        if(dfs(u))  
            res++;  
    }  
    return res;  
}  
bool judge(int mid)  
{  
    for(int i = 0; i < vN; i++)  
        num[i] = mid;  
    int ret = hungary();  
    if(ret == uN) return true;  
    else return false;  
}  
int main()  
{  
    int vex;  
    while(scanf("%d%d", &uN, &vN) != EOF)  
    {  
        if(!uN && !vN) break;  
        memset(g, 0, sizeof(g));  
        for(int i = 0; i < uN; i++)  
        {  
            char name[20];  
            scanf("%s", name);  
            while(getchar() != '\n')  
            {  
                scanf("%d", &vex);  
                g[i][vex] = 1;  
            }  
        }  
        int left = 0, right = uN, mid;  
        while(left < right)  
        {  
            mid = (left + right) >> 1;  
            if(judge(mid))  
                right = mid;  
            else  
                left = mid + 1;  
        }  
        printf("%d\n", right);  
    }  
    return 0;  
}  

