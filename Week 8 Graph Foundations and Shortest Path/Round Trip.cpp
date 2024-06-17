#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
int n,m;
bool is_cycle=false;
vector<vector<int>>g;
vector<int>state;
vector<int>parent;
//state 0 means not visited
void dfs(int node,int par){
    state[node]=2;
    parent[node]=par;
    for(auto v:g[node]){
        if(v==parent[node]){
            continue;//if it was directed graph this won't be here
        }
        if(state[v]==1){
            dfs(v,node);
        }
        else if(state[v]==2){
            is_cycle=true;
        }
    }
    state[node]=3;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    g.resize(n+1);
    state.assign(n+1,1);
    parent.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);// also this
    }
    for(int i=1;i<=n;i++){
        if(state[i]==1){
            dfs(i,0);
        }
    }
    if(is_cycle){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}