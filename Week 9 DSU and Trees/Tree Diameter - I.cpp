#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
using pp=pair<lli,lli>;
vector<vector<int>>g;
int n;
vector<int>depth;
vector<int>parent;
void dfs(int root,int dep,int par){
    depth[root]=dep;
    parent[root]=par;
    for(auto v:g[root]){
        if(v!=par){
            dfs(v,dep+1,root);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    g.resize(n+1);
    depth.resize(n+1);
    parent.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1,0,0);
    int dis=INT_MIN;
    int idx=0;// it will store the node which is at maximum distance from node 1
    for(int i=1;i<=n;i++){
        if(dis<depth[i]){
            idx=i;
            dis=depth[i];
        }
    }
    dfs(idx,0,0);
    int ans=INT_MIN;
    for(int i=1;i<=n;i++){
        ans=max(ans,depth[i]);
    }
    cout<<ans<<endl;
    return 0;
}