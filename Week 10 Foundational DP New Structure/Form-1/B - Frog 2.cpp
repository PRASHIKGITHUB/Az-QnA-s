#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[100100];
int dp[100100];
int rec(int level){
  if(level==n-1){
    return 0;
  }
  int ans=1e9;
  if(dp[level]!=-1){
    return dp[level];
  }
  for(int i=1;i<=k;i++){
    if(level+i<n){
      ans=min(ans,rec(level+i)+abs(arr[level]-arr[level+i]));
    }
  }
  return dp[level]=ans;
}
int main(){
  cin>>n>>k;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<rec(0)<<endl;
  return 0;
}