#include<bits/stdc++.h>
using namespace std;
void solve(int n){
    queue<int> q;
    while(n--){
        string s;
        cin>>s;
        if(s[0]=='a'){
            int digit;
            cin>>digit;
            q.push(digit);
        }
        else if(s[0]=='r'){
            if(!q.empty()){
                q.pop();
            }
        }
        else if(s[0]=='p'){
            if(!q.empty()){
                cout<<q.front()<<endl;
            }
            else{
                cout<<"0"<<endl;
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