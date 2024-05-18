#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;;
    cin>>n;
    long long int m=1e9+7;
    long long ans=1;
    for(int i=0;i<n;i++){
        long long int temp;
        cin>>temp;
        ans=((ans%m)*(temp%m))%m;
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}