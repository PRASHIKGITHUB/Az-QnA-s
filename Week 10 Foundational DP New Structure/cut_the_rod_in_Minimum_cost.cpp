#include<bits/stdc++.h>
using namespace std;
int n;//n is the length of rod 
int arr[1001];
// 0 x1 x2 ..... xn-1 xn
int rec(int l,int r){
    if(l+1==r){
        return 0;
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=k;i++){
        cin>>arr[i];
    }

    int ans=rec(0,n);
    cout<<ans<<endl;
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