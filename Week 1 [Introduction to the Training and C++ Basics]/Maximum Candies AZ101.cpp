#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,b;
    cin>>n>>b;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    int count=0;
    
    for(int i=0;i<n;i++){
    	b=b-arr[i];
    	if(b>=0){
    		
    		count++;
    	}
    	else{
    		break;
    	}
    }

    cout<<count<<endl;
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}