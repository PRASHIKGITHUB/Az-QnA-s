#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
lli gcd(lli a,lli b){
    while(b!=0){
        lli temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
void solve(){
    lli a,b,c;
    cin>>a>>b>>c;
    lli aAb=gcd(a,b);
    
    if(c%aAb==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}