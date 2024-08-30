#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
void solve(int x){
    if(x==1){
        cout<<"NO"<<endl;
        return;
    }
    int i=2;
    while(i*i<=x){
        if(x%i==0){
            cout<<"NO"<<endl;
            return;
        }
        i++;
    }
    cout<<"YES"<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        solve(n);
    }
}