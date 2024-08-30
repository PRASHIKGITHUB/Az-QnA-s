#include<bits/stdc++.h>
using namespace std;
using lli=long long int;

void solve(int* pre,int* arr){
    int l,r;
    cin>>l>>r;
    long long ans;
    long long m=1e9+7;
    ans=(pre[r]-pre[l]+arr[l]%m)%m;
    
    ans=(ans%m+m)%m;
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    // cout<<"printing the arry elements"<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    long long m=1e9+7;

    int pre[n+1];
    pre[1]=arr[1];
    for(int i=2;i<=n;i++){
        int temp;
        pre[i]=(pre[i-1]%m+arr[i]%m)%m;
        // pre[i]=(temp%m+m)%m;
    }
    // cout<<"printing the prefix array"<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<pre[i]<<" ";
    // }
    while(q--){
        solve(pre,arr);
    }
    return 0;
}