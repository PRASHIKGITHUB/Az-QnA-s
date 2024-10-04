#include<bits/stdc++.h>
using namespace std;
int n;
string T="0100";//note that it is independent of T

int dp[100001][101];
int rec(int level,int state){
    
    if(state==T.length()){
        return 0;
    }

    if(level==n){
        return 1;
    }

    if(dp[level][state]!=-1){
        return dp[level][state];
    }

    int ans=rec(level+1,state)+rec(level+1,state+1);

    return dp[state][level]= ans;
}

void solve(){ 
    cin>>n;
    memset(dp,-1,sizeof(dp));
    int ans=rec(0,0);
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;

    while(t--){
        solve();
    }

    return 0;
}