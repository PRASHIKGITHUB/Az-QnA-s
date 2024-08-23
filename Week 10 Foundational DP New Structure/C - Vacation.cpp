#include<bits/stdc++.h>
using namespace std;
int n;
int A[100100],B[100100],C[100100];
int dp[100100][3];
int rec(int level,int prev_taken){
    if(level==n){
        return 0;
    }

    if(prev_taken>=0 &&dp[level][prev_taken]!=-1){
        return dp[level][prev_taken];
    }
    //choices
    int ans=0;
    if(prev_taken!=0){
        ans=A[level]+rec(level+1,0);
    }
    if(prev_taken!=1){
        ans=max(ans,B[level]+rec(level+1,1));
    }
    if(prev_taken!=2){
        ans=max(ans,C[level]+rec(level+1,2));
    }

    return dp[level][prev_taken]=ans;
    
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i]>>B[i]>>C[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,-1)<<endl;
    return 0;
}