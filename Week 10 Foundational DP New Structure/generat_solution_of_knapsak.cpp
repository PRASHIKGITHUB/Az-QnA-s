#include<bits/stdc++.h>
using namespace std;
int n,W;
int v[3001];
int w[3001];
int dp[3001][3001];
vector<int>sol;
int rec(int level,int weight_remain){
    if(level==n){
        return 0;
    }

    if(dp[level][weight_remain]!=-1){
        return dp[level][weight_remain];
    }

    int ans=rec(level+1,weight_remain);//dont take
    if(w[level]<=weight_remain){
        ans=max(ans,v[level]+rec(level+1,weight_remain-w[level]));
    }

    return dp[level][weight_remain]=ans;

}
void generate(int i,int x){
    if(i==n){
        return;
    }
    int donttake=rec(i+1,x);
    if(w[i]<=x){
        //you can take
        int take=rec(i+1,x-w[i])+v[i];
        if(take>donttake){
            sol.emplace_back(i);
            generate(i+1,x-w[i]);
        }
        else{
            generate(i+1,x);
        }
    }
    else{
        //cant take
        generate(i+1,x);
    }

}
int main(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>v[i]>>w[i];
    }
    memset(dp,-1,sizeof(dp));

    cout<<rec(0,W)<<endl;

    generate(0,W);
    for(auto i:sol){
        cout<<i<<" ";
    }
    return 0;
}