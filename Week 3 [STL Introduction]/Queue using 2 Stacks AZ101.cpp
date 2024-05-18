#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
void transfer(stack<int>&s1,stack<int>&s2){
    while(!s1.empty()){
        int back=s1.top();
        s1.pop();
        s2.push(back);
    }
}
void solve(int q){
    stack<int>s1;
    stack<int>s2;
    while(q--){
        string s;
        cin>>s;
        if(s=="push"){
            int ele;
            cin>>ele;
            s1.push(ele);
        }
        else if(s=="pop"){
            if(s2.empty()){
                transfer(s1,s2);
            }
            if(!s2.empty()){
                cout<<s2.top()<<endl;
                s2.pop();
            }
        }
        else if(s=="front"){
            if(s2.empty()){
                transfer(s1,s2);
            }
            if(!s2.empty()){
                cout<<s2.top()<<endl;
            }
        }
    }
}
int main(){
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>q;
        solve(q);
    }
    return 0;
}