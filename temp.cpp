#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
int n,m;
using pp=pair<int,int>;

vector<vector<int>>g;
vector<vector<int>>dis;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool check(int x,int y){
    if(x>=1 && x<=n && y>=1 && y<=m){
        return true;
    }
    return false;
}
map<pp,int>neighbour(pp node){
    map<pp,int>ans;
    for(int i=0;i<4;i++){
        int x=node.first+dx[i];
        int y=node.second+dy[i];
        if(check(x,y)){
            if(g[node.first][node.second]==g[x][y]){
                pp p={x,y};
                ans[p]=0;
            }
            else{
                ans[make_pair(x,y)]=1;
            }
        }
    }
    return ans;
}
void bfs(pp node){
    deque<pp>dq;
    dq.push_front(node);
    dis[node.first][node.second]=0;
    while(!dq.empty()){
        pp temp=dq.front();
        dq.pop_front();
        for(auto i:neighbour(temp)){
            pp neig=i.first;
            int weight=i.second;
            if(dis[neig.first][neig.second]>dis[temp.first][temp.second]+weight){
                dis[neig.first][neig.second]=dis[temp.first][temp.second]+weight;
                if(weight==0){
                    dq.push_front(neig);
                }
                else{
                    dq.push_back(neig);
                }
            }
        }
    }
    cout<<dis[n][m]<<endl;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    g.resize(n+1,vector<int>(m+1,0));
    dis.assign(n+1,vector<int>(m+1,1e9));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    bfs(make_pair(1,1));

    return 0;
}