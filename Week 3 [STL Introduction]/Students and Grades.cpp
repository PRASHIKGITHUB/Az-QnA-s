#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
void solve(){
    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        mp[temp]++;
    }
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        if(mp[temp]!=0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
            mp[temp]++;
        }
    }
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