#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

void solve(){
    set<int> arr[26];
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        arr[s[i]-'a'].insert(i);
    }
    int q;
    cin>>q;
    while(q--){
        int first;
        cin>>first;
        if(first==1){
            char c;
            int idx;
            cin>>idx>>c;
            arr[s[idx-1]-'a'].erase(idx-1);
            arr[c-'a'].insert(idx-1);
            s[idx-1]=c;
        }
        else{
            int ans=0;
            int l,r;
            cin>>l>>r;
            for(int i=0;i<26;i++){
                auto it=arr[i].lower_bound(l-1);
                if(it==arr[i].end()){
                    continue;
                }
                if(*it<=(r-1) && *it>=(l-1)){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return;
}
int main()
{
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