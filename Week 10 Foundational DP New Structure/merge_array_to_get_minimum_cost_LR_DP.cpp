//cost of adding two elements is the product of those numbers 
#include<bits/stdc++.h>
using namespace std;
int dp[501][501];
int arr[501];
int n;
int rec(int l,int r){//maximum cost to merge all the elements from l to r
    if(l==r){
        return arr[l];
    }

    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    int tot=0;
    int sum=0;
    for(int i=l;i<=r;i++){
        tot+=arr[i];
    }

    int ans=0;
    for(int mid=l;mid<r;mid++){
        sum+=arr[mid];
        ans=max(ans,rec(l,mid)+rec(mid+1,r)+(sum%100)*((tot-sum)%100));
    }

    return dp[l][r]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans=rec(0,n-1);
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    solve();
    return 0;
}