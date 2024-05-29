#include<bits/stdc++.h>
using namespace std;
void solve()
{
	
	double x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
    double euclid=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double man=abs(x1-x2)+abs(y1-y2);
	cout<<fixed<<setprecision(7)<<euclid<<" "<<fixed<<setprecision(7)<<man<<endl;

	
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