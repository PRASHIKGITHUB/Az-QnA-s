#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
void solve() {
    int n;
    cin >> n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=arr[0];
    for(int i=1;i<n;i++){
        ans=gcd(ans,arr[i]);
    }
    if(ans!=1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}