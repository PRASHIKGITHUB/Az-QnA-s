#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
void solve(){
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    lli ans=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        mp[temp]++;
    }
    if(k==0){
        for(auto i:mp){
            if(i.second!=1){
                ans+=1LL*i.second*(i.second-1)/2;
            }
        }
        cout<<ans<<endl;
        return;
    }
    for(auto i:mp){
        int b=i.first+k;
        if(mp.find(b)!=mp.end()){
            ans+=1LL*mp[i.first]*mp[b];
        }
    }
    // ans/=2;
    cout<<ans<<endl;;
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