#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;


void solve(){
    priority_queue<lli>pq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        pq.push(-temp);
    }
    lli ans=0;
    while(pq.size()>1){
        lli a=-pq.top();
        pq.pop();
        lli b=-pq.top();
        pq.pop();
        ans+=(a+b);
        pq.push(-(a+b));
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