#include<bits/stdc++.h>
using namespace std;
//nC2-N;
using lli=long long int;
lli fastExpo(lli a,lli b,lli c){
    lli ans=1;
    while(b!=0){
        if(b%2==1){
            ans=(ans*a)%c;
        }
        a=(a*a)%c;
        b/=2;
    }
    return ans;
}

void solve(){
    
    lli n;
    cin>>n;
    lli mod=1e9+7;
    lli temp=fastExpo(2,mod-2,mod);
    lli first=n%mod;
    lli second=(n-1)%mod;
    lli ans=(((((first)*(second))%mod )* temp)-n%mod)%mod;
    cout<<ans<<endl;
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;  
    while(t--){
        solve();
    }
    return 0;
}