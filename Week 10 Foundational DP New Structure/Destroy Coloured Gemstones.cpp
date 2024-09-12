#include<bits/stdc++.h>
using namespace std;
int n;
int arr[101];
int dp[101][101];
int rec(int l,int r){
    if(l+1==r && arr[l]==arr[r]){
        return 1;
    }
    else if(l+1==r){
        return 2;
    }
    if(l==r){
        return 1;
    }
    if(l>r){
        return 0;
    }
   
   if(dp[l][r]!=-1){
    return dp[l][r];
   }
    int ans=1e9;
    if(arr[l]==arr[r]){
        ans=min(ans,rec(l+1,r-1));
    }
   
    for(int mid=l;mid<r;mid++){
       ans=min(rec(l,mid)+rec(mid+1,r),ans);
    }
    return dp[l][r]= ans;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=rec(0,n-1);
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