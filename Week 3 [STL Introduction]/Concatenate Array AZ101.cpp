#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
void solve(){
  int n;
    cin>>n;
    set<int>s;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        s.insert(temp);
    }
    cout<<s.size()<<endl;
  
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