#include <bits/stdc++.h>
using lli = long long;
using namespace std;
lli m=1e9+7;
lli s;
lli n;
lli sumdigits(lli k){
    lli sum=0;
    while(k){
        sum+=k%10;
        k/=10;
    }
    return sum;
}
bool check(lli x){
    if(x-sumdigits(x)>=s){
        return 1;
    }
    else{
        return 0;
    }
}
void solve(){

    cin>>n>>s;
    lli low=1;
    lli high=n;
   
    
    lli ans=0;
    
    while(low<=high){
        lli mid=low+(high-low)/2;
        if(check(mid)){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
        
    }
    if(ans){
        cout<<(n-ans+1)<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
    
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  
}