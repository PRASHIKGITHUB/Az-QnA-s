#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m,p;
	cin>>n>>m>>p;
	long long mat1[n][m];
	long long mat2[m][p];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat1[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			cin>>mat2[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<p;j++){
			int sum=0;
			for(int k=0;k<m;k++){
				sum=sum+mat1[i][k]*mat2[k][j];
			}
			cout<<sum<<" ";


		}
		cout<<endl;
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