#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int>par;
vector<int>isLeaf;
vector<int>subtreez;
vector<int>dep;
vector<int>numChild;
void dfs(int root,int parent,int depth){
    par[root]=parent;
    dep[root]=depth;
    numChild[root]=0;
    subtreez[root]=1;
    for(auto v:g[root]){
        if(v!=parent){
            numChild[root]++;
            dfs(v,root,depth+1);
            subtreez[root]+=subtreez[v];
        }
    }
    if(numChild[root]==0){
        isLeaf[root]=1;
    }
}
int main(){
    int n;
    cin>>n;
    g.resize(n);
    isLeaf.resize(n);
    subtreez.resize(n);
    dep.resize(n);
    numChild.resize(n);
    par.resize(n);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    return 0;
}