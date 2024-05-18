#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve(int k)
{
    priority_queue<int>pq;
    while(k--){
        string s;
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            pq.push(x);
        }
        else if(s=="remove"){
            if(!pq.empty()){
                pq.pop();
            }
        }
        else if(s=="print"){
            if(!pq.empty()){
                cout<<pq.top()<<endl;
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