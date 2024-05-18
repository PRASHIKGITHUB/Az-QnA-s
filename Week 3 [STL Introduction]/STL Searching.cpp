#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using lli=long long int;
void solve(){
   int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    while(q--){
        string s;
        cin>>s;
        if(s=="1"){
            int x;
            cin>>x;
            if(lower_bound(arr,arr+n,x)!=(arr+n)){
                cout<<*(lower_bound(arr,arr+n,x))<<" ";
            }
            else{
                cout<<"-1"<<endl;
            }
            
        }
        else if(s=="2"){
            int x;
            cin>>x;
            if(upper_bound(arr,arr+n,x)!=(arr+n)){
                cout<<*(upper_bound(arr,arr+n,x))<<" ";
            }
            else{
                cout<<"-1"<<endl;
            }
            
        }
        else if(s=="3"){
            int x;
            cin>>x;
            cout<<upper_bound(arr,arr+n,x)-arr<<" ";
        }
        else if(s=="4"){
            int x;
            cin>>x;
            cout<<lower_bound(arr,arr+n,x)-arr<<" ";
        }
    }
    cout<<endl;
  
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