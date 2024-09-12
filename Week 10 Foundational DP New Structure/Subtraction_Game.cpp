#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
using pp=pair<lli,lli>;
lli m = 1e9 + 7;
int x;
int dp[200005];
int rec(int x){
    if(x==0){
        return dp[0]= 0;
    }

    return (x%3);

    if(dp[x]!=-1){
        return dp[x];
    }

    int ans=0;
    for(int i=0;(x-(1<<i))>=0;i++){
        if(rec(x-(1<<i))==0){
            ans=1;
            break;
        }
    }

    return dp[x]=ans;
}
void solve(){
    cin>>x;
    
    int ans=rec(x);

    if(ans==0){
        cout<<"Abhishek"<<endl;
    }
    else{
        cout<<"Vivek"<<endl;
    }
    // for(int i=0;i<x;i++){
    //   cout<<dp[i]<<endl;
    // }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    while(t--){
        solve();
    }
    return 0;
}