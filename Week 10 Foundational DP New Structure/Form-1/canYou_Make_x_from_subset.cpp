#include<bits/stdc++.h>
using namespace std;
int n,x;
vector<int>arr;
// vector<vector<int>>dp;
int dp[100][1001];
bool rec(int level,int sum_taken){
    if(level==n){
        return sum_taken==x;
    }

    if(dp[level][sum_taken]!=-1){
        return dp[level][sum_taken];
    }

    bool ans=false;
    //take
    if(sum_taken+arr[level]<=x){
        ans=ans|rec(level+1,sum_taken+arr[level]);
    }
    ans=ans|rec(level+1,sum_taken);

    return dp[level][sum_taken]=ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>x;
    memset(dp,-1,sizeof(dp));
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<rec(0,0)<<endl;
    return 0;
}