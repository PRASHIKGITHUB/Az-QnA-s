#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
void solve(){
    int n;
    lli target;
    lli absolute=INT64_MAX;
    cin>>n>>target;
    lli arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int j=0;j<n;j++){
        int i=0;int k=n-1;
        while(i<j && k>j){
            lli sum=arr[i]+arr[j]+arr[k];
            absolute=min(absolute,abs(sum-target));
            if(sum==target){
                cout<<"0"<<endl;
                return;
            }
            else if(sum>target){
                k--;
            }
            else{
                i++;
            }
        }
    }
    cout<<absolute<<endl;
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