#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<string>G;

vector<int> split(string s){
    int len=s.size();
    vector<int>ans;
    int val=0;
    for(int i=0;i<len;++i){
        if(s[i]=='.'){
            ans.push_back(val);
            val=0;
        }else{
            val=val*10+s[i]-'0';
        }
    }
    ans.push_back(val);
    return ans;
}

bool cmp(string x,string y){
    vector<int>x_num=split(x);
    vector<int>y_num=split(y);
    int i=0;
    for(i=0;i<x_num.size()&&i<y_num.size();++i){
        if(x_num[i]==y_num[i])continue;
        else if(x_num[i]<y_num[i])return true;
        else return false;
    }
    if(i==x_num.size())return true;
    else return false;
}

int main(){
    int N;scanf("%d",&N);
    for(int i=0;i<N;++i){
        string s;cin>>s;
        G.push_back(s);
    }
    sort(G.begin(),G.end(),cmp);
    for(int i=0;i<N;++i)
        cout<<G[i]<<endl;
    return 0;
}
