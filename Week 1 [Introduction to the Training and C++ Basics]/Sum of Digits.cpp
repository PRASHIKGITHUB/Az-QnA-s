#include<bits/stdc++.h>
using namespace std;
void solve()
{
  string s;
  cin>>s;
  long long ans=0;
  for(int i=0;i<s.length();i++){
  		int digit=s[i]-'0';
  		ans=ans+digit;
  }
  cout<<ans<<endl;

}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}