#include <iostream>  
#include <cstring>  
#include <cstdlib>  
#include <cstdio>  
#include <queue>  
#define MAXN 1005  
#define MAXM 50005  
#define INF 1000000000  
#define eps 1e-6  
using namespace std;  
struct node  
{  
    int v, next;  
    double w;  
}edge[MAXM];  
int head[MAXN], e, vis[MAXN], q[50 * MAXM], c[MAXN];  
int n, m;  
double d[MAXN], val[MAXN];  
void insert(int x, int y, double w)  
{  
    edge[e].v = y;  
    edge[e].w = w;  
    edge[e].next = head[x];  
    head[x] = e++;  
}  
bool spfa(double mid)  
{  
    int h = 0, t = 0;  
    for(int i = 1; i <= n; i++)  
    {  
        vis[i] = c[i] = 1;  
        q[t++] = i;  
        d[i] = 0;  
    }  
    while(h < t)  
    {  
        int u = q[h++];  
        vis[u] = 0;  
        for(int i = head[u]; i != -1; i = edge[i].next)  
        {  
            int v = edge[i].v;  
            double w = val[u] - mid * edge[i].w;  
            if(d[v] < d[u] + w)  
            {  
                d[v] = d[u] + w;  
                if(!vis[v])  
                {  
                    q[t++] = v;  
                    vis[v] = 1;  
                    c[v]++;  
                    if(c[v] > n) return 1;  
                }  
            }  
        }  
    }  
    return 0;  
}  
int main()  
{  
    int x, y;  
    double w;  
    e = 0;  
    memset(head, -1, sizeof(head));  
    scanf("%d%d", &n, &m);  
    for(int i = 1; i <= n; i++) scanf("%lf", &val[i]);  
    for(int i = 1; i <= m; i++)  
    {  
        scanf("%d%d%lf", &x, &y, &w);  
        insert(x, y, w);  
    }  
    double low = 0, high = 1000;  
    while(high - low > eps)  
    {  
        double mid = (low + high) / 2;  
        if(spfa(mid)) low = mid;  
        else high = mid;  
    }  
    printf("%.2f\n", low);  
    return 0;  
}  

