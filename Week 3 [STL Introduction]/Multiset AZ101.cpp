#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve(int k)
{
    multiset<int>ms;
    while(k--){
        string s;
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            ms.insert(x);
        }
        else if(s=="erase"){
            int x;
            cin>>x;
            if(ms.find(x)!=ms.end()){
                ms.erase(ms.find(x));
            }
        }
        else if(s=="eraseall"){
            int x;
            cin>>x;
             if(ms.find(x)!=ms.end()){
                ms.erase(x);
            }
        }
        else if(s=="find"){
            int x;
            cin>>x;
            if(ms.find(x)!=ms.end()){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else if(s=="count"){
            int x;
            cin>>x;
            cout<<ms.count(x)<<endl;
        }
        else if(s=="print"){
            for(auto i:ms){
                cout<<i<<" ";
            }
            cout<<endl;
        }

        else if(s=="empty"){
            ms.clear();
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