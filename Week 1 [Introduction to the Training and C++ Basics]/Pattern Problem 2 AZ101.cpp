#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int x,y,z;
	cin>>x>>y>>z;
	for(int i=0;i<x*(z+1)+1;i++){
		for(int j=0;j<y*(z+1)+1;j++){
			if(j%(z+1)==0 || i%(z+1)==0){
				cout<<"*";
			}
			else if(i%(2*(z+1))==j%(2*(z+1))){
				cout<<"\\";
			}
			else if(i%(2*(z+1))+j%(2*(z+1))==2*(z+1)){

				cout<<"/";
            }
            else{
            	cout<<".";
            }
		}
		cout<<endl;
	}
	cout<<endl;
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