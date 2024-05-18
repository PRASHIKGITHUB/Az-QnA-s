#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve()
{
   int n,m;
    cin>>n>>m;
    vector<int>v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int i=0;
    int ans=0;
    while(m>=v[i] && i<n){
        ans++;
        m=m-v[i];
        i++;
    }
    cout<<ans<<endl;
   
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}