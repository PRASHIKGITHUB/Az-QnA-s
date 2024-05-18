#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
void solve(){
   int n;
   cin>>n;
   unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        mp[temp]++;
    }
    int ans=0;
    for(auto i:mp){
        if(i.first>i.second){
            ans=ans+i.second;
        }
        else if(i.first<i.second){
            ans=ans+(i.second-i.first);
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