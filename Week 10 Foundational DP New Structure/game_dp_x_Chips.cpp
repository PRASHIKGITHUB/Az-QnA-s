#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[101];
int dp[100001];
int rec(int x){
    if(x==0){
        return 0;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(x-arr[i]>=0 && rec(x-arr[i])==0){
            ans=1;
            break;
        }
    }

    return dp[x]=ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(rec(k)==0){
        cout<<"Second"<<endl;//taro is losing
    }
    else{
        cout<<"First"<<endl;
    }
    return 0;
}