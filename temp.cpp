#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
using pp=pair<lli,lli>;
lli m = 1e9 + 7;
int n;
int arr[1001];
int dp[1001];
lli freq[1001];
int rec(int l){//rec(l) --> longest increasing subseq ending at index l
    if(l<0){//base case
        return 0;
    }

    if(dp[l]!=-1){
        return dp[l];
    }
    int ans=1;
    for(int i=l-1;i>=0;i--){
        if(arr[i]<arr[l]){
            freq[rec(i)+1]++;
            ans=max(rec(i)+1,ans);
        }
    }

    return dp[l]=ans;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int final_max_len=0;
    for(int i=0;i<n;i++){
        final_max_len=max(final_max_len,rec(i));
    }
    cout<<freq[final_max_len]%m<<endl;
    for(int i=1;i<=n;i++){
        cout<<freq[i]<<" ";
    }
}
// 1
// 5
// 1 2 2 3 6
// 5
// 1 3 5 4 7
// 6
// 1 1 1 1 1 1
// 4
// 3 1 1 2

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        memset(freq,0,sizeof(freq));
        solve();
    }
    return 0;
}



