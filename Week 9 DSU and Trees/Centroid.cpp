#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
using pp=pair<lli,lli>;
int n;
vector<int>parent;
vector<int>sub_size;
vector<vector<int>>tree;
vector<int>centroids;
void bfs(int node,int par){
    parent[node]=par;
    sub_size[node]=1;
    bool valid=true;
    for(auto v:tree[node]){
        if(v!=par){
            bfs(v,node);
            sub_size[node]+=sub_size[v];
            if(sub_size[v]>n/2)valid=false;
        }
    }
    if(n-sub_size[node]>n/2)valid=false;
    if(valid)centroids.emplace_back(node);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    tree.resize(n+1);
    sub_size.resize(n+1);
    parent.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    bfs(1,0);
    sort(centroids.begin(),centroids.end());
    cout<<centroids[0]<<endl;

    return 0;
}