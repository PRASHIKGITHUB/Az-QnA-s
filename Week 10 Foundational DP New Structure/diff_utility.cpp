/*
x="XMJYAUZ"
y="XMJAATZ"
XMJ-YA-U+A+TZ  --> minimum length possible
*/

#include<bits/stdc++.h>
using namespace std;
string x,y;
int n,m;
vector<vector<int>>back;
vector<vector<int>> dp;
int rec(int i,int j){//what's the minimum length possible if you start with i,j
    if(i==n && j==m){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans=1e9;
    if(i<n){
        if(1+rec(i+1,j)<ans){
            ans=1+rec(i+1,j);
            back[i][j]=1;
        }
    }
    if(j<m){
        if(1+rec(i,j+1)<ans){
            ans=1+rec(i,j+1);
            back[i][j]=2;
        }
    }
    
    if(i<n && j<m && x[i]==y[j]){
        if(1+rec(i+1,j+1)<ans){
            ans=1+rec(i+1,j+1);
            back[i][j]=3;
        }
    }

    return dp[i][j]=ans;
}

void generate(int i,int j){
    if(i==n && j==m){
        return;
    }
    if(back[i][j]==1){
        cout<<"-"<<x[i];
        generate(i+1,j);
    }else if(back[i][j]==2){
        cout<<"+"<<y[j];
        generate(i,j+1);
    }else{
        cout<<x[i];
        generate(i+1,j+1);
    }
}
void solve(){
    cin>>x>>y;
    n=x.length();
    m=y.length();
    dp.assign(n+1,vector<int>(m+1,-1));
    back.assign(n+1,vector<int>(m+1,-1));
    cout<<rec(0,0)<<endl;
    generate(0,0);
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}