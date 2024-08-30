#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[1001][1001];
int dp[1001][1001];
int rec(int i,int j){//number of paths from 1,1 to i,j
    if(i==1 && j==1){
        return 1;
    }

    if(i<=0 || j<=0 || arr[i][j]==0){//arr[i][j]=0 means it's an obstacle
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    ans+=rec(i-1,j)+rec(i,j-1);

    return dp[i][j]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<rec(n,m)<<endl;
    return 0;
}