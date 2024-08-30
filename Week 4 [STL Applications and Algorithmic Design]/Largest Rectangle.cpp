#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
using pp=pair<lli,lli>;
lli m = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int>s1;
    stack<int>s2;
    int nse_right[n];
    int nse_left[n];
    for(int i=0;i<n;i++){
        while(!s1.empty() && arr[s1.top()]>=arr[i]){
            s1.pop();
        }
        if(s1.empty()){
            nse_left[i]=-1;
        }
        else{
            nse_left[i]=s1.top();
        }
        s1.push(i);
    }

    for(int i=n-1;i>=0;i--){
        while(!s2.empty() && arr[s2.top()]>=arr[i]){
            s2.pop();
        }
        if(s2.empty()){
            nse_right[i]=n;
        }
        else{
            nse_right[i]=s2.top();
        }
        s2.push(i);
    }

    lli ans=0;
    for(int i=0;i<n;i++){
        lli area=1LL*arr[i]*(nse_right[i]-nse_left[i]-1);
        ans=max(ans,area);
        
    }
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