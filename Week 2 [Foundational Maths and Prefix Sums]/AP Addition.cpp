#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
lli m=1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    lli arr[n+2];
    lli a[n+2];
    lli b[n+2];
    for(int i=0;i<=n+1;i++){
        arr[i]=0;
        a[i]=0;
        b[i]=0;
    }

    while(q--){
        lli k,d,l,r;
        cin>>k>>d>>l>>r;
        lli t1=k-l*d;
        a[l]+=t1;
        // a[l]=(a[l]+t1);
        a[r+1]-=t1;
        b[l]+=d;
        b[r+1]-=d;
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
        arr[i]=(a[i]%m+(i%m*b[i]%m)%m+m)%m;
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}