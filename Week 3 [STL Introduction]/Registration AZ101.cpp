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
    unordered_map<string,int>M;
    while(q--){
        string s;
        cin>>s;
        M[s]++;
        if(M[s]==1){
            cout<<"OK"<<endl;
        }
        else{
            cout<<s<<M[s]-1<<endl;
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