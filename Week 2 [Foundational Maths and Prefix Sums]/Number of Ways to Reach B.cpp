#include<bits/stdc++.h>
using namespace std;
using lli=long long int;

lli fastExpo(lli a,lli b,lli m){
    lli ans=1;
    while(b!=0){
        if(b%2==1){
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b/=2;
    }
    return ans;
}
void solve(lli* arr){
    int n,m;
    cin>>n>>m;
    lli M=1e9+7;
    lli first=arr[n+m];//first=(n+m)!%M
    lli second=fastExpo(arr[n],M-2,M);//second=(n!%M)^M-2 % M
    lli third=fastExpo(arr[m],M-2,M);// third=(m!%M)^M-2 % M
    lli ans=(first*((second*third)%M))%M;
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    //pre-computing factorial mod 
    lli arr[200001];//since m+n can go upto 200000
    lli mod=1e9+7;
    arr[1]=1;
    for(lli i=2;i<=200000;i++){
        arr[i]=(i%mod*arr[i-1]%mod)%mod;

    }
    // for(int i=1;i<=200000;i++){
    //     cout<<arr[i]<<" ";
    // }
    while(t--){
        solve(arr);
    }
    return 0;
}