#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using ld=long double;
bool check(ld mid,int k,int*a,int*b,int n){
    priority_queue<ld,vector<ld>,greater<ld>>pq;
    for(int i=0;i<n;i++){
        pq.push((ld)a[i]-mid*(ld)b[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    ld sum=0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    return sum>=0;
}
void solve(){
    ld ans=0;
    ld low=0;
    ld high=0;
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        high+=a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    
    
    while(abs(low-high)>1e-9){
        ld mid=(high+low)/2;
        if(check(mid,k,a,b,n)){
            ans=mid;
            low=mid;
        }
        else{
            high=mid;
        }
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
    
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
}