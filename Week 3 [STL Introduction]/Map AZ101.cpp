#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve(int k)
{
    map<string,int>mp;
    while(k--){
        string s;
        cin>>s;
        if(s=="add"){
            string x;
            cin>>x;
            int y;
            cin>>y;
            mp[x]=y;
            
        }
        else if(s=="erase"){
            string x;
            cin>>x;
            if(mp.find(x)!=mp.end()){
                mp.erase(x);
            }
        }
        else if(s=="print"){
            string x;
            cin>>x;
            if(mp.find(x)!=mp.end()){
                cout<<mp[x]<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
            
        }
    }
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
        int q;
        cin >> q;
        solve(q);
    }
    return 0;
}