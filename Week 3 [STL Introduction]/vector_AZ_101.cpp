#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
void solve(int q){
    vector<int>v;
    while(q--){
        string s;
        cin>>s;
        // cout<<"before query"<<endl;
        if(s[0]=='a'){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        
        else if(s[0]=='r'){
            if(!v.empty())
            v.pop_back();
        }
        
        else if(s[0]=='p'){
            int index;
            cin>>index;
            if(index>=v.size()){
                cout<<"0"<<endl;
            }
            else{
                cout<<v[index]<<endl;
            }
        }
        else if(s[0]=='c'){
            v.clear();
        }

        // cout<<"after query "<<v.size()<<endl;
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
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
        string temp;
        getline(cin,temp);
        solve(q);
    }
}