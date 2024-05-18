#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
bool comp(pair<string,int>&a,pair<string,int>&b){
    return a.second<b.second;
}
void solve(){
  int n;
    cin>>n;
    vector<pair<string,int>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),comp);
    for(auto i:v){
        cout<<i.first<<" "<<i.second<<endl;
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