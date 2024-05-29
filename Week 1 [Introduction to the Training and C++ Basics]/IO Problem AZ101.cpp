#include<bits/stdc++.h>
using namespace std;
void solve(){
	string s;
	cin>>s;
	
	string s1;
	cin>>s1;
	
	long long x=stoll(s);
	
	long long y=stoll(s1);
	
	int count=0;
	for(int i=0;s1[i]!='.';i++){
		count++;
	}
	s1=s1.substr(count+1);
	
	long long z=stoll(s1);
	cout<<(z+x)<<"."<<(y+x)<<endl;


}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin>>t;
  string temp;
  getline(cin,temp);
  while(t--)
  {
    solve();
  }
}