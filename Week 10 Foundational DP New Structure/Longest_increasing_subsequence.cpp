#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1001];
int dp[1001];
int rec(int l){
    //best index ending at level
    if(l<0){
        return 0;
    }
    if(dp[l]!=-1){
        return dp[l];
    }

    int ans=1;
    for(int p=0;p<l;p++){
        if(arr[p]<arr[l]){
            ans=max(ans,1+rec(p));
        }
    }

    return dp[l]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int best=0;
    for(int i=0;i<n;i++){ //this loop has to be there 
        best=max(rec(i),best);
    }
    return 0;
}