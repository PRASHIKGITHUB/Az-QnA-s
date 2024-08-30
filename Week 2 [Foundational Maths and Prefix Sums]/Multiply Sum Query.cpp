// Solution 1
#include <bits/stdc++.h>
using lli = long long;
using namespace std;
lli m=1e9+7;
void solve(){
    lli n,q;
    cin>>n>>q;
    lli pre[n+1];
    pre[0]=0;
    lli arr[n+1];
    arr[0]=0;
    for(lli i=1;i<=n;i++){
         cin>>arr[i];
    }
    pre[1]=arr[1];
    for(int i=2;i<=n;i++){
        pre[i]=(pre[i-1]%m+arr[i]%m)%m;
    }

    lli first[n+1];
    first[0]=0;
    first[1]=arr[1];
    for(lli i=2;i<=n;i++){
        first[i]=(first[i-1]%m+((i%m)*(arr[i]%m))%m)%m;
    }

    while(q--){
        lli l,r;
        cin>>l>>r;
        lli ans;
        ans=(((1-l)%m)*(pre[r]%m-pre[l-1]%m)%m+(first[r]%m-first[l-1]%m)%m)%m;
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