#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int prefix[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prefix[i]=arr[i];
        if(i){
            prefix[i]+=prefix[i-1];
        }
    }
    map<int,int>mp;
    mp[0]++;
    int ans=0;
    for(int r=0;r<n;r++){
        ans+=mp[prefix[r]-k];
        mp[prefix[r]]++;
    }
    cout<<ans<<endl;
    return 0;
}