#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
void solve(int n){
    vector<int>v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    auto i=unique(v.begin(),v.end());
    v.erase(i,v.end());
    
    if(v.size()==1){
        cout<<"-1"<<endl;
        return;
    }
    else{
        cout<<v[1]<<endl;
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        solve(n);
    }
    return 0;
}