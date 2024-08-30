#include<bits/stdc++.h>
using namespace std;
// ((nC2-n)C2)-n(n-4) -->answer
using lli=long long int;

lli fastExpo(lli a,lli b){ //O(lnb)
    lli m=1e9+7;
    lli ans=1;
    while(b){
        if(b%2==1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b/=2;
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    lli m=1e9+7;
    lli T=fastExpo(24,m-2);
    lli one=((n%m)*((n-1)%m))%m;
    lli two=(one*((n-2)%m) )%m;
    lli three=(two*((n-3)%m))%m;
    lli ans=(three*T)%m;
    cout<<ans<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}