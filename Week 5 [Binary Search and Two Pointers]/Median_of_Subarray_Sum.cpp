#include<bits/stdc++.h>
using namespace std;


#define int long long
vector<int>arr;
int n;
bool check(int k){
    int cnt=0;
    int head=-1,tail=0;int sum=0;
    while(tail<n){
        
        while(head+1<n && (sum+arr[head+1])<=k){

            head++;
            sum+=arr[head];
        }
        cnt+=(head-tail+1);//counts the number of subarray starting with head and sum <=k
        if(tail>head){
            tail++;
            head=tail-1;
        }
        else{
            sum-=arr[tail];
            tail++;
        }
    }
    int temp=((n*(n+1)/2)+1)/2;//if the number of elements in the final array is odd that's why this +1 is comming
    if (cnt>=temp){
        return 1;
    }
    else{
        return 0;
    }
}
void solve(){
    cin>>n;
    arr.resize(n);
    int high=0;
    // Initialize 'low' as a large value
    int low=1e18;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        high+=arr[i];
        // Update 'low' as the minimum value present in the array
        low=min(low,arr[i]);
    }
    
    int ans=-1;
    while(low<=high){
        int mid=(high+low)/2;
        if(check(mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;

}
signed main(){
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
