#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
void solve(lli x){
    int cnt=0;
    for(int i=1;i*i<=x;i++){

        if(x%i==0){
            cnt++;
            if(i*i!=x){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;

        solve(n);
    }
}