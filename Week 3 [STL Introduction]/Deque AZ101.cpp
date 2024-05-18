#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve(int q)
{
    deque<int>dq;
    while(q--){
        string s;
        cin>>s;
        
        if(s=="insertback"){
            int x;
            cin>>x;
            dq.push_back(x);
        }
        else if(s=="eraseback"){
            if(!dq.empty()){
                dq.pop_back();
            }
        }
        else if(s=="insertfront"){
            int x;
            cin>>x;
            dq.push_front(x);
        }
        else if(s=="erasefront"){
            if(!dq.empty()){
                dq.pop_front();
            }
        }
        else if(s=="printfront"){
            if(!dq.empty()){
                cout<<dq.front()<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
        else if(s=="printback"){
            if(!dq.empty()){
                cout<<dq.back()<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
        else if(s=="print"){
            int x;
            cin>>x;
            if(x<=(int)dq.size()-1){
                cout<<dq[x]<<endl;
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
        cin>>q;
        solve(q);
    }
    return 0;
}