#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
using pp=pair<lli,lli>;
lli m = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    // cout<<s<<endl;
    vector<lli>occ[26];
    for(int i=0;i<26;i++){
        occ[i].emplace_back(-1);
    }
    for(int i=0;i<n;i++){
        occ[s[i]-'a'].emplace_back(i);
    }
    for(int i=0;i<26;i++){
        occ[i].emplace_back(n);
    }

    lli ans=0;
    for(int i=0;i<26;i++){
        for(int j=1;j<occ[i].size()-1;j++){
            ans+=(occ[i][j]-occ[i][j-1])*(occ[i][j+1]-occ[i][j]);
        }
    }
    
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}