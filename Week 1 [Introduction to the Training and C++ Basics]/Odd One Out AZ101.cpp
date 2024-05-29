#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    long long ans=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        ans=ans^temp;
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