#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
using pp=pair<lli,lli>;
lli m = 1e9 + 7;
string s1,s2,s3;
int dp[101][101][101];
int rec(int i,int j,int k){
    if(i==s1.length() || j==s2.length() || k==s3.length()){
        return 0;
    }

    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    
    int ans=-1e9;
    ans=max({rec(i+1,j,k),rec(i,j+1,k),rec(i,j,k +1)});

    if(s1[i]==s2[j] && s2[j]==s3[k]){
        ans=max(ans,1+rec(i+1,j+1,k+1));
    }

    return dp[i][j][k]=ans;
    
}
void solve(){
    memset(dp,-1,sizeof(dp));
    
    cin>>s1>>s2>>s3;
    cout<<rec(0,0,0)<<endl;//rec(i,j,k)---> what's the best possible common length you can get if you start with i,j,k

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