#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
using pp=pair<lli,lli>;
lli m = 1e9 + 7;
int mod;
lli power(lli a, lli b) {
  lli ans = 1;
  while (b) {
    if (b % 2) {
      ans = ((ans % mod) * (a % mod)) % mod;
    }
    a = ((a % mod) * (a % mod)) % mod;
    b /= 2;
  }
  return ans;
}
lli compute(lli a,lli b,char op){
    if(op=='+'){
        return (a%mod+b%mod)%mod;
    }
    else if(op=='-'){
        return (a%mod-b%mod+mod)%mod;
    }
    else if(op=='*'){
        return (a%mod*b%mod)%mod;
    }
    else{
        return (a*power(b,mod-2))%mod;
    }
}
void solve(){
    string temp;
    cin>>temp;
    lli a=stoi(temp.substr(1));
    cin>>temp;
    char op1=temp[0];
    cin>>temp;
    lli b=stoi(temp);
    cin>>temp;
    char op2=temp[0];
    cin>>temp;
    lli c=stoi(temp.substr(0,temp.length()-1));
    cin>>temp;
    cin>>temp;
    mod=stoi(temp);
    lli ans=0;
    if(op1=='+' || op1=='-'){
        if(op2=='-' || op2=='+'){
            ans=compute(a,b,op1);
            ans=compute(ans,c,op2);
        }
        else{
            ans=compute(b,c,op2);
            ans=compute(a,ans,op1);
        }
    }
    else{
        ans=compute(a,b,op1);
        ans=compute(ans,c,op2);
    }
    cout<<ans<<endl;

    
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