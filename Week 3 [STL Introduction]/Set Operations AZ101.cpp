#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
void solve(){
  int n,m;
     cin>>n>>m;
    set<int>unio;
    set<int>a,b;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.insert(temp);
        unio.insert(temp);
    }
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        b.insert(temp);
        unio.insert(temp);
    }
    // cout<<"printing union"<<endl;
    for(auto i:unio){
        cout<<i<<" ";
    }
    cout<<endl;
    
    //intersection;
    // set<int>inter;
    for(auto i:a){
        if(b.find(i)!=b.end()){
            cout<<i<<" ";
        }
    }
    cout<<endl;

    for(auto i:a){
        if(b.find(i)!=b.end()){
            continue;
        }
        else{
            cout<<i<<" ";
        }
    }
    cout<<endl;
    
    
    
  
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