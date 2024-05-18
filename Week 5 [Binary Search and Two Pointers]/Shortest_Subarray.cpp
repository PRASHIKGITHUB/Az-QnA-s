#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
int mp[100100];
void solve(){
    int n;
    cin>>n;
    map<int,int>mp1;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp1[arr[i]]++;
    }
    int distinct=mp1.size();
    int tail=0;
    int head=-1;
    int ans=INT_MAX;
    int cnt=0;
    // map<int,int>mp;
    while(tail<n){
        while(head+1<n && (cnt<distinct)){
            head++;
            if(mp[arr[head]]==0){
                cnt++;
            }
            mp[arr[head]]++;
        }
        if(cnt==distinct){
            ans=min(ans,head-tail+1);
        }
        
        
        if(head<tail){
            tail++;
            head=tail-1;
        }
        else{
            if(mp[arr[tail]]==1){
                cnt--;
            }
            mp[arr[tail]]--;
            tail++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    for(int i=0;i<=100000;i++){
        mp[i]=0;
    }
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