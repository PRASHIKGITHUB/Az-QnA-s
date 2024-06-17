#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
lli dis[501][501];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)dis[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++){
        lli a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=min(c,dis[a][b]);
        dis[b][a]=min(c,dis[b][a]);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dis[a][b]!=1e18){
            cout<<dis[a][b]<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
        
    }
    return 0;
}