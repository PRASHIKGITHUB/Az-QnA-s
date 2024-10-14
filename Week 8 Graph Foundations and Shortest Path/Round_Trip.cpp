#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
int n,m;
bool is_cycle=false;
vector<vector<int>>g;
vector<int>state;
vector<int>parent;
vector<int>any_cycle;
void dfs(int node,int par){
    state[node]=2;
    parent[node]=par;
    for(auto v:g[node]){
        if(v==parent[node]){//if it was directed graph this won't be here --> you can see this in round trip 2
            continue;
        }
        if(state[v]==1){//1 means not visited --> forward edge
            dfs(v,node);
        }
        else if(state[v]==2){// 2 means the v is already visited and we are going on it (cycle detected) --> back edge
            if(is_cycle==0){//this is just for printing any cycle
                int temp=node;
                while(temp!=v){
                    any_cycle.push_back(temp);
                    temp=parent[temp];
                }
                any_cycle.push_back(v);
            }
            is_cycle=true;
        }
    }
    state[node]=3;//3 means node and it's neighbours got visited --> cross edge
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
        for(auto ele:any_cycle){
            cout<<ele<<" ";
        }
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}