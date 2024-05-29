#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;

	
	long long sumA=0,sumB=0,sumC=0;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		sumA+=temp;
	}
	for(int i=0;i<n-1;i++){
		int temp;
		cin>>temp;
		sumB+=temp;
	}
	for(int i=0;i<n-2;i++){
		int temp;
		cin>>temp;
		sumC+=temp;
	}
	cout<<sumA-sumB<<" "<<sumB-sumC<<endl;
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