// Enter your code below 
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;

void solve(){
 
  int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    lli ans=0;
    
    for(int i=1;i<n;i++){
        ans+=(upper_bound(arr,arr+i,x-arr[i])-arr);  
    }
    
    cout<<(2*ans)<<endl;
    //ordered pairs
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        
    }
    
    return 0;
}