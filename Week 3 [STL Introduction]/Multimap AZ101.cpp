#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
void solve(){
    int q;
    cin>>q;
    multimap<string,int>mm;
    while(q--){
        string s;
        cin>>s;
        if(s=="add"){
            string s;
            cin>>s;
            int y;
            cin>>y;
            mm.insert({s,y});
        }
        else if(s=="erase"){
            string x;
            cin>>x;
            
            if(mm.find(x)!=mm.end()){
                mm.erase(mm.find(x));
            }
        }
        else if(s=="eraseall"){
            string x;
            cin>>x;
            if(mm.find(x)!=mm.end()){
                mm.erase(x);
            }
            
        }
        else if(s=="print"){
            string x;
            cin>>x;
            if(mm.find(x)!=mm.end()){
                cout<<mm.find(x)->second<<endl;
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
        solve();
    }
    return 0;
}