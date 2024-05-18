#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
void solve(){
  int n,m;
    cin>>n>>m;
    map<lli,int>mp;
    for(int i=0;i<n;i++){
        lli x,u;
        cin>>x>>u;
        mp[x*u]++;
    }
    int ans=0;
    for(int i=0;i<m;i++){
        lli y,v;
        cin>>y>>v;
        if(mp.find(y*v)!=mp.end()){
            mp[y*v]--;
            if(!(mp[y*v]<0)){
            ans++;

            }
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