#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
void solve(lli &n,lli &k){
    priority_queue<lli>pq;
    for(int i=0;i<n;i++){
        lli temp;
        cin>>temp;
        pq.push(temp);
    }
    lli ans=0;
    while(k--){
        ans=ans+pq.top();
        lli temp=pq.top()/2;
        pq.pop();
        pq.push(temp);
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
        lli n,k;
        cin>>n>>k;
        solve(n,k);
    }
    return 0;
}