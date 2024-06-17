#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
using pp=pair<lli,lli>;
vector<int>parent;
vector<int>num_nodes;
int rep(int x){
    if(parent[x]==x){
        return x;
    }
    else{
        return parent[x]=rep(parent[x]);
    }
}
void merge(int a,int b){
    a=rep(a);
    b=rep(b);
    if(a==b){
        return;
    }
    else{
        if(num_nodes[a]>num_nodes[b]){
            parent[b]=a;
            num_nodes[a]+=num_nodes[b];
        }
        else{
            parent[a]=b;
            num_nodes[b]+=num_nodes[a];
        }
    }
}
void solve(){
    int n,v,b_cost,r_cost;
    cin>>n>>v>>b_cost>>r_cost;
    parent.resize(n+2);
    num_nodes.resize(n+2);
    for(int i=1;i<=n+1;i++){
        parent[i]=i;
        num_nodes[i]=1;
    }
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<v;i++){
        int a,b;
        edges.push_back({r_cost,{a,b}});
    }
    for(int i=1;i<=n;i++){
        edges.push_back(make_pair(b_cost,make_pair(i,n+1)));
    }
    sort(edges.begin(),edges.end());
    lli ans=0;
    for(auto v:edges){
        int wt=v.first;
        int a=v.second.first;
        int b=v.second.second;
        if(rep(a)!=rep(b)){
            merge(a,b);
            ans+=wt;
        }
    }
    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}