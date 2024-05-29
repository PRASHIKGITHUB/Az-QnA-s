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
    long long ans=0;
    for(int j=0;j<n-1;j++){
        if(arr[j+1]<arr[j]){
            ans=ans+arr[j]-arr[j+1];
            arr[j+1]=arr[j];
        }
    }
    cout<<ans<<endl;
    

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