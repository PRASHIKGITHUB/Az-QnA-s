#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    multiset<int>ms;
    while(n--){
        int temp;
        cin>>temp;
        auto up=ms.upper_bound(temp);
        if(up==ms.end()){
            ms.insert(temp);
        }
        else{
            ms.erase(up);
            ms.insert(temp);
        }
    }
    cout<<ms.size()<<endl;
    
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