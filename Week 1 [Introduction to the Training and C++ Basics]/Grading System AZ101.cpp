#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int mid,end,make;
	cin>>mid>>end>>make;
	if(mid==-1 || end==-1){
		cout<<"F"<<endl;
	}
	else if(mid+end>=80){
		cout<<"A"<<endl;
	}
	else if(mid+end<80 && mid+end>=65){
		cout<<"B"<<endl;
	}
	else if(mid+end<65 && mid+end>=50){
		cout<<"C"<<endl;
	}
	else if(mid+end<50 && mid+end>=30){
		if(make>=50){
			cout<<"C"<<endl;
		}
		else{
			cout<<"D"<<endl;
		}
		
	}
	else{
		cout<<"F"<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}