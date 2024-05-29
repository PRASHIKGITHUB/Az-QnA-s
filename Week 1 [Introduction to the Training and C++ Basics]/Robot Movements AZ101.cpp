#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,r,c,x,y;
	cin>>n>>r>>c>>x>>y;
	bool visited[r+1][c+1]={0};
    //1 based indexing
	visited[x][y]=1;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		char direction=s[i];
		//down
		if(direction=='S'){
			for(int k=x+1;k<=r;k++){
				if(visited[k][y]==1){
					continue;
				}
				else{
					visited[k][y]=1;
					x=k;
					break;
				}
			}
		}
		//up
		else if(direction=='N'){
			for(int k=x-1;k>=1;k--){
				if(visited[k][y]==1){
					continue;
				}
				else{
					visited[k][y]=1;
					x=k;
					break;
				}
			}
		}
		//right
		else if(direction=='E'){
			for(int k=y+1;k<=c;k++){
				if(visited[x][k]==1){
					continue;
				}
				else{
					visited[x][k]=1;
					y=k;
					break;
				}
			}
		}
		//left
		else{
			for(int k=y-1;y>=1;k--){
				if(visited[x][k]==1){
					continue;
				}
				else{
					visited[x][k]=1;
					y=k;
					break;
				}
			}
		}
	}
	cout<<x<<" "<<y<<endl;

	//How at the end visited arry will look like
	

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