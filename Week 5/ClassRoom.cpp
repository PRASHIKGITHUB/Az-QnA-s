// Solution 1
#include <bits/stdc++.h>
using lli = long long;
using namespace std;
lli m=1e9+7;
int k;
int n;
bool check(int x,int* arr){
    int studeployed=1;
    int begin=arr[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(arr[i]>=x+begin){
            cnt++;
            begin=arr[i];
        }
        
    }
    if(cnt>=k){
        return 1;
    }
    else {
        return 0;
    }
    
}
void solve(){

    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    // cout<<"sorted array"<<endl;
    // for(auto i:arr){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    int low=0;
    int high=arr[n-1]-arr[0];
    
    // cout<<"max difference "<<high<<endl;
    
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        // cout<<mid<<" mid"<<endl;
        if(check(mid,arr)){
            low=mid+1;
            ans=mid;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  
}