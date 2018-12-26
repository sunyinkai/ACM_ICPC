// 1、基本定义。
// 子串：字符串S的子串r[i...j]。
// 后缀：以i开始的后缀表示为Suffix(i)。
// 大小比较：按字典序。
// 后缀数组：SA是一个一维数组。将S的后缀从小到大排序后，后缀的开头位置顺次放入SA。(SA[i]=j：排在第i个的是Suffix(j))
// 名词数组：Rank[i]是Suffix(i)在后缀中从小到大排列的名次。(Rank[i]=j：Suffix(i)排在第j个)
// 后缀数组和名次数组为互逆运算：设Rank[i]=j，则SA[j]=i。
// 2、倍增算法。
// 目的：设字符串长度为n，在O(nlog2n)求出SA数组和Rank数组。
// 3、后缀数组的应用。
// height数组：height[i]=Suffix(sa[i-1])和Suffix(sa[i])的最长公共前缀，也就是排名相邻的两个后缀的最长公共前缀。
// h数组：h[i]=height[rank[i]]=Suffix(i)和在它前一名的后缀的最长公共前缀。
// h数组的性质：h[i]>=h[i-1]-1。
// 证明：设Suffix(k)是排在Suffix(i-1)前一名的后缀，则它们的最长公共前缀就是h[i-1]。那么Suffix(k+1)将排在Suffix(i)的前面。
// a、若Suffix(k)与Suffix(i-1)的最长公共前缀<=1，即h[i-1]<=1，h[i]>=0显然成立。
// b、若Suffix(k)与Suffix(i-1)的最长公共前缀>=2，Suffix(k)与Suffix(i-1)同时去掉首字符得到Suffix(k+1)
// 与Suffix(i)，则Suffix(k+1)排在Suffix(i)的前面，且Suffix(k+1)与Suffix(i)的最长公共前缀=h[i-1]-1。
// 设Suffix(t)是排在Suffix(i)前一名的后缀，则它们的最长公共前缀就是h[i]，那么Suffix(t)=Suffix(k+1)
// 或者Suffix(t)排在Suffix(k+1)前面，则h[i]>=h[i-1]-1。



#include<cstdio>
const int MAXN=1e5+7;

int wa[MAXN], wb[MAXN], wv[MAXN], ws[MAXN];
inline bool cmp(int *r, int a, int b, int len)
{
    return r[a] == r[b] && r[a + len] == r[b + len];
}
void SA(char *r, int *sa, int n, int m)
{
    //r为字符串数组，sa为后缀数组，n=strlen(s)+1，m为max(r[i])+1。
    int i, j, p, *x = wa, *y = wb, *t;

    //对长度为1的字符串基数排序。
    for (i = 0; i < m; i++)
        ws[i] = 0; //清零。
    for (i = 0; i < n; i++)
        ws[x[i] = r[i]]++; //统计各相同字符的个数。
    for (i = 1; i < m; i++)
        ws[i] += ws[i - 1]; //统计小于等于i的字符共有多少个。
    for (i = n - 1; i >= 0; i--)
        sa[--ws[x[i]]] = i; //小于等于r[i]共有ws[x[i]]个，因此r[i]排在第ws[x[i]]个。

    for (j = p = 1; p < n; j <<= 1, m = p) //p是第二关键字为0的个数，j是当前比较的字符串长度。
    {
        //对第二关键字基数排序。
        //y[s]=t表示排在第s个的起点在t，即y[s]对第二关键字排序，但y[s]的值指向第一关键字的位置。
        for (p = 0, i = n - j; i < n; i++)
            y[p++] = i; //在n-j之后的第二关键字都为0，排在前面，即第p个。
        for (i = 0; i < n; i++)
        {
            if (sa[i] >= j) //如果排在第i个的字符串起点在sa[i]，满足sa[i]>=当前字符串长度j。
                y[p++] = sa[i] - j; //对于sa[i]-j为起点的第二关键字排在前面。
        }

        //对第一关键字基数排序。
        for (i = 0; i < m; i++)
            ws[i] = 0; //清零。
        for (i = 0; i < n; i++)
            ws[wv[i] = x[y[i]]]++; //第二关键字排在第i个的起点在y[i]，x[y[i]]就是y[i]指向的字符，ws进行个数统计。
        for (i = 1; i < m; i++)
            ws[i] += ws[i - 1]; //统计字符小于等于i的个数。
        for (i = n - 1; i >= 0; i--) //wv[i]是排在第i个第二关键字对应的第一关键字。
            sa[--ws[wv[i]]] = y[i]; //y[i]就是第一关键字的位置。
        for (t = x, x = y, y = t, x[sa[0]] = 0, p = i = 1; i < n; i++) //交换x，y的地址，x保存当前rank值，y为前一次rank值。
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        //若rank[sa[i-1]]=rank[sa[i]]，则必然sa[i-1]+j没有越界，因为不可能有相等的后缀。
    }
}

int rank[MAXN], height[MAXN];
void Height(int *r, int *sa, int n)
{
    int i, j, k;
    for (i = 1; i <= n; i++)
        rank[sa[i]] = i;
    for (i = k = 0; i < n; height[rank[i++]] = k)
        for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
    //若k>0，从k-1开始找最长公共前缀。
    return;
}

int main(){
	
	return 0;
}
