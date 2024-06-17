#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;

int n,m,components;
lli cost;
vector<int>weight;
vector<int>parent;
int rep(int x){
    if(parent[x]==x){
        return x;
    }
    else{
        return parent[x]=rep(parent[x]);
    }
}
void merge(int a,int b,int wt){
    a=rep(a);
    b=rep(b);
    if(a==b){
        return ;
    }

    if(weight[a]>weight[b]){
        parent[b]=a;
        weight[a]+=weight[b];
        components--;  
    }
    else{
        parent[a]=b;
        weight[b]+=weight[a];
        components--;
    }
    cost+=wt;
}
vector<pair<int,pair<int,int>>>edge_list;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    components=n;
    weight.resize(n+1);
    parent.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        weight[i]=1;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge_list.push_back({c,{a,b}});
    }
    sort(edge_list.begin(),edge_list.end());
    for(auto e:edge_list){
        int a=e.second.first;
        int b=e.second.second;
        int wt=e.first;
        merge(a,b,wt);
    }
    if(components==1){
        cout<<cost<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}