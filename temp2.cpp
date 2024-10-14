#include<bits/stdc++.h>
using namespace std;
bool is_cycle=false;
vector<int>state;
vector<vector<int>>g;
void dfs(int node){
    if(state[node]==2){
        return;
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    g.resize(n);
    state.assign(n,1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(0);
    cout<<is_cycle<<endl;

    return 0;
}