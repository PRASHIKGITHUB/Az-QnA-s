#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
lli m = 1e9 + 7;
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    // cout<<"n:"<<n<<"m:"<<m<<"q:"<<q<<endl;
    lli a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int freq[n+1];
    for(int i=0;i<=n;i++){
        freq[i]=0;
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        freq[l]++;
        if(r<=n-1){
            freq[r+1]--;
        }
    }
    
    //this will store frequencies of all the elements added in s
    for(int i=1;i<=n;i++){
        freq[i]=freq[i-1]+freq[i];
    }

    vector<pair<lli,lli>>v;//number,frequency pair
    for(int i=1;i<=n;i++){
        if(freq[i]){
            v.push_back({a[i],freq[i]});
        } 
    }

    sort(v.begin(),v.end());
    vector<lli>frequencies;
    for(auto i:v){
        frequencies.push_back(i.second);
    }
    for(int i=1;i<v.size();i++){
        frequencies[i]=frequencies[i-1]+frequencies[i];
    }
    
    //q queries
    for(int i=0;i<q;i++){
        lli ki;
        cin>>ki;
        auto it=lower_bound(frequencies.begin(),frequencies.end(),ki);
        if(it!=frequencies.end()){
            int index;
            index=it-frequencies.begin();
            cout<<v[index].first<<" ";
        }
        else{
            cout<<"-1"<<" ";
        }
        
    }
    cout<<endl;
    
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    // cout<<t<<"val of t"<<endl;
    while (t--) {
        solve();
    }
    return 0;
}