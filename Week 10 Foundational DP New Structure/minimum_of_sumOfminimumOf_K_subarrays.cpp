#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
int arr[1001];
int dp[1001][1001];

int rec(int l,int k){
    //pruning
    //basecase
    if(l==-1){
        if(k==0){
            return 0;
        }
        else{
            return 1e9;
        }
    }

    //cache check
    if(dp[l][k]!=-1){
        return dp[l][k];
    }
    //transition
    int ans=1e9;
    int min_seen=arr[l];
    for(int j=l-1;j>=-1;j--){
        ans=min(ans,rec(j,k-1)+min_seen);
        min_seen=min(min_seen,arr[j]);//running minimum
    }

    //save and return
    return dp[l][k]=ans;
}
signed main(){
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<rec(n-1,k)<<endl;


    return 0;
}