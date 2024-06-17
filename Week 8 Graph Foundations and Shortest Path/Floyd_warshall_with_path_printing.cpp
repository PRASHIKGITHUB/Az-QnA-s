#include<bits/stdc++.h>
using namespace std;
int dis[401][401];
int path[401][401];
void printPath(int i,int j){
    if(i!=j){
        printPath(i,path[i][j]);
    }
    cout<<j<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j)dis[i][j]=1e9;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=min(dis[a][b],c);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            path[i][j]=i;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){

                    dis[i][j]=dis[i][k]+dis[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }
    return 0;
}