#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const int mod=1e9+7;

void solve(){
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<ll>> a(n+2,vector<ll> (m+2,0));
    ll maxi=-1e8;
    int cnt=0;

    int x1,y1,x2,y2;
    ll c;
    while(q--){
        cin>>x1>>y1>>x2>>y2>>c;

        a[x1][y1] += c;
        a[x1][y2+1] -= c*(y2+1<=m);
        a[x2+1][y1] -= c*(x2+1<=n);
        a[x2+1][y2+1] += c*(x2+1<=n && y2+1<=m);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];

            if(maxi<a[i][j]){
                cnt=1;
                maxi=a[i][j];
            }
            else if(maxi==a[i][j]){
                cnt++; 
            }
        }
    }

    cout<<maxi<<" "<<cnt;
}

int main(){
    IOS;

    int _t=1; 
    // cin>>_t;
    // initiate();

    for(int i=1;i<=_t;i++){
        solve();
    }

    return 0;
}