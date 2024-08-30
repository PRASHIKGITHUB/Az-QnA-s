#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int dp[1001][1001];
int n,m;

int rec(int r,int c){

    if(r==0 && c==0){
        return arr[0][0];
    }//base case

    if(r<0 || c<0){
        return -1e9;
    }//pruning

    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    //check if cached?

    int ans;
    ans=max(rec(r-1,c)+arr[r][c],rec(r,c-1)+arr[r][c]);
    //transition

    return dp[r][c]=ans;
    //save and return 

}

int main(){
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    cout<<rec(n-1,m-1)<<endl;
    return 0;
}