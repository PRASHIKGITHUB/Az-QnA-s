// Solution 1
#include <bits/stdc++.h>
using lli = long long;
using namespace std;
lli m=1e9+7;
lli fastExpo(lli a,lli b){
    lli ans=1;
    while(b){
        if(b%2==1){
            ans=(ans%m*a%m)%m;
        }
        a=(a*a)%m;
        b/=2;
    }
    return ans;
}
void solve(){
   lli n,q,k;
    cin>>n>>q>>k;
    lli arr[n+1];
    arr[0]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    lli kpower[n+1];
    kpower[0]=0;
    kpower[1]=fastExpo(k,1);
    for(int i=2;i<=n;i++){
        kpower[i]=(kpower[i-1]%m*kpower[1]%m)%m;
    }
    lli power[n+1];
    power[0]=0;
    power[1]=((arr[1]%m)*(k%m))%m;
    for(int i=2;i<=n;i++){
        power[i]=(power[i-1]%m+(arr[i]%m*kpower[i])%m)%m;
    }
    
    lli kp[n+1];
    kp[0]=0;
    kp[1]=fastExpo(k,m-2);
    for(int i=2;i<=n;i++){
        kp[i]=(kp[i-1]%m*kp[1]%m)%m;
    }
    
    while(q--){
        lli l,r;
        cin>>l>>r;
        lli ans;
        ans=((power[r]-power[l-1])%m*(kp[l]%m))%m;
        ans=(ans+m)%m;
        cout<<ans<<endl;
    }
    
    
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  solve();
}