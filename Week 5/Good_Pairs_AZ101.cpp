#include <bits/stdc++.h>
using lli = long long;
using namespace std;
lli m=1e9+7;
lli n;


void solve(){

    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int ab[n];
    // cout<<"ab array"<<endl;
    for(int i=0;i<n;i++){
        ab[i]=a[i]-b[i];
        // cout<<ab[i]<<" ";
    }
    // cout<<endl;

    lli finalans=0;
    sort(ab,ab+n);
    // cout<<"sorted ab"<<endl;
    // for(auto i:ab){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<n-1;i++){
        int num=ab[i];
        int low=i+1;
        int high=n-1;
        int ans=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if((1LL*(ab[mid]+num)>0)){
                high=mid-1;
                ans=mid;
                // cout<<"possible pair"<<num<<" "<<ab[mid]<<endl;
            }
            else{
                low=mid+1;
            }
        }
        // cout<<"index"<<ans<<endl;
        if(ans!=-1){
            finalans+=n-ans;
        }
        
    }
    cout<<finalans<<endl;
    
    
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