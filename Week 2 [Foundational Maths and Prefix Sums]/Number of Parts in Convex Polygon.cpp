#include<bits/stdc++.h>
using namespace std;
using lli =long long int;
lli m=1e9+7;
lli expo(lli a,lli b){
    lli ans=1;
    while(b){
        if(b%2){
            ans=((ans%m)*(a%m))%m;
        }
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}
void solve(){
    //1+nC2-n+nC4
    lli ans;
    lli n;
    cin>>n;
    lli t1=((((n%m)*((n-1)%m))%m)*(expo(2,m-2)))%m;
    lli t2=n;
    lli t3=((((n%m*(n-1)%m)%m*(n-2)%m)%m*(n-3)%m)%m*(expo(24,m-2))%m)%m;
    
    ans=(((1+t1)%m-t2%m+m)%m+t3%m)%m;
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