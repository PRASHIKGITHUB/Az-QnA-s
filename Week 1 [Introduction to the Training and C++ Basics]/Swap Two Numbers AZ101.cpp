#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b;
    cin>>a>>b;
    
    int temp;
    temp=a;
    a=b;
    b=temp;
    cout<<a<<" "<<b<<endl;
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
     solve();   
    }
    
    return 0;
}