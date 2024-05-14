// Solution 1
#include <bits/stdc++.h>
using lli = long long;
using namespace std;
lli m=1e9+7;
int n;

bool check(int x,int *arr){
    if(x<=arr[n-1]){
        return 1;
    }
    else{
        return 0;
    }
}
void binary(int* arr){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(arr[mid],arr)){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}
    
void solve(){

    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    binary(arr);
    
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