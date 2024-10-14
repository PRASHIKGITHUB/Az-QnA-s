#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>ump;
    ump[0]++;
    int ans=0;
    int presum=0;
    for(int i=0;i<n;i++){
        presum+=arr[i];
        if(ump.find(presum-k)!=ump.end()){
            ans+=ump[presum-k];
        }
        ump[presum]++;
    }
    cout<<ans<<endl;
    return 0;
}