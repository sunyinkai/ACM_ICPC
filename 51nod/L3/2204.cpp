//tag: greedy
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<string>vc;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        string s;cin>>s;
        vc.push_back(s);
    }
    sort(vc.begin(),vc.end(),[](string x,string y){
            return x+y<y+x;});
    for(auto s:vc)
        cout<<s;
    cout<<endl;
    return 0;
}
