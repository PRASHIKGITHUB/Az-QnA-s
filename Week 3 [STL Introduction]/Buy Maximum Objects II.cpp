#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
void solve(){
   
    int n,q;
    cin>>n>>q;
    // cout<<"n:"<<n<<"q:"<<q<<endl;
    vector<lli>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++){
        v[i]+=v[i-1];
    }
    while(q--){
        int m;
        cin>>m;
        auto i=upper_bound(v.begin(),v.end(),m);
        int ans=i-v.begin();
        cout<<ans<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}