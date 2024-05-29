#include<bits/stdc++.h>
using namespace std;
void solve()
{
	
	int n;

	cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int count=1;
        int diff=arr[i]-arr[i+1];
        for(int j=i+1;j<n-1;j++){
            if(arr[j]-arr[j+1]==diff){
                count++;
            }
            else{
                i=j-1;
                break;
            }
        }
        ans=max(ans,count);
    }
	cout<<ans+1<<endl;
	
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