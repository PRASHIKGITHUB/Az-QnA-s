#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
using pp=pair<lli,lli>;
int n,m;
int arr[1001][1001];
int dp[1001][1001];
int rec(int r,int c){

    if(r<0 || c<0){
        return 0;
    }

    if(dp[r][c]!=-1){
        return dp[r][c];
    }

    int ans=0;
    if(arr[r][c]!=0){
        ans=1+min({rec(r-1,c),rec(r,c-1),rec(r-1,c-1)});
    }
    
    return dp[r][c]=ans;
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            dp[i][j]=-1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,rec(i,j));
        }
    }
    cout<<1LL*ans*ans<<endl;
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