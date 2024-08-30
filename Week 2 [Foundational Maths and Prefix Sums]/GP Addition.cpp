#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
lli m=1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli n,q,k;
    cin>>n>>q>>k;
    lli arr[n+2];
    for(int i=0;i<=n+1;i++){
        arr[i]=0;
    }

    lli powk[n+1];
    powk[0]=1;
    powk[1]=k;
    for(int i=2;i<=n;i++){
        powk[i]=(powk[i-1]%m*k)%m;
    }

    while(q--){
        int a,l,r;
        cin>>a>>l>>r;
        arr[l]+=a;
        arr[r+1]-=a*powk[r-l+1];
    }

    for(int i=1;i<=n;i++){
        arr[i]=(arr[i]%m+(arr[i-1]%m*k%m)%m+m)%m;
        cout<<arr[i]<<" ";
    }



    return 0;
}